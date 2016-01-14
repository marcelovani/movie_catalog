<?php
/**
 * @file
 * movie_catalog_appearance.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function movie_catalog_appearance_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
