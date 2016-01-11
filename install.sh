#!/bin/bash
set +x

INSTALL_DIR=$1
[ -z $INSTALL_DIR ] && echo [ERROR] You need to specify the install folder! e.g. $0 /Users/marcelo/Sites/movie_catalog && exit 1

function f_install_drush() {
  if [ ! -d "/usr/local/drush" ]; then
    echo "[INFO] Installing Drush"
    sudo git clone --branch 7.x-5.x http://git.drupal.org/project/drush.git /usr/local/drush
    sudo /usr/local/drush/drush --version
  fi
}

function f_install_site() {
  echo "[INFO] Installing Drupal"
  /usr/local/drush/drush make --prepare-install build-movie_catalog.make ${INSTALL_DIR}
  cd ${INSTALL_DIR}/sites/default
  /usr/local/drush/drush si -y mv --db-url="mysql://root@localhost/movie_catalog" --site-name="Movie Catalog" --account-name=admin --account-pass=password --sites-subdir=default
}

f_install_drush
f_install_site

echo Done
