
#include "interface.h" 
#include "context.h"
#include "../include/memory.h"


void* mi_init(struct fuse_conn_info *conn) 
{
	mi_log("init()\n");
	mi_init_context(new memory());
}
