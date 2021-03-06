IDIR = include
ODIR = build
SRCDIR = src
DEMODIR = demo
TARGETDIR = bin

CC = gcc
# CFLAGS = -I$(IDIR) -DDEBUG -DWITHSTATS -DWITHLOG -g -Wall -O2
# CFLAGS = -I$(IDIR) -DDEBUG -g -Wall -O2
CFLAGS = -I$(IDIR) -DWITHSTATS -g -Wall -O2

# LDIR = -L./lib3rd/libyaml
# LIBS = -lyaml
LDIR =
LIBS =

_OBJ = nbs_psys.o nbs_planet.o nbs_satellite.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
_LIBSRC = nbs_psys.c nbs_planet.c nbs_satellite.c
LIBSRC = $(patsubst %,$(SRCDIR)/%,$(_LIBSRC))
LIBTARGET = libnbs.a
TESTSRC = $(SRCDIR)/nbs_selftest.c $(LIBSRC)
TESTTARGET = $(TARGETDIR)/nbs_selftest
EXESRC = $(SRCDIR)/nbs_main.c $(LIBSRC)
EXETARGET = $(TARGETDIR)/nbs
DEMOSRC = $(DEMODIR)/nbs_demo.c
DEMOTARGET = $(TARGETDIR)/nbs_demo


.PHONY: clib cdll test exe demo pylib clean

$(ODIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clib: $(OBJ)
	ar rcs $(LIBTARGET) $(ODIR)/*.o

cdll: $(OBJ)
	$(CC) -shared -o $@ $^ -Wl,--out-implib,$(LIBTARGET) $(LDIR) $(LIBS)

test:
	$(CC) $(TESTSRC) -o $(TESTTARGET) $(CFLAGS) $(LDIR) $(LIBS)
	$(TESTTARGET)

exe:
	$(CC) $(EXESRC) -o $(EXETARGET) $(CFLAGS) $(LDIR) $(LIBS)

demo: clib
	$(CC) -o $(DEMOTARGET) $(DEMOSRC) -Wall -O2 -L. $(LIBTARGET)

pylib:
	python py/setup.py build_ext --inplace

clean:
	rm -rf $(TARGETDIR)/* *.dll *.a *so $(ODIR)/* py/*.c
