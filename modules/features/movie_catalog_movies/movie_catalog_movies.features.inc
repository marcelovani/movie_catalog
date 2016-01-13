<?php
/**
 * @file
 * movie_catalog_movies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function movie_catalog_movies_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function movie_catalog_movies_image_default_styles() {
  $styles = array();

  // Exported image style: cover.
  $styles['cover'] = array(
    'label' => 'Cover',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      3 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 350,
          'height' => 500,
          'anchor' => 'center-center',
        ),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function movie_catalog_movies_node_info() {
  $items = array(
    'movies' => array(
      'name' => t('Movies'),
      'base' => 'node_content',
      'description' => t('Stores movies information'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
