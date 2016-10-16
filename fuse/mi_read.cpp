
#include "interface.h"
#include "context.h"

int mi_read (const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) 
{
        int oldsize = size;
        int readed = 0; // znam da je nepravilno ali ne moze read
        node *curr = mi_get_destination(path);
        memory *part = mi_get_context()->mem;
	mi_log("\nread(%s, **, %i, %i, **): '", path, size, offset);
        if (curr->folder) return -EISDIR;
    
        int frsz = fr_mem * 1024 - 2 - 4; // fr_mem - sizeof(short) - sizeof(int);
        int from_fr = curr->start;
        int sz = curr->sizeB;

        while (from_fr != 0 && sz)
        {
            for (int i = 0; i < frsz && sz; i++)
            {
                if (offset) --offset;
                else 
                {
                    *buf = *((char*)(part->mem[from_fr] + 2 + i));
                    mi_log("%02x ", *buf);
                    ++buf;
                    ++readed;
                    --size;
                    if (!size) {
                        mi_log("' readed %i\n", readed);
                        return readed;
                    }
                }
                sz--;
            }
    
            from_fr = *((int*)( (char*)(part->mem[from_fr] + fr_mem * 1024 - 4)) );
        }
        mi_log("' readed [eof] %i\n", readed);
        return 0;
}
