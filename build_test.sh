#! /bin/bash
echo "Rebuilding ..."
gcc src/nbs_selftest.c src/nbs_planet.c src/nbs_satellite.c -o bin/nbs_selftest
bin/nbs_selftest
