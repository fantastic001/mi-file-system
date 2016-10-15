
#include "interface.h"

int mi_write (const char *path, const char *buff, size_t size, off_t offset, struct fuse_file_info *fi) 
{
	mi_log("write() ");
	mi_log(path);
	mi_log("\n");
	return 1;
}
