/*  =========================================================================
    nbs_psys - N-Body Simulation: Particles System
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the N-Body Simulation Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef NBS_PSYS_H_INCLUDED
#define NBS_PSYS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _nbs_psys_t nbs_psys_t;

// Create a new psys object
nbs_psys_t *
    nbs_psys_new (void);

// Destroy psys object
void
    nbs_psys_destroy (nbs_psys_t **self_p);

// Run simulation
void nbs_psys_run (nbs_psys_t *self);

// Self test
void
    nbs_psys_test (bool verbose);

#ifdef __cplusplus
}
#endif

#endif
