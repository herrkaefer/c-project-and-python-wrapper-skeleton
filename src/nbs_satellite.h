/*  =========================================================================
    nbs_satellite - N-Body Simulation: Satellite
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef __NBS_SATELLITE_H_INCLUDED__
#define __NBS_SATELLITE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _nbs_satellite_t nbs_satellite_t;

// Create a new satellite object
nbs_satellite_t * nbs_satellite_new (void);

// Destroy satellite object
void nbs_satellite_destroy (nbs_satellite_t **self_p);

// Get name property
const char *nbs_satellite_name (nbs_satellite_t *self);

// Set name property
void nbs_satellite_set_name (nbs_satellite_t *self, const char *name);

// Self test
void nbs_satellite_test (bool verbose);

#ifdef __cplusplus
}
#endif

#endif
