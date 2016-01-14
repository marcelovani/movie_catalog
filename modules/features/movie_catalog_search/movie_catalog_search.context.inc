<?php
/**
 * @file
 * movie_catalog_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function movie_catalog_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_results';
  $context->description = 'Search page and facets';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-0H5pq41S1PljCO8FEd0az1Kp1cX0ijAk' => array(
          'module' => 'facetapi',
          'delta' => '0H5pq41S1PljCO8FEd0az1Kp1cX0ijAk',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-oD0TtvfCljUvBaiu7fQCIlWMPSHUsotl' => array(
          'module' => 'facetapi',
          'delta' => 'oD0TtvfCljUvBaiu7fQCIlWMPSHUsotl',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  t('Search page and facets');
  $export['search_results'] = $context;

  return $export;
}
