
#include "interface.h"
#include "context.h"
#include <sys/stat.h>

int mi_readdir (const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) 
{
	mi_log(path);
	mi_log(" readdir()\n");
	node* dir = mi_get_destination(path);
	mi_log("Directory name: ");
	mi_log(dir->name);
	node* son = dir->younger;
	while(son != NULL) 
	{
		
		filler(buf, son->name, NULL, 0);
		son = son->older_to;
	}
	filler(buf, ".", NULL, 0);
	filler(buf, "..", NULL, 0);
	return 0;
}
