
#define FUSE_USE_VERSION 30

#include "interface.h" 

static struct fuse_operations mi_ops = {
	.getattr = mi_getattr,
	.mkdir = mi_mkdir,
	.rmdir = mi_rmdir,
	.rename = mi_rename,
	.open = mi_open,
	.read = mi_read,
	.write = mi_write,
	.opendir = mi_opendir,
	.readdir = mi_readdir,
	.init = mi_init,
	.create = mi_create,
};

int main(int argc, char* argv[]) 
{
	return fuse_main(argc, argv, &hello_oper, NULL);
}


