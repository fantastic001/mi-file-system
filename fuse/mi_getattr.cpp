
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
	mi_log(base);
	mi_log(" ");
	mi_log(name);
	mi_log("\n");
	fstat->st_dev = 166;
	fstat->st_ino = 0;
	fstat->st_mode = S_IRWXU | S_IRWXG | S_IRWXO | S_IFDIR;	
	fstat->st_nlink = 1;
	fstat->st_uid = 1000;
	fstat->st_rdev = 0;
	fstat->st_size = 0;
	fstat->st_blksize = 4096;
	fstat->st_blocks = 1;
	//fstat->st_atim = ;
	fstat->st_blocks = 1;
	fstat->st_blocks = 1;
        
	return 0;
	//return stat("/home/stefan/", fstat);
}
