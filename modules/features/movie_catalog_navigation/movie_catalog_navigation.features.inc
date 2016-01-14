<?php
/**
 * @file
 * movie_catalog_navigation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function movie_catalog_navigation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
