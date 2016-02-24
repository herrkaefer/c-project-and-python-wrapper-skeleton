/*  =========================================================================
    nbs_satellite - N-Body Simulation: Satellite
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include "nbs_classes.h"


//  --------------------------------------------------------------------------
//  Structure of satellite

struct _nbs_satellite_t {
    // properties here
    char *name;
};


//  --------------------------------------------------------------------------
//  Class constructor

nbs_satellite_t *nbs_satellite_new (void) {
    nbs_satellite_t *self = (nbs_satellite_t *) malloc (sizeof (nbs_satellite_t));
    assert (self);

    // Aim to initialize all properties to null/zero/false/empty by default.
    self->name = NULL;

    return self;
}


//  --------------------------------------------------------------------------
//  Class destructor

void nbs_satellite_destroy (nbs_satellite_t **self_p) {
    assert (self_p);
    if (*self_p) {
        nbs_satellite_t *self = *self_p;

        // free properties here
        free (self->name); self->name = NULL; // or: safe_free (&self->name)

        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Get name property.
//  Note that it's defined as 'const' so the caller cannot modify it.

const char *nbs_satellite_name (nbs_satellite_t *self) {
    assert (self);
    return self->name;
}


//  --------------------------------------------------------------------------
//  Set name property

void nbs_satellite_set_name (nbs_satellite_t *self, const char *name) {
    assert (self);
    free (self->name);
    self->name = strdup (name);
}


//  --------------------------------------------------------------------------
//  Self test of this class

void nbs_satellite_test (bool verbose)
{
    printf (" * nbs_satellite: ");
    nbs_satellite_t *satellite = nbs_satellite_new ();
    nbs_satellite_destroy (&satellite);
    printf ("OK\n");
}
