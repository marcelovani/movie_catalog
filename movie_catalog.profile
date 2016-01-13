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
