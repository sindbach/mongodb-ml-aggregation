# -*- mode: python -*-
 
Import("env")
 
env.Library(target='inject',
            source=['inject.cpp'],
            LIBDEPS=['$BUILD_DIR/mongo/base'],
            LIBDEPS_DEPENDENTS=['$BUILD_DIR/mongo/db/pipeline/pipeline'])
