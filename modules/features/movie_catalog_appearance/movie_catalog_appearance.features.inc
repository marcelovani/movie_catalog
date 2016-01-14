<?php
/**
 * @file
 * movie_catalog_appearance.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function movie_catalog_appearance_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function movie_catalog_appearance_strongarm_alter(&$data) {
  if (isset($data['theme_default'])) {
    $data['theme_default']->value = 'movie_catalog'; /* WAS: 'omega' */
  }
}
