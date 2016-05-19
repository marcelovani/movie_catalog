#!/bin/bash
set +x

INSTALL_DIR=$1
[ -z $INSTALL_DIR ] && echo [ERROR] You need to specify the install folder! e.g. $0 /Users/marcelo/Sites/movie_catalog && exit 1

echo "[INFO] Installing profile"
drush make --prepare-install build-movie_catalog.make ${INSTALL_DIR}

cd ${INSTALL_DIR}

# Creating a symlink to the api.
if [ -e "api.php" ]
then
  rm -f api.php
fi
ln -s profiles/movie_catalog/api.php api.php

# Adding Rewrite API callback URLs of the form api.php?q=x.
for file in .htaccess; do
    if [ -e "$file.new" ]
    then
      rm -f $file.new
    fi

    if [ -e "$file.old" ]
    then
      rm -f $file.old
    fi

    sed 's/RewriteBase \/$/RewriteBase \/\n\nRewriteCond %{REQUEST_URI} ^\\\/([a-z]{2}\\\/)?api\\\/.*\r\nRewriteRule ^(.*)$ api.php?q=$1 [L,QSA]\r\nRewriteCond %{QUERY_STRING} \(^|\&\)q=(\\\/)?(\\\/)?api\\\/.*\nRewriteRule .* api.php [L]\n/g' $file > $file.new
    mv $file $file.old
    mv $file.new $file
done

# cd sites/default
# drush si -y movie_catalog --db-url="mysql://root@localhost/movie_catalog" --site-name="Movie Catalog" --account-name=admin --account-pass=password --sites-subdir=default
echo "[Info] Installation finished."
echo
echo Open the site in your browser and perform a  Drupal installation, selecting Movie Catalog profile
