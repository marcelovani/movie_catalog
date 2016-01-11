#!/bin/bash
set +x

echo
echo "[Info] Bootstrap is cloning the repo"

git clone --recursive --branch master http://git.drupal.org:sandbox/marcelovani/2648246.git movie_catalog

echo "[Info] Bootstrap has finished installation."
echo
echo To install Distro run 
echo $ cd movie_catalog
echo $ ./install.sh
