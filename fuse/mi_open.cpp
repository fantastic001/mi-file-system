
#include "interface.h"
#include "context.h"

int mi_open(const char *path, struct fuse_file_info *fi) 
{
	mi_log("open() ");
	mi_log(path);
	mi_log("\n");
        node* nod = mi_get_destination(path);
        if (nod == NULL) return -ENOENT;
        fi->fh = (uint64_t)nod;
        return 0;
}
