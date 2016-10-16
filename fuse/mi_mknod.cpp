
#include "interface.h"
#include "context.h"

int mi_mknod(const char* name, mode_t mode, dev_t dev)
{
    mi_log(name);
    mi_log("mknod()\n");

    char base[256] = {0};
    char fn[256] = {0};

    mi_split_path(name, base, fn);
    

    mi_context* ctx = mi_get_context();   
    node* folder = mi_get_destination(base);
    node * nxt = ctx->mem->create_node(
            const_cast<char*>(fn), 
            false,
            folder,
            folder,
            folder->younger);
    folder->younger = nxt;
    return 0;
}
