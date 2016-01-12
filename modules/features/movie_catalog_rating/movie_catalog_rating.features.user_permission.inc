<?php
/**
 * @file
 * movie_catalog_rating.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function movie_catalog_rating_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(),
    'module' => 'votingapi',
  );

  // Exported permission: 'view rate results page'.
  $permissions['view rate results page'] = array(
    'name' => 'view rate results page',
    'roles' => array(),
    'module' => 'rate',
  );

  return $permissions;
}
