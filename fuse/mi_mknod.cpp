
#include "interface.h"
#include "context.h"

int mi_mknod(const char* name, mode_t mode, dev_t dev)
{
    mi_context* ctx = mi_get_context();   
    node * nxt = ctx->mem->create_node(
            const_cast<char*>(name), 
            false,
            ctx->curr,
            ctx->curr,
            ctx->curr->younger);
    ctx->curr->younger = nxt;
}
