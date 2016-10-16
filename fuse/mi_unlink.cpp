#include "interface.h"
#include "context.h"

int mi_unlink(const char * name) 
{
    node *nod = mi_get_destination(name);
    if (nod == NULL) return -ENOENT;
    if (nod->folder) return -EISDIR;
    mi_get_context()->mem->delete_node(nod);
    return 0;
}
