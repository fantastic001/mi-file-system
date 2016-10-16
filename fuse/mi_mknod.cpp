
#include "interface.h"
#include "context.h"

int mi_mknod(const char* path, mode_t mode, dev_t dev)
{
    mi_context* ctx = mi_get_context();   
    char base[256];
    char name[64];
    mi_split_path(path, base, name);
    node* curr = mi_get_destination(base);
    node * nxt = ctx->mem->create_node(
            const_cast<char*>(name), 
            false,
            curr,
            curr,
            curr->younger);
    curr->younger = nxt;
    return 0;
}
