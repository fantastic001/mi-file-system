
#include "interface.h"
#include "context.h"
#include <sys/stat.h>

int mi_getattr(const char *path, struct stat * fstat) 
{
	mi_log("getattr() ");
	mi_log(path);
	mi_log("\n");
	char base[256] = {0};
	char name[64] = {0};
	mi_split_path(path, base, name);
	node* curr = mi_get_destination(path);
	if (curr == NULL) return -ENOENT;

	mi_get_stat(curr, fstat);

	return 0;
	//return stat("/home/stefan/", fstat);
}
