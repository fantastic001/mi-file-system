
#include "interface.h"

int mi_open(const char *path, struct fuse_file_info *fi) 
{
	mi_log("open()\n");
	return 1;
}
