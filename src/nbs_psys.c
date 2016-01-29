/*  =========================================================================
    nbs_psys - N-Body Simulation: Planet
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include "nbs_classes.h"


//  --------------------------------------------------------------------------
//  Structure of psys

struct _nbs_psys_t {
    // properties here
    int num_planets;
    // nbs_planet_t *planets;
};


//  --------------------------------------------------------------------------
//  Class constructor

nbs_psys_t *
nbs_psys_new () {
    nbs_psys_t *self = (nbs_psys_t *) malloc (sizeof (nbs_psys_t));
    assert (self);

    // Aim to initialize all properties to null/zero/false/empty by default.
    self->num_planets = 0;

    printf ("psys created.");
    return self;
}


//  --------------------------------------------------------------------------
//  Class destructor

void
nbs_psys_destroy (nbs_psys_t **self_p) {
    assert (self_p);
    if (*self_p) {
        nbs_psys_t *self = *self_p;

        // free properties here
        // int count;
        // for (count = 0; count < self->num_planets; count++) {
        //     nbs_planet_destroy (self->planets[count])
        // }


        free (self);
        *self_p = NULL;
    }
    printf ("psys destroyed.");
}


//  --------------------------------------------------------------------------
//  Get num_planets property.

int
nbs_psys_num_planets (nbs_psys_t *self) {
    assert (self);
    return self->num_planets;
}


//  --------------------------------------------------------------------------
//  run simulation

void
nbs_psys_run (nbs_psys_t *self) {
    assert (self);
    printf ("Simulation running ...\n");
}


//  --------------------------------------------------------------------------
//  Self test of this class

void
nbs_psys_test (bool verbose)
{
    printf (" * nbs_psys: ");
    nbs_psys_t *sim = nbs_psys_new ();
    nbs_psys_run (sim);
    nbs_psys_destroy (&sim);
    printf ("OK\n");
}
