IDIR = include
ODIR = build
SRCDIR = src
DEMODIR = demo
TARGETDIR = bin

CC = gcc
# CFLAGS = -I$(IDIR) -DDEBUG -DWITHSTATS -DWITHLOG -g -Wall -O2
# CFLAGS = -I$(IDIR) -DDEBUG -g -Wall -O2
CFLAGS = -I$(IDIR) -DDEBUG -DWITHSTATS -g -Wall -O2

# LDIR = -L./lib3rd/libyaml
# LIBS = -lyaml
LDIR =
LIBS =

_OBJ = nbs_planet.o nbs_satellite.o
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


.PHONY: clean lib dll test exe demo

$(ODIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

lib: $(OBJ)
	ar rcs $(LIBTARGET) $(ODIR)/*.o

dll: $(OBJ)
	$(CC) -shared -o $@ $^ -Wl,--out-implib,$(LIBTARGET) $(LDIR) $(LIBS)

test:
	$(CC) $(TESTSRC) -o $(TESTTARGET) $(CFLAGS) $(LDIR) $(LIBS)
	$(TESTTARGET)

exe:
	$(CC) $(EXESRC) -o $(EXETARGET) $(CFLAGS) $(LDIR) $(LIBS)

demo: lib
	# $(CC) -c $(SRCDIR)/vrp_demo.cpp -o $(ODIR)/vrp_demo.o $(CFLAGS)
	$(CC) -o $(DEMOTARGET) $(DEMOSRC) -Wall -O2 -L. $(LIBTARGET)
	# gcc -static -o vrp_demo $(ODIR)/vrp_demo.o -L. -lvrp

pylib:
	python py/setup.py build_ext --inplace

clean:
	rm -rf $(TARGETDIR)/* *.dll *.a *so $(ODIR)/* py/*.c


# g++ ga_cvrp.cpp heuristic.cpp tsp.cpp util.cpp -DDEBUG -Wall -o ../build/ga_cvrp -L../src/libyaml -lyaml
