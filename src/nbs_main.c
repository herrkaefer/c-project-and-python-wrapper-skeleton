/*  =========================================================================
    nbs_main.c - main
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include "nbs_classes.h"

int main (int argc, char *argv []) {
    puts ("nbs - N-Body Simulation");
    bool verbose = false;
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (strcmp (argv [argn], "--help") == 0
        ||  strcmp (argv [argn], "-h") == 0) {
            puts ("nbs [options] ...");
            puts ("  --verbose / -v         verbose test output");
            puts ("  --help / -h            this information");
            return 0;
        }
        else
        if (strcmp (argv [argn], "--verbose") == 0
        ||  strcmp (argv [argn], "-v") == 0)
            verbose = true;
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }
    //  Insert main code here
    if (verbose)
        // zsys_info ("nbs - N-Body Simulation");
        printf ("version: %d\n", GLOBDOM_VERSION);

    nbs_psys_t *sim = nbs_psys_new ();
    nbs_psys_run (sim);
    nbs_psys_destroy (&sim);

    return 0;
}
