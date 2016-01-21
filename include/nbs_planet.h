
/*  =========================================================================
    nbs_planet - N-Body Simulation of Planet
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef NBS_PLANET_H_INCLUDED
#define NBS_PLANET_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _nbs_planet_t nbs_planet_t;

// Create a new planet
nbs_planet_t *
    nbs_planet_new (void);

// Destroy a planet
void
    nbs_planet_destroy (nbs_planet_t **self_p);

// Get planet name
const char *
    nbs_planet_name (nbs_planet_t *self);

// Set planet name
void
    nbs_planet_set_name (nbs_planet_t *self, const char *name);

#ifdef __cplusplus
}
#endif

#endif
