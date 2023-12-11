from distutils.core import setup, Extension

module = Extension(
    name="my_c_module",
    sources=["fib/main.c"],
    include_dirs=[],  # list of directories to search for C/C++ header files
    library_dirs=[],  # list of directories to search for static libraries
    runtime_library_dirs=[],  # list of directories to search for shared libraries
    libraries=[],  # list of library names)
)

setup(name="fibonacci", version="1.0", description="...", ext_modules=[module])
