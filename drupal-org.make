; drush make --no-core --no-gitinfofile --working-copy --contrib-destination=. -y drupal-org.make
api = 2
core = 7.x

projects[search_api_db][subdir] = contrib
projects[search_api_db][version] = 1.5

projects[search_api][subdir] = contrib
projects[search_api][version] = 1.20

projects[search_api_page][subdir] = contrib
projects[search_api_page][version] = 1.3

projects[facetapi][subdir] = contrib
projects[facetapi][version] = 1.5

projects[field_group][subdir] = contrib
projects[field_group][version] = 1.5

projects[diff][subdir] = contrib
projects[diff][version] = 3.2

projects[ckeditor][subdir] = contrib
projects[ckeditor][version] = 1.17

projects[endpoint][subdir] = contrib
projects[endpoint][version] = 1.4

projects[admin_menu][subdir] = contrib
projects[admin_menu][version] = 3.0-rc5

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.9

projects[entity][subdir] = contrib
projects[entity][version] = 1.7

projects[features][subdir] = contrib
projects[features][version] = 2.10

projects[features_override][subdir] = contrib
projects[features_override][version] = 2.0-rc3

projects[pathauto][subdir] = contrib
projects[pathauto][version] = 1.3

projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0

projects[token][subdir] = contrib
projects[token][version] = 1.6

projects[views][subdir] = contrib
projects[views][version] = 3.14

projects[entitycache][subdir] = contrib
projects[entitycache][version] = 1.5

projects[link][subdir] = contrib
projects[link][version] = 1.3

projects[libraries][subdir] = contrib
projects[libraries][version] = 2.3

projects[field_collection][subdir] = contrib
projects[field_collection][version] = 1.0-beta10

projects[context][subdir] = contrib
projects[context][version] = 3.7

projects[feeds][subdir] = contrib
projects[feeds][version] = 2.0-beta1

projects[module_filter][version] = 2.0
projects[module_filter][subdir] = contrib

projects[views_bulk_operations][version] = 3.3
projects[views_bulk_operations][subdir] = contrib

projects[omega_tools][subdir] = contrib
projects[omega_tools][version] = 3.0-rc4
projects[omega_tools][type] = module

projects[tao] = 3.1
projects[tao][type] = theme
projects[tao][subdir] = contrib

projects[rubik] = 4.4
projects[rubik][type] = theme
projects[rubik][subdir] = contrib

projects[omega] = 4.4
projects[omega][type] = theme
projects[omega][subdir] = contrib

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.5.6/ckeditor_4.5.6_standard.tar.gz

