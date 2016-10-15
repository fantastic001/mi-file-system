
#include "interface.h"
#include "context.h"

int mi_opendir (const char *path, struct fuse_file_info *fi) 
{
	mi_log("opendir() ");
	mi_log(path);
	mi_log("\n");
	mi_get_context()->curr = mi_get_destination(path);
	return 0;
}
