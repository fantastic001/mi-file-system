
#include "interface.h"
#include <sys/stat.h>

int mi_getattr(const char *path, struct stat * fstat) 
{
	mi_log("getattr()\n");
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
