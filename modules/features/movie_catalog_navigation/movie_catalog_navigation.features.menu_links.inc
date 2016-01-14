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
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: management_menus:admin/structure/menu.
  $menu_links['management_menus:admin/structure/menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Add new menus to your site, edit existing menus, and rename and reorganize menu links.',
      ),
      'identifier' => 'management_menus:admin/structure/menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Menus');
  t('Movies');

  return $menu_links;
}
