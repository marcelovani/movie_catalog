<?php
// $Id$

require_once('movie_catalog.module');

/**
 * Implements hook_form_alter().
 */
function movie_catalog_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure_form') {
    $form['site_information']['site_name']['#default_value'] = 'Movie Catalog';
  }
}
/**
 * Implements hook_install_tasks()
 */
function movie_catalog_install_tasks() {

  $tasks['set_admin_theme'] = array(
    'display_name' => st('Set theme'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => '_movie_catalog_set_theme',
  );

  return $tasks;
}
