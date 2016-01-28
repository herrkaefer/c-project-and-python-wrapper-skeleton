# pynbs.pyx - Cython wrapping of C public APIs
# Copyright (c) the Contributors as noted in the AUTHORS file.
# This file is part of the N-Body Simulation Project.
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

cdef extern from "../include/nbs.h":
    ctypedef struct nbs_psys_t
    nbs_psys_t *nbs_psys_new ()
    void nbs_psys_destroy (nbs_psys_t **obj_p)
    void nbs_psys_run (nbs_psys_t *obj)

cdef class Nbs:
    cdef nbs_psys_t *_thisptr

    def __init__(self):
        self._thisptr = nbs_psys_new()
        if self._thisptr == NULL:
            raise MemoryError("Insuffient memory.")

    def __dealloc__(self):
        if self._thisptr != NULL:
            nbs_psys_destroy(&self._thisptr)

    cpdef void run(self):
        nbs_psys_run(self._thisptr)



