
#include "interface.h"

int mi_write (const char *path, const char *buff, size_t size, off_t offset, struct fuse_file_info *fi) 
{
	mi_log("write()\n");
	return 1;
}
