Movie Catalog
=============

You can catalog your movies.
It has APIs that can obtain data from IMDB.
Also, provides an end point to accept requests that update the catalog.


Prerequisites
=============

- Git
- Drush


Installation
============

  1 - Create a database and configure your vhost as usual

  2 - Go to a temporary folder
  $ cd /tmp

  3 - Copy and paste this into your shell to install everything:
  $ curl -L -s http://goo.gl/Ur6uex | bash

  4 - Go inside the folder
  $ cd movie_catalog

  5 - Run the install script specifying the folder where you want the site to be created i.e.
  $ sh ./install.sh /Users/marcelo/Sites/movie_catalog

  6 - Open the site in your browser and perform a  Drupal installation, selecting Movie Catalog profile


Using it

  You can add movies manually. If you want to import your local movies using
  IMDB database, follow these steps:

  1 - Checkout https://github.com/marcelovani/IMDB-movie-scanner and follow instructions from README.md

  2 - Edit .htaccess on the Drupal core folder file and paste
		# Rewrite API callback URLs of the form api.php?q=x.
		RewriteCond %{REQUEST_URI} ^\/([a-z]{2}\/)?api\/.*
		RewriteRule ^(.*)$ api.php?q=$1 [L,QSA]
		RewriteCond %{QUERY_STRING} (^|&)q=(\/)?(\/)?api\/.*
		RewriteRule .* api.php [L]

  3 - Make sure you have a symlink on Drupal core folder to api.php inside profiles/movie_catalog
  i.e. Run this from the Drupal core folder: ln -s profiles/movie_catalog/api.php

  4 - You can try if the configuration of 3 and 4 works by visiting your site domain /api/imdb/movie/add
  You should get this response: {"result":{"result":"It Works!"}}

  5 - Run the script to scan your movies' folder and fetch IMDB data. On IMDB movie scanner folder run
  $ ./scan.py

  6 - Once the proccess in 5 has finished, go to your Drupal site and run cron. This will import all movies.
