/*  =========================================================================
    nbs_planet - N-Body Simulation: Planet
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include "nbs_classes.h"


//  --------------------------------------------------------------------------
//  Structure of planet

struct _nbs_planet_t {
    // properties here
    char *name;
    double mass;
    double velocity;
    // int num_satellite;
    // nbs_satellite_t *satellites;
};


//  --------------------------------------------------------------------------
//  Class constructor

nbs_planet_t *
nbs_planet_new (void) {
    nbs_planet_t *self = (nbs_planet_t *) malloc (sizeof (nbs_planet_t));
    assert (self);

    // Aim to initialize all properties to null/zero/false/empty by default.
    self->name = NULL;
    self->mass = 0.0;
    self->velocity = 0.0;

    return self;
}


//  --------------------------------------------------------------------------
//  Class destructor

void
nbs_planet_destroy (nbs_planet_t **self_p) {
    assert (self_p);
    if (*self_p) {
        nbs_planet_t *self = *self_p;

        // free properties here
        free (self->name); self->name = NULL; // or: safe_free (&self->name)

        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Get name property.
//  Note that it's defined as 'const' so the caller cannot modify it.

const char *
nbs_planet_name (nbs_planet_t *self) {
    assert (self);
    return self->name;
}


//  --------------------------------------------------------------------------
//  Set name property

void
nbs_planet_set_name (nbs_planet_t *self, const char *name) {
    assert (self);
    free (self->name);
    self->name = strdup (name);
}


//  --------------------------------------------------------------------------
//  Get mass property.

double
nbs_planet_mass (nbs_planet_t *self) {
    assert (self);
    return self->mass;
}


//  --------------------------------------------------------------------------
//  Set mass property

void
nbs_planet_set_mass (nbs_planet_t *self, double mass) {
    assert (self);
    self->mass = mass;
}


//  --------------------------------------------------------------------------
//  Get velocity property.

double
nbs_planet_velocity (nbs_planet_t *self) {
    assert (self);
    return self->velocity;
}


//  --------------------------------------------------------------------------
//  Set velocity property

void
nbs_planet_set_velocity (nbs_planet_t *self, double velocity) {
    assert (self);
    self->velocity = velocity;
}


//  --------------------------------------------------------------------------
//  Get momentum

double
nbs_planet_momentum (nbs_planet_t *self) {
    assert (self);
    return self->mass * self->velocity;
}


//  --------------------------------------------------------------------------
//  Self test of this class

void
nbs_planet_test (bool verbose)
{
    printf (" * nbs_planet: ");
    nbs_planet_t *planet = nbs_planet_new ();
    nbs_planet_destroy (&planet);
    printf ("OK\n");
}
