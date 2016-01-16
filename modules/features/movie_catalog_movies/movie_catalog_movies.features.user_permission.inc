<?php
/**
 * @file
 * movie_catalog_movies.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function movie_catalog_movies_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create movies content'.
  $permissions['create movies content'] = array(
    'name' => 'create movies content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any movies content'.
  $permissions['delete any movies content'] = array(
    'name' => 'delete any movies content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own movies content'.
  $permissions['delete own movies content'] = array(
    'name' => 'delete own movies content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in countries'.
  $permissions['delete terms in countries'] = array(
    'name' => 'delete terms in countries',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in genres'.
  $permissions['delete terms in genres'] = array(
    'name' => 'delete terms in genres',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in people'.
  $permissions['delete terms in people'] = array(
    'name' => 'delete terms in people',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any movies content'.
  $permissions['edit any movies content'] = array(
    'name' => 'edit any movies content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own movies content'.
  $permissions['edit own movies content'] = array(
    'name' => 'edit own movies content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in countries'.
  $permissions['edit terms in countries'] = array(
    'name' => 'edit terms in countries',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in genres'.
  $permissions['edit terms in genres'] = array(
    'name' => 'edit terms in genres',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in people'.
  $permissions['edit terms in people'] = array(
    'name' => 'edit terms in people',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
