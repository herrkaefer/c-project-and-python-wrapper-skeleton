#! /bin/bash
echo "Rebuilding ..."
gcc src/nbs_selftest.c src/gdom_server.c -o src/gdom_selftest -lczmq
src/nbs_selftest
