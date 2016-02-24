/*  =========================================================================
    nbs_planet - N-Body Simulation: Planet
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef __NBS_PLANET_H_INCLUDED__
#define __NBS_PLANET_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _nbs_planet_t nbs_planet_t;

// Create a new planet object
nbs_planet_t *nbs_planet_new (void);

// Destroy planet object
void nbs_planet_destroy (nbs_planet_t **self_p);

// Get name property
const char *nbs_planet_name (nbs_planet_t *self);

// Set name property
void nbs_planet_set_name (nbs_planet_t *self, const char *name);

// Get mass property
double nbs_planet_mass (nbs_planet_t *self);

// Set mass property
void nbs_planet_set_mass(nbs_planet_t *self, double mass);

// Get velocity property
double nbs_planet_velocity (nbs_planet_t *self);

// Set velocity property
void nbs_planet_set_velocity(nbs_planet_t *self, double velocity);

// Get momentum
double nbs_planet_momentum (nbs_planet_t *self);

// Self test
void nbs_planet_test (bool verbose);

#ifdef __cplusplus
}
#endif

#endif
