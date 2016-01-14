<?php
/**
 * @file
 * movie_catalog_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function movie_catalog_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_page().
 */
function movie_catalog_search_default_search_api_page() {
  $items = array();
  $items['search'] = entity_import('search_api_page', '{
    "index_id" : "index",
    "path" : "search",
    "name" : "Search",
    "machine_name" : "search",
    "description" : null,
    "options" : {
      "mode" : "terms",
      "fields" : {
        "node:field_genres:name" : "node:field_genres:name",
        "node:title" : "node:title",
        "taxonomy_term:name" : "taxonomy_term:name"
      },
      "per_page" : "10",
      "get_per_page" : 0,
      "result_page_search_form" : 1,
      "view_mode" : "search_api_page_result"
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function movie_catalog_search_default_search_api_server() {
  $items = array();
  $items['db_search'] = entity_import('search_api_server', '{
    "name" : "db search",
    "machine_name" : "db_search",
    "description" : "aaa",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "indexes" : { "index" : {
          "node" : {
            "table" : "search_api_db_index",
            "column" : "node",
            "type" : "integer",
            "boost" : "1.0"
          },
          "taxonomy_term" : {
            "table" : "search_api_db_index",
            "column" : "taxonomy_term",
            "type" : "integer",
            "boost" : "1.0"
          },
          "taxonomy_vocabulary" : {
            "table" : "search_api_db_index",
            "column" : "taxonomy_vocabulary",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "node:title" : { "table" : "search_api_db_index_text", "type" : "text", "boost" : "1.0" },
          "node:field_genres" : {
            "table" : "search_api_db_index_node_field_genres",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "node:field_rating" : {
            "table" : "search_api_db_index",
            "column" : "node_field_rating",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "taxonomy_term:name" : { "table" : "search_api_db_index_text", "type" : "text", "boost" : "1.0" },
          "node:field_genres:name" : {
            "table" : "search_api_db_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
