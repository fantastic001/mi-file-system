
#include "context.h"
#include "interface.h"

mi_context* mi_get_context() 
{
	return (mi_context*) fuse_get_context()->private_data;
}

void mi_init_context(memory* mem) 
{
	fuse_get_context()->private_data = new mi_context;
	mi_get_context()->mem = mem;
	mi_get_context()->mem->initialize_mem();
	node* root = mi_get_context()->mem->create_root();
	mi_get_context()->root = root;
	mi_get_context()->curr = mi_get_context()->root;
	mi_get_context()->comm = new commands();
}

node* mi_get_destination(const char* path) 
{
	mi_log("Getting destination for ");
	mi_log(path);
	mi_log("\n");
	if (strlen(path) == 1) return mi_get_context()->root;
	else 
	{
		char base[256];
		char name[64]; 
		mi_split_path(path, base, name);
		node* curr = mi_get_destination(base);
		if (curr == NULL) return NULL;
		else 
		{
			
			bool found = false;
			node* nxt = curr->younger;
			mi_log("Trying to match with ");
			mi_log(name);
			mi_log("\n");
			while (nxt != NULL && !found)
			{
				mi_log(nxt->name);
				if (!strcmp(nxt->name, name)) {
					mi_log(" found");
					found = true;
					return nxt;
				}
				mi_log("\n");
				nxt = nxt->older_to;
			}
			if (!found) return NULL;
		}
	}
	return NULL;
}

void mi_split_path(const char* path, char* basename, char* name)
{
	int i = 0;
	while (path[i] != '\0') i++;
	
	if (i > 1) // ommit on the end of path (e.g. "/path/a/" becomes "/path/a" but "/" stays "/")
	{
		while (path[i-1] == '/') 
		{
			i--;
		}
	}
	int len=i;
	i--;

	while (path[i] != '/') i--;
	int baselen = i;
	int j;
	for (j = 0; j<=baselen; j++) basename[j] = path[j];
	basename[j] = '\0';
	i++;
	int l = 0;
	while (path[i] != '\0' && path[i] != '/') 
	{
		name[l] = path[i];
		i++; l++;
	}
	name[l] = '\0';
}
