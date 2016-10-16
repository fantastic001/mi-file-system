
#ifndef MI_FILESYSTEM_FUSE_CONTEXT_H 
#define MI_FILESYSTEM_FUSE_CONTEXT_H

#include "../include/memory.h"
#include "../include/node.h"
#include "../include/commands.h"
#include <fuse.h>

typedef struct {
	memory* mem;
	node* root;
	node* curr;
	commands* comm; 
} mi_context;

mi_context* mi_get_context();

void mi_init_context(memory* mem);

node* mi_get_destination(const char* path);

void mi_split_path(const char* path, char* basename, char* name);

void mi_get_stat(node*, struct stat*);

#endif // MI_FILESYSTEM_FUSE_CONTEXT_H
