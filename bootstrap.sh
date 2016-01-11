#!/bin/bash
set +x

echo
echo "[Info] Bootstrap is cloning the repo"

git clone --branch 7.x-1.x https://git.drupal.org/sandbox/marcelovani/2648246.git 

echo "[Info] Bootstrap has finished installation."
echo
echo To install Distro run 
echo $ cd movie_catalog
echo $ ./install.sh
