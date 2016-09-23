
#include "interface.h" 
#include "context.h"
#include "../include/memory.h"


int mi_init(struct fuse_conn_info *conn) 
{
	mi_init_context(new memory());
}
