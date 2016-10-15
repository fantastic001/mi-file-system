
#include "interface.h"
#include "context.h"


int mi_mkdir(const char *path, mode_t mode) 
{
	mi_log("mkdir()");
	mi_log(path);
	mi_log("\n");
	char base[256];
	char name[64];
	mi_split_path(path, base, name);
	node* curr = mi_get_destination(base);
	bool found = false;
	node* nxt = curr->younger;
	while (nxt != NULL && !found)
	{
			if (!strcmp(nxt->name, name))
				found = true;
			nxt = nxt->older_to;
	}

	if (found) return 0;
	else
	{
		node* nxt = mi_get_context()->mem->create_node(name, true, curr, curr, curr->younger);
		curr->younger = nxt;
	}
	return 0;
}
