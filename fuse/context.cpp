
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
	mi_get_context()->curr = mi_get_context()->root;
	mi_get_context()->comm = new commands();
}

node* mi_get_destination(const char* path) 
{
	std::string dest(path);
	node* res = mi_get_context()->root;
	mi_get_context()->comm->destination(mi_get_context()->mem, res, mi_get_context()->curr, dest);
	return res;
}
