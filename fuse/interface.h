

#ifndef MI_FILESYSTEM_FUSE_INTERFACE_H
#define MI_FILESYSTEM_FUSE_INTERFACE_H

#include <fuse.h>
#include <fcntl.h>


int mi_getattr(const char *, struct stat *);
int mi_mkdir(const char *, mode_t);
int mi_rmdir(const char *);
int mi_rename(const char *, const char *);
int mi_open(const char *, struct fuse_file_info *);
int mi_read (const char *, char *, size_t, off_t, struct fuse_file_info *); 
int mi_write (const char *, const char *, size_t, off_t, struct fuse_file_info *);
int mi_opendir (const char *, struct fuse_file_info *) 
int mi_readdir (const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *)
int mi_init(struct fuse_conn_info *conn);
int mi_create(const char *, mode_t, struct fuse_file_info *);

#endif // MI_FILESYSTEM_FUSE_INTERFACE_H
