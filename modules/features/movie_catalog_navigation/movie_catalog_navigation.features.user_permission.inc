<?php
/**
 * @file
 * movie_catalog_navigation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function movie_catalog_navigation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  return $permissions;
}
