<?php
/**
 * @file
 * movie_catalog_homepage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function movie_catalog_homepage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Home page blocks';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-movies-homepage' => array(
          'module' => 'views',
          'delta' => 'movies-homepage',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home page blocks');
  t('Pages');
  $export['homepage'] = $context;

  return $export;
}
