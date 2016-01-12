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
));

function my_module_foo_list() {
  // ...
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  $node = node_load(1);
  return array('node' => $node);
}

function movie_catalog_add_movie() {
  $data = endpoint_request_data();

  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

  $node = new stdClass();
  $node->type = "movies";
  node_object_prepare($node);

  $node->title = $data->title;
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled

  $body = implode('<br>', $data->plot);
  $node->body[$node->language][0]['value']   = $body;
  $node->body[$node->language][0]['summary'] = text_summary($body);
  $node->body[$node->language][0]['format']  = 'filtered_html';

  //$node->path = array('alias' => $path);
  // Disable pathauto for this node
  //$node->path['pathauto'] = '';

  $node->status = 1; //(1 or 0): published or not
  //$node->promote = 0; //(1 or 0): promoted to front page
  //$node->comment = 1; // 0 = comments disabled, 1 = read only, 2 = read/write

  // Term reference (taxonomy) field
  //$node->field_product_tid[$node->language][]['tid'] = $form_state['values']['a taxonomy term id'];

  // Entity reference field
  /*
  $node->field_customer_nid[$node->language][] = array(
    'target_id' => $form_state['values']['entity id'],
    'target_type' => 'node',
  );
  */
  // 'node' is default,

  //$node = node_submit($node); // Prepare node for saving
  node_save($node);

  // ...
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