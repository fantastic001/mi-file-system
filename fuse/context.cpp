
#include "context.h"

mi_context* mi_get_context() 
{
	return (mi_context*) fuse_get_context()->private_data;
}

void mi_init_context(memory* mem) 
{
	fuse_get_context()->private_data = new mi_context;
	mi_get_context()->mem = mem;
	mi_get_context()->mem->initialize_mem();
	node* root = mi_get_context()->mem->create_root();
	mi_get_context()->root = root;
}
