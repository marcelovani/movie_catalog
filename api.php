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

}

function my_module_foo_list() {
  // ...

  return array('result' => 'no action');
}

function movie_catalog_add_movie() {
  $movie_data = endpoint_request_data();
  if (isset($movie_data->imdb_id)) {
    $imdb_id = check_plain($movie_data->imdb_id);
  }
  else {
    watchdog('error', 'Invalid data passed to end point', array(), WATCHDOG_ALERT);
    return array('error' => 'Invalid IMDB ID');
  }

  $result = movie_catalog_movie_exists($imdb_id);

  if ($result !== FALSE) {
    $movie_data->entity_id = $result['entity_id'];
    $op = 'update';
  }
  else {
    $op = 'add';
  }

  $queue = DrupalQueue::get('movie_catalog');
  $queue->createQueue();
  $queue->createItem(
    array(
      'op' => $op,
      'type' => 'movies',
      'movie' => $movie_data
    )
  );

  return array('result' => 'queued');
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
 * Helper to check if the IMDB id already exists.
 *
 * @param $imdb_id
 * @return mixed
 */
function movie_catalog_movie_exists($imdb_id) {
  $result = db_select('field_data_field_imdb_id', 'i')
    ->fields('i', array('entity_id'))
    ->condition('field_imdb_id_value', $imdb_id, '=')
    ->condition('language', LANGUAGE_NONE, '=')
    ->execute()
    ->fetchAssoc();

  return $result;
}
