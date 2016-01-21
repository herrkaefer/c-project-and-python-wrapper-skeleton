/* This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "myp_myclass.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct _myp_myclass_t {
    // properties here
    char *myprop;
};

// class constructor
myp_myclass_t *
myp_myclass_new (void) {
    myp_myclass_t *self = (myp_myclass_t *) malloc (sizeof (myp_myclass_t));
    assert (self);

    // Aim to initialize all properties to null/zero/false/empty by default.
    self->myprop = NULL;

    return self;
}

// class destructor
void
myp_myclass_destroy (myp_myclass_t **self_p) {
    assert (self_p);
    if (*self_p) {
        myp_myclass_t *self = *self_p;

        // free properties here
        free (self->myprop); self->myprop = NULL; // or: safe_free (&self->myprop)

        free (self);
        *self_p = NULL;
    }
}

//  property getter
const char *
myp_myclass_myprop (myp_myclass_t *self) {
    assert (self);
    return self->myprop;
}

// property setter
void
myp_myclass_set_myprop (myp_myclass_t *self, const char *myprop) {
    assert (self);
    free (self->myprop);
    return self->myprop = strdup (myprop);
}
