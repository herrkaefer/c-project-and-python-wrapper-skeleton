/*  =========================================================================
    sct_myclass - Scalable C Template: Myclass
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Scalable C Template Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef SCT_MYCLASS_H_INCLUDED
#define SCT_MYCLASS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _sct_myclass_t sct_myclass_t;

// @interface
// Create a new myclass object
sct_myclass_t *
    sct_myclass_new (void);

// Destroy myclass object
void
    sct_myclass_destroy (sct_myclass_t **self_p);

// Get name property
const char *
    sct_myclass_name (sct_myclass_t *self);

// Set name property
void
    sct_myclass_set_name (sct_myclass_t *self, const char *name);
// @end

#ifdef __cplusplus
}
#endif

#endif
