//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
/* This is a disk space analyzer program in C. It reads the directory structure of a given path and prints out the total size of the directory and all its subdirectories. */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char path[BUFFER_SIZE];
    off_t size;
} Directory;

void read_directory(const char* path, Directory* dir) {
    DIR *dp;
    struct dirent *dirp;
    struct statvfs buf;

    dp = opendir(path);

    if (dp!= NULL) {
        if (statvfs(path, &buf) == 0) {
            dir->size = buf.f_blocks * buf.f_frsize;
        } else {
            dir->size = 0;
        }

        while ((dirp = readdir(dp))!= NULL) {
            strcpy(dir->path, path);
            strcat(dir->path, "/");
            strcat(dir->path, dirp->d_name);

            if (dirp->d_type == DT_DIR) {
                Directory subdir;
                read_directory(dir->path, &subdir);
                dir->size += subdir.size;
            }
        }

        closedir(dp);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    Directory dir;
    read_directory(argv[1], &dir);

    printf("Total size of '%s': %lld bytes\n", argv[1], dir.size);

    return 0;
}