
#include "interface.h"


int mi_create(const char *path, mode_t mode, struct fuse_file_info *fi) 
{
	mi_log("create()\n");
	return 1;
}
