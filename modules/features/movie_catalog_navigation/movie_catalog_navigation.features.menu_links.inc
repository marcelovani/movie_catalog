<?php
/**
 * @file
 * movie_catalog_navigation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function movie_catalog_navigation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_genres:genres.
  $menu_links['main-menu_genres:genres'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'genres',
    'router_path' => 'genres',
    'link_title' => 'Genres',
    'options' => array(
      'identifier' => 'main-menu_genres:genres',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_movies:movies.
  $menu_links['main-menu_movies:movies'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'movies',
    'router_path' => 'movies',
    'link_title' => 'Movies',
    'options' => array(
      'identifier' => 'main-menu_movies:movies',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_search:search.
  $menu_links['main-menu_search:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_search:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Genres');
  t('Movies');
  t('Search');

  return $menu_links;
}
