
#ifndef MI_FILESYSTEM_FUSE_INTERFACE_H
#define MI_FILESYSTEM_FUSE_INTERFACE_H

#include <fuse.h>
#include <fcntl.h>

#include <fstream>

//void mi_log(const char*);

#define mi_log(...) { \
    FILE* f = fopen("/home/stefan/log.log", "a"); \
    fprintf(f, __VA_ARGS__); \
    fclose(f); \
}

int mi_getattr(const char *, struct stat *);
int mi_mkdir(const char *, mode_t);
int mi_mknod(const char *, mode_t, dev_t);
int mi_rmdir(const char *);
int mi_rename(const char *, const char *);
int mi_open(const char *, struct fuse_file_info *);
int mi_read (const char *, char *, size_t, off_t, struct fuse_file_info *); 
int mi_write (const char *, const char *, size_t, off_t, struct fuse_file_info *);
int mi_opendir (const char *, struct fuse_file_info *);
int mi_readdir (const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);
void* mi_init(struct fuse_conn_info *conn);
int mi_utimens(const char *name, const struct timespec tv[2]);
int mi_unlink(const char *);

#endif // MI_FILESYSTEM_FUSE_INTERFACE_H
