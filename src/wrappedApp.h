//
//  wrappedApp.h
//  dynamicLoad
//

#pragma once
#include "ofBaseApp.h"

typedef ofBaseApp* create_t();
typedef void destroy_t(ofBaseApp*);