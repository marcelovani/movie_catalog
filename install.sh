#!/bin/bash
set +x

INSTALL_DIR=$1
[ -z $INSTALL_DIR ] && echo [ERROR] You need to specify the install folder! e.g. $0 /Users/marcelo/Sites/movie_catalog && exit 1

function f_install_profile() {
  git clone --branch 7.x-1.x https://git.drupal.org/sandbox/marcelovani/2648246.git /tmp/movie_catalog
  cd  /tmp/movie_catalog
  echo "[INFO] Installing profile"
  drush make --prepare-install build-movie_catalog.make ${INSTALL_DIR}
  cd ${INSTALL_DIR}/sites/default
  drush si -y mv --db-url="mysql://root@localhost/movie_catalog" --site-name="Movie Catalog" --account-name=admin --account-pass=password --sites-subdir=default
}

f_install_profile

echo Done
