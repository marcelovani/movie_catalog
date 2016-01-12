<?php
/**
 * @file
 * movie_catalog_editorial.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function movie_catalog_editorial_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
