#!/bin/bash

SELF=$(cd `dirname $0`; pwd)

set -xe

cd $SELF/..
if [ ! -d node_modules ]; then
   npm install
fi
if [ ! -d dist ]; then
   npm run build
fi

TO=dist/storage.googleapis.com/workbox-cdn/releases/3.6.3
mkdir -p dist/storage.googleapis.com/workbox-cdn/releases/3.6.3
cp node_modules/workbox-sw/build/workbox-sw.js $TO
cp node_modules/workbox-strategies/build/workbox-strategies.prod.js $TO
cp node_modules/workbox-precaching/build/workbox-precaching.prod.js $TO
#cp node_modules/workbox-google-analytics/build/workbox-google-analytics.prod.js $TO
cp node_modules/workbox-cache-expiration/build/workbox-cache-expiration.prod.js $TO
cp node_modules/workbox-routing/build/workbox-routing.prod.js $TO
cp node_modules/workbox-broadcast-cache-update/build/workbox-broadcast-cache-update.prod.js $TO
cp node_modules/workbox-core/build/workbox-core.prod.js $TO
cp node_modules/workbox-navigation-preload/build/workbox-navigation-preload.prod.js $TO
cp node_modules/workbox-range-requests/build/workbox-range-requests.prod.js $TO
cp node_modules/workbox-streams/build/workbox-streams.prod.js $TO
cp node_modules/workbox-background-sync/build/workbox-background-sync.prod.js $TO
cp node_modules/workbox-cacheable-response/build/workbox-cacheable-response.prod.js $TO

sed -i 's|https://storage[.]googleapis[.]com|storage.googleapis.com|g' $TO/workbox-sw.js
sed -i 's|https://storage[.]googleapis[.]com|storage.googleapis.com|g' dist/workbox-sw.js
