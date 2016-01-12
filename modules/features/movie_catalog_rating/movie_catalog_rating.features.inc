<?php
/**
 * @file
 * movie_catalog_rating.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function movie_catalog_rating_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
