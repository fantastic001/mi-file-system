
#include "interface.h"

int mi_read (const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) 
{
	mi_log("read() ");
	mi_log(path);
	mi_log("\n");
	return 1;
}
