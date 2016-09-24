
#include "interface.h"

int mi_readdir (const char *path, void *buff, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) 
{
	return 1;
}
