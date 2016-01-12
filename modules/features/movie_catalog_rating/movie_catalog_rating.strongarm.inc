<?php
/**
 * @file
 * movie_catalog_rating.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function movie_catalog_rating_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'rating',
      'tag' => 'vote',
      'title' => 'Rating',
      'node_types' => array(
        0 => 'movies',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '0',
          1 => '1',
        ),
        1 => array(
          0 => '20',
          1 => '2',
        ),
        2 => array(
          0 => '30',
          1 => '3',
        ),
        3 => array(
          0 => '40',
          1 => '4',
        ),
        4 => array(
          0 => '50',
          1 => '5',
        ),
        5 => array(
          0 => '60',
          1 => '6',
        ),
        6 => array(
          0 => '70',
          1 => '7',
        ),
        7 => array(
          0 => '80',
          1 => '8',
        ),
        8 => array(
          0 => '90',
          1 => '9',
        ),
        9 => array(
          0 => '100',
          1 => '10',
        ),
      ),
      'template' => 'fivestar',
      'node_display' => '1',
      'teaser_display' => TRUE,
      'comment_display' => '0',
      'node_display_mode' => '1',
      'teaser_display_mode' => '2',
      'comment_display_mode' => '1',
      'roles' => array(
        4 => '4',
        3 => 0,
        1 => 0,
        2 => 0,
      ),
      'allow_voting_by_author' => 0,
      'noperm_behaviour' => '1',
      'displayed' => '1',
      'displayed_just_voted' => '1',
      'description' => '',
      'description_in_compact' => FALSE,
      'delete_vote_on_second_click' => '0',
      'use_source_translation' => TRUE,
      'value_type' => 'percent',
      'theme' => 'rate_template_fivestar',
      'css' => 'profiles/movie_catalog/modules/contrib/rate/templates/fivestar/fivestar.css',
      'js' => 'profiles/movie_catalog/modules/contrib/rate/templates/fivestar/fivestar.js',
      'translate' => FALSE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  return $export;
}
