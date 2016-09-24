
#define FUSE_USE_VERSION 30

#include "interface.h" 

static struct fuse_operations mi_ops;

int main(int argc, char* argv[]) 
{
	mi_ops.getattr = mi_getattr;
	mi_ops.mkdir = mi_mkdir;
	mi_ops.rmdir = mi_rmdir;
	mi_ops.rename = mi_rename;
	mi_ops.open = mi_open;
	mi_ops.read = mi_read;
	mi_ops.write = mi_write;
	mi_ops.opendir = mi_opendir;
	mi_ops.readdir = mi_readdir;
	mi_ops.init = mi_init;
	mi_ops.create = mi_create;
	return fuse_main(argc, argv, &mi_ops, NULL);
}


