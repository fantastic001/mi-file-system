
#include "interface.h"
#include "context.h"

int mi_opendir (const char *path, struct fuse_file_info *fi) 
{
	mi_get_context()->curr = mi_get_destination(path);
	return 0;
}
