
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
	node* curr = mi_get_destination(base);
	mi_log("Base: ");
	mi_log(base);
	mi_log(" Name: ");
	mi_log(name);
	mi_log("\n");
	if (strlen(base) == 0) {
		curr = mi_get_context()->root;
		mi_log("Replacing root\n");
	}
	if (strlen(name) > 0) 
	{
		
		bool found = false;
		node* nxt = curr->younger;
		while (nxt != NULL && !found)
		{
			if (!strcmp(nxt->name, name))
				found = true;
			nxt = nxt->older_to;
		}
		if (!found) return -ENOENT;
	}
	if (curr == NULL) return -ENOENT;




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
