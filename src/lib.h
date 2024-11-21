#ifndef CSTD_DEF_H
#define CSTD_DEF_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../include/cprimitives/src/lib.h"



/// A function that frees the resources held by `self`.
typedef void (*Destructor)(void* self);

/// A function that clones from `src` to `dest` without forgetting about the resources held by `self`.
typedef void (*Clone)(void* dest,void* src);

typedef int (*ComparisonFn)(const void*,const void*);

typedef bool (*PredicateFn)(const void*);


#ifndef MAX
#define MAX(x,y) ((x)>(y))?(x):(y)
#endif
#ifndef MIN
#define MIN(x,y) ((x)<(y))?(x):(y)
#endif

#define MIN_NON_ZERO_CAP(SIZE) ((SIZE)==1)?(8):((SIZE)<=1024)?4:1
#define panic(...) { fprintf(stderr,__VA_ARGS__);exit(1); }
#define inline_always __inline __attribute__ ((__always_inline__))

#ifndef not_null
#define not_null(ptr) { assert(ptr!=NULL); }
#endif
#ifndef not_null2
#define not_null2(ptr1,ptr2) { assert(ptr1!=NULL);assert(ptr2); }
#endif

/// inspired by dr Jonas Birch
#define lambda(ident,_,params,__,ret_type,c) \
  ret_type __fn_lambda##ident##__LINE__ params { return c; } \
  ret_type (*ident) params = __fn_lambda ## ident ## __LINE__ ;



#endif
