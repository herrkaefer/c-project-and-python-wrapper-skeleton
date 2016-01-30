from distutils.core import setup, Extension
from Cython.Build import cythonize

# list of all source files for building the lib
_src = ["nbs_psys.c", "nbs_planet.c", "nbs_satellite.c"]
_srcdir = "src/"
src = [_srcdir + s for s in _src]
src.append("py/pynbs.pyx")

ext = Extension(name="pynbs", sources=src)
setup(ext_modules=cythonize(ext))
