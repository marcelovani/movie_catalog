<?php
/**
 * @file
 */

define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/profiles/movie_catalog/modules/contrib/endpoint/includes/router.inc';

$routes = array(
  'api/imdb/movie/add' => array(
    'GET' => array(
      'callback' => 'my_module_foo_list',
      'anonymous'  => TRUE,
    ),
    'POST' => array(
      'callback' => 'movie_catalog_add_movie',
      'anonymous'  => TRUE,
    ),
  ),
  'api/v1/foo/(\w+)' => array(
    'GET' => array(
      'callback' => 'my_module_foo_get',
      'anonymous'  => TRUE,
    ),
    'POST' => array(
      'include' => DRUPAL_ROOT . '/sites/all/modules/custom/another_module/includes/some_callback.inc',
      'callback' => 'my_module_foo_update',
    ),
  ),
);

endpoint_route(array(
  //'debug' => TRUE,
  'routes' => $routes,
  //'authorize callback' => 'my_module_callback_authorize',
//  'error callback' => 'my_module_callback_error',
    'before execute callback' => 'movie_catalog_bootstrap',
));

function movie_catalog_bootstrap() {
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
}

function my_module_foo_list() {
  // ...

  $node = node_load(1);
  return array('node' => $node);
}

function movie_catalog_add_movie() {
  $movie_data = endpoint_request_data();

  if (isset($movie_data->imdb_id)) {
    $imdb_id = check_plain($movie_data->imdb_id);
  }
  else {
    watchdog('error', 'Invalid data passed to end point', array(), WATCHDOG_ALERT);
  }

  // Check if entry already exists.
  $result = db_select('field_data_field_imdb_id', 'i')
    ->fields('i', array('entity_id'))
    ->condition('field_imdb_id_value', $imdb_id, '=')
    ->condition('language', LANGUAGE_NONE, '=')
    ->execute()
    ->fetchAssoc();

  if ($result !== FALSE) {
    // Update node.
    $node = node_load($result['entity_id']);
  } else {
    // Create new node.
    $node = new stdClass();
    $node->type = 'movies';
    node_object_prepare($node);
  }

  // Populate node values.
  if (isset($movie_data->title)) {
    $node->title = check_plain($movie_data->title);
  }
  $node->language = LANGUAGE_NONE;
  if (isset($movie_data->plot)) {
    $node->body[$node->language][0] = movie_catalog_prepare_field_body($movie_data->plot, 'filtered_html');
  }
  $node->field_imdb_id[$node->language][0]['value'] = $imdb_id;
  if (isset($movie_data->rating)) {
    $node->field_rating[$node->language][0]['value'] = check_plain($movie_data->rating);
  }
  // Genres (Autocomplete field).
  if (isset($movie_data->genres)) {
    $node->field_genres[$node->language] = movie_catalog_prepare_term_autocomplete('genres', $movie_data->genres);
  }
  if (isset($movie_data->cover)) {
    $node->field_cover_url[$node->language][0]['value'] = check_plain($movie_data->cover);
  }
  //$node->field_cover[$node->language] = movie_catalog_prepare_remote_image($movie_data->cover);
  $node->status = 1;
  $node->promote = 0;
  $node->comment = 0;

  // Term reference (taxonomy) field
  //$node->field_genres[$node->language][]['tid'] = $form_state['values']['a taxonomy term id'];

  // Entity reference field
  /*
  $node->field_customer_nid[$node->language][] = array(
    'target_id' => $form_state['values']['entity id'],
    'target_type' => 'node',
  );
  */
  // 'node' is default,

  node_submit($node);
  node_save($node);

  return array('node' => $node);
}

function my_module_foo_get($id) {
  // ...
  return array('id' => $id);
}

function my_module_foo_update() {
  $data = endpoint_request_data();
  // ...
}

function my_module_callback_authorize() {
  return TRUE;
  // ...
}

/**
 * Helper to prepare value for body.
 *
 * @param $value
 * @param $format_id
 * @return array
 */
function movie_catalog_prepare_field_body($value, $format_id) {
  // Clean array.
  if (is_array($value)) {
    foreach ($value as $key => $item) {
      $value[$key] = '<p>' . check_markup($item, $format_id) . '</p>';
    }
    $value = implode("\n", $value);
  } else {
    $value = check_markup($value, $format_id);
  }

  return array(
    'value' => $value,
    'summary' => text_summary($value),
    'format' => $format_id,
  );
}

/**
 * Helper to populate Tids for multiple values autocomplete term reference field.
 *
 * @param $field_name
 * @param $vocab_name
 * @param $value
 */
function movie_catalog_prepare_term_autocomplete($vocab_name, $value) {
  $value = is_array($value)
    ? implode(',', $value)
    : $value;
  $value = check_plain($value);

  $vocabulary = taxonomy_vocabulary_machine_name_load($vocab_name);

  $values = array();
  foreach (drupal_explode_tags($value) as $term_entry) {
    // See if the term exists in the chosen vocabulary and return the tid;
    // otherwise, create a new 'autocreate' term for insert/update.
    if ($possibilities = taxonomy_term_load_multiple(array(), array('name' => trim($term_entry), 'vid' => $vocabulary->vid))) {
      $term = array_pop($possibilities);
    }
    else {
      $term = array(
        'tid' => 'autocreate',
        'vid' => $vocabulary->vid,
        'name' => $term_entry,
        'vocabulary_machine_name' => $vocabulary->machine_name,
      );
    }
    $values[] = (array)$term;
  }

  return $values;
}
