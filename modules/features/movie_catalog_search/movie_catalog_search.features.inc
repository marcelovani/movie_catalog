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
 * Implements hook_default_search_api_index().
 */
function movie_catalog_search_default_search_api_index() {
  $items = array();
  $items['index'] = entity_import('search_api_index', '{
    "name" : "index",
    "machine_name" : "index",
    "description" : null,
    "server" : "db_search",
    "item_type" : "multiple",
    "options" : {
      "datasource" : { "types" : [ "node", "taxonomy_term", "taxonomy_vocabulary" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "node" : { "type" : "integer", "entity_type" : "node" },
        "node:field_cast" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_countries" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_genres" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "node:field_genres:name" : { "type" : "list\\u003Ctext\\u003E" },
        "node:field_rating" : { "type" : "decimal" },
        "node:title" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "taxonomy_term" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "taxonomy_term:name" : { "type" : "text" },
        "taxonomy_vocabulary" : { "type" : "integer", "entity_type" : "taxonomy_vocabulary" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "node" : true,
              "node:title" : true,
              "node:field_genres" : true,
              "node:field_rating" : true,
              "node:field_countries" : true,
              "node:field_cast" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
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
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : { "node:title" : "node:title" },
      "per_page" : "20",
      "result_page_search_form" : 1,
      "get_per_page" : 1,
      "view_mode" : "search_api_page_result",
      "empty_behavior" : ""
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
          },
          "node:field_countries" : {
            "table" : "search_api_db_index_node_field_countries",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "node:field_cast" : {
            "table" : "search_api_db_index_node_field_cast",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
