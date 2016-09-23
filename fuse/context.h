
#ifndef MI_FILESYSTEM_FUSE_CONTEXT_H 
#define MI_FILESYSTEM_FUSE_CONTEXT_H

#include "../include/memory.h"
#include "../include/node.h"
#include <fuse.h>

typedef struct {
	memory* mem;
	node* root;
} mi_context;

mi_context* mi_get_context();

void mi_init_context(memory* mem);

#endif // MI_FILESYSTEM_FUSE_CONTEXT_H
