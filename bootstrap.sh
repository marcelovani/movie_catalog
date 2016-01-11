#!/bin/bash
set +x

echo
echo "[Info] Bootstrap is cloning the repo"

git clone --recursive --branch https://git.drupal.org/sandbox/marcelovani/2648246.git /tmp/movie_catalog

echo "[Info] Bootstrap has finished installation."
echo
echo To install Distro run 
echo $ cd movie_catalog
echo $ ./install.sh
