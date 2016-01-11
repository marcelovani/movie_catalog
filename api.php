<?php
/**
 * @file
 */

define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/profiles/movie_catalog/modules/contrib/endpoint/includes/router.inc';

$routes = array(
  'api/v1/foos' => array(
    'GET' => array(
      'callback' => 'my_module_foo_list',
      'anonymous'  => TRUE,
    ),
    'POST' => array(
      'callback' => 'my_module_foo_create',
    ),
  ),
  'api/v1/foo/(\w+)' => array(
    'GET' => array(
      'callback' => 'my_module_foo_get',
    ),
    'POST' => array(
      'include' => DRUPAL_ROOT . '/sites/all/modules/custom/another_module/includes/some_callback.inc',
      'callback' => 'my_module_foo_update',
    ),
  ),
);

endpoint_route(array(
  'debug' => TRUE,
  'routes' => $routes,
//  'authorize callback' => 'my_module_callback_authorize',
//  'error callback' => 'my_module_callback_error',
));

function my_module_foo_list() {
  // ...
  return array('foos' => 'baar');
}

function my_module_foo_create() {
  $data = endpoint_request_data();
  // ...
  return array('foo' => $foo, 'bar' => $bar);
}

function my_module_foo_get($id) {
  // ...
  return array('foo' => $foo, 'bar' => $bar);
}

function my_module_foo_update() {
  $data = endpoint_request_data();
  // ...
}
?>