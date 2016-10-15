
#include "interface.h"

int mi_rmdir(const char *path) 
{
	mi_log("rmdir() ");
	mi_log(path);
	mi_log("\n");
	return 1;
}
