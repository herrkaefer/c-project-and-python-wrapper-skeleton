/*  =========================================================================
    sct_myclass - Scalable C Template: Myclass
    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the Scalable C Template Project.
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#include "sct_classes.h"


//  --------------------------------------------------------------------------
//  Structure of myclass

struct _sct_myclass_t {
    // properties here
    int filler;
    char *name;
};


//  --------------------------------------------------------------------------
//  Class constructor

sct_myclass_t *
sct_myclass_new (void) {
    sct_myclass_t *self = (sct_myclass_t *) malloc (sizeof (sct_myclass_t));
    assert (self);

    // Aim to initialize all properties to null/zero/false/empty by default.
    self->name = NULL;

    return self;
}


//  --------------------------------------------------------------------------
//  Class destructor

void
sct_myclass_destroy (sct_myclass_t **self_p) {
    assert (self_p);
    if (*self_p) {
        sct_myclass_t *self = *self_p;

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
sct_myclass_name (sct_myclass_t *self) {
    assert (self);
    return self->name;
}


//  --------------------------------------------------------------------------
//  Set name property

void
sct_myclass_set_name (sct_myclass_t *self, const char *name) {
    assert (self);
    free (self->name);
    return self->name = strdup (name);
}


//  --------------------------------------------------------------------------
//  Self test of this class

void
sct_myclass_test (bool verbose)
{
    printf (" * sct_myclass: ");
    sct_myclass_t *myclass = sct_myclass_new ();
    gdom_server_destroy (&myclass);
    printf ("OK\n");
}
