
#include "interface.h"
#include "context.h"
#include <sys/stat.h>

int mi_readdir (const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) 
{
	node* dir = mi_get_destination(path);
	node* son = dir->younger;
	while(son != NULL) 
	{
		
		filler(buf, son->name, NULL, 0);
		son = son->older_to;
	}
	return 0;
}
