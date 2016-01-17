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
  $context->name = 'search';
  $context->description = '';
  $context->tag = 'Search';
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
        'search_api_page-search' => array(
          'module' => 'search_api_page',
          'delta' => 'search',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['search'] = $context;

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
        'facetapi-5Vz0sxpO2a1pHgp6GkK2ayelvOH9B5eP' => array(
          'module' => 'facetapi',
          'delta' => '5Vz0sxpO2a1pHgp6GkK2ayelvOH9B5eP',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-8tHGhOF79DyajH5n7OSXY3aSnbxinWUG' => array(
          'module' => 'facetapi',
          'delta' => '8tHGhOF79DyajH5n7OSXY3aSnbxinWUG',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-bYGXB1ccyI6wJCGqNExOdeiQfFEcdnHy' => array(
          'module' => 'facetapi',
          'delta' => 'bYGXB1ccyI6wJCGqNExOdeiQfFEcdnHy',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'facetapi-oD0TtvfCljUvBaiu7fQCIlWMPSHUsotl' => array(
          'module' => 'facetapi',
          'delta' => 'oD0TtvfCljUvBaiu7fQCIlWMPSHUsotl',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'facetapi-3ehTJa9L58xHyaGRJT0m1bocAR0AKPaw' => array(
          'module' => 'facetapi',
          'delta' => '3ehTJa9L58xHyaGRJT0m1bocAR0AKPaw',
          'region' => 'sidebar_second',
          'weight' => '-5',
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
