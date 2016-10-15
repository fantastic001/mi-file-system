
#include "interface.h"

int mi_open(const char *path, struct fuse_file_info *fi) 
{
	mi_log("open() ");
	mi_log(path);
	mi_log("\n");
	return 1;
}
