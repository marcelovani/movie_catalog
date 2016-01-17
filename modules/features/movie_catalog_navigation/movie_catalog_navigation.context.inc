<?php
/**
 * @file
 * movie_catalog_navigation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function movie_catalog_navigation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main_menu';
  $context->description = '';
  $context->tag = 'Navigation';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin*' => '~admin*',
        '~node/add' => '~node/add',
        '~node/edit' => '~node/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  $export['main_menu'] = $context;

  return $export;
}
