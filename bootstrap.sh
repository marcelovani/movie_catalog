#!/bin/bash
set +x

echo
echo "[Info] Bootstrap is cloning the repo"

git clone --branch 7.x-1.x https://git.drupal.org/project/movie_catalog.git movie_catalog

echo "[Info] Bootstrap has finished installation."
echo
echo To install the Drupal profile do the following:
echo $ cd movie_catalog
echo $ sh ./install.sh
