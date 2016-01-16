<?php
/**
 * @file
 * movie_catalog_movies.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function movie_catalog_movies_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'genres';
  $context->description = 'Displays a block with genres';
  $context->tag = 'Movies';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~node/add/*' => '~node/add/*',
        '~search/*' => '~search/*',
        '~genres/*' => '~genres/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-genres-genres' => array(
          'module' => 'views',
          'delta' => 'genres-genres',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays a block with genres');
  t('Movies');
  $export['genres'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'people';
  $context->description = 'List of Directos and cast';
  $context->tag = 'Movies';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~node/add/*' => '~node/add/*',
        '~search/*' => '~search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-people-cast' => array(
          'module' => 'views',
          'delta' => 'people-cast',
          'region' => 'sidebar_second',
          'weight' => '-16',
        ),
        'views-people-directors' => array(
          'module' => 'views',
          'delta' => 'people-directors',
          'region' => 'sidebar_second',
          'weight' => '-15',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List of Directos and cast');
  t('Movies');
  $export['people'] = $context;

  return $export;
}
