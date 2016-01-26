#! /bin/bash
echo "Rebuilding main..."
gcc src/nbs_main.c src/nbs_planet.c src/nbs_satellite.c -o bin/nbs
bin/nbs
