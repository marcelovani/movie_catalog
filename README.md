Movie Catalog
=============

You can catalog your movies.
It has APIs that can obtain data from IMDB.
Also, provides an end point to accept requests that update the catalog.


Prerequisites
=============

- Git
- Drush
- Setting up virtual host (MAMP or Acquia DevDesktop are handy)


Installation
============
  1 - Open terminal

  2 - Go to a temporary folder
  $ cd /tmp

  3 - Copy and paste this into your shell to install everything:
  $ curl -L -s http://goo.gl/Ur6uex | bash

  4 - Go inside the folder
  $ cd movie_catalog

  5 - Run the install script specifying the folder where you want the site to be created i.e.
  $ sh ./install.sh /Users/marcelo/Sites/movie_catalog

  6 - Create a database and configure your vhost pointing to the folder specified in 5

  7 - Open the site in your browser and perform a Drupal installation, selecting Movie Catalog profile

IMDB script
===========
A Python script that scans your folders and uses the file names to grab movie metadata
from IMDB website. It sends the information to an end point in the drupal site, which
adds to a queue that is processed next time cron runs.

  To install the script, follow these steps:

  1 - Checkout https://github.com/marcelovani/IMDB-movie-scanner and
    follow instructions from README.md
  $ git clone https://github.com/marcelovani/IMDB-movie-scanner

  2 - Make sure that these lines are present on the .htaccess file in the drupal core folder.

		# Rewrite API callback URLs of the form api.php?q=x.
		RewriteCond %{REQUEST_URI} ^\/([a-z]{2}\/)?api\/.*
		RewriteRule ^(.*)$ api.php?q=$1 [L,QSA]
		RewriteCond %{QUERY_STRING} (^|&)q=(\/)?(\/)?api\/.*
		RewriteRule .* api.php [L]

  3 - Make sure you have a symlink on Drupal core folder to api.php inside profiles/movie_catalog
  i.e. Run this from the Drupal core folder: ln -s profiles/movie_catalog/api.php
  This symlink should be automatically created by the install script.

  4 - You can try if the configuration of 2 and 3 works by visiting your site domain /api/imdb/movie/add
  You should get this response: {"result":{"result":"It Works!"}}

  5 - Run the script to scan your movies' folder and fetch IMDB data. On IMDB movie scanner folder run
  $ ./scan.py

  6 - Once the proccess in 5 has finished, go to your Drupal site and run cron. This will import all movies.
