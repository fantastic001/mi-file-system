
#include "interface.h"
#include "context.h"

int mi_write (const char *path, const char *buff, size_t size, off_t offset, struct fuse_file_info *fi) 
{
	mi_log("write() ");
	mi_log(path);
	mi_log("\n");
        if (offset != 0) mi_log("e sad jebem li ga ne umem pisat iz sredine\n   - B\n");
        node *curr = mi_get_destination(path);
        memory *part = mi_get_context()->mem;
        part->add_extern_file(
                curr, 
                const_cast<char*>(buff), // obelezavajte ulazne bafere kao const 
                size, 
                curr->start, 
                0);
        return size;
}
