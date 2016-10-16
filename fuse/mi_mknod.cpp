
#include "interface.h"
#include "context.h"

int mi_mknod(const char* path, mode_t mode, dev_t dev)
{
    mi_log(path);
    mi_log("mknod()\n");

    char base[256] = {0};
    char fn[256] = {0};

    mi_split_path(path, base, fn);
    

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
