<?php
/**
 * @file
 * movie_catalog_movies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function movie_catalog_movies_taxonomy_default_vocabularies() {
  return array(
    'countries' => array(
      'name' => 'Countries',
      'machine_name' => 'countries',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'genres' => array(
      'name' => 'Genres',
      'machine_name' => 'genres',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
