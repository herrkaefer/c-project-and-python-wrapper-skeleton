/*  =========================================================================
    gdom_selftest.c - run selftests
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include "nbs_classes.h"

typedef struct {
    const char *testname;
    void (*test) (bool);
} test_item_t;

static test_item_t
all_tests [] = {
// #ifdef WITH_DRAFTS
    { "nbs_planet", nbs_planet_test },
    { "nbs_satellite", nbs_satellite_test },
// #endif // WITH_DRAFTS
    {0, 0}          //  Sentinel
};


//  -------------------------------------------------------------------------
//  Run all tests.
//

static void
test_runall (bool verbose)
{
    test_item_t *item;
    printf ("Running selftests...\n");
    for (item = all_tests; item->test; item++)
        item->test (verbose);

    printf ("Tests passed OK\n");
}


int
main (int argc, char **argv)
{
    test_runall (true);
    return 0;
}
