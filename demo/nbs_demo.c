/*  =========================================================================
    nbs_demo.c - Demo of public API usage for developers
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/nbs.h"

int main (int argc, char *argv []) {
    puts ("Welcome to NBS!");
    nbs_psys_t *psys = nbs_psys_new ();
    nbs_psys_run (psys);
    nbs_psys_destroy (&psys);
    return 0;
}
