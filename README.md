Movie Catalog
=============

You can catalog your movies.
It has APIs that can obtain data from IMDB.
Also, provides an end point to accept requests that update the catalog.


Prerequisites

Git
Drush

Installation

  1 - Go to a temporary folder
  $ cd /tmp

  2 - Copy and paste this into your shell to install everything:
  $ curl -L -s http://goo.gl/UmWrmz | bash

  3 - Go inside the folder
  $ cd movie_catalog
  
  4 - Run install i.e.
  $ ./install.sh /Users/marcelo/Sites/movie_catalog

  5 - Edit .htaccess file and paste
  	Rewrite API callback URLs of the form api.php?q=x.
	RewriteCond %{REQUEST_URI} ^\/([a-z]{2}\/)?api\/.*
	RewriteRule ^(.*)$ api.php?q=$1 [L,QSA]
	RewriteCond %{QUERY_STRING} (^|&)q=(\/)?(\/)?api\/.*
	RewriteRule .* api.php [L]
	