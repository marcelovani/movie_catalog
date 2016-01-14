<?php
/**
 * @file
 * movie_catalog_appearance.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function movie_catalog_appearance_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: variable
  $overrides["variable.theme_default.value"] = 'movie_catalog';

 return $overrides;
}
