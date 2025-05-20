//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
    unsigned long long used;
    unsigned long long free;
} Directory;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    Directory dir;
    strncpy(dir.path, argv[1], MAX_PATH);

    unsigned long long total = 0, used = 0, free = 0;

    DIR *d;
    struct dirent *dirp;
    d = opendir(dir.path);
    if (d) {
        while ((dirp = readdir(d))!= NULL) {
            if (dirp->d_type == DT_DIR) {
                char path[MAX_PATH];
                sprintf(path, "%s/%s", dir.path, dirp->d_name);
                struct statvfs stv;
                if (statvfs(path, &stv) == 0) {
                    total += stv.f_blocks * stv.f_frsize;
                    used += stv.f_blocks - stv.f_bavail;
                    free += stv.f_bavail * stv.f_frsize;
                }
            }
        }
        closedir(d);
    }

    dir.size = total;
    dir.used = used;
    dir.free = free;

    printf("Directory: %s\n", dir.path);
    printf("Total size: %llu bytes\n", dir.size);
    printf("Used space: %llu bytes\n", dir.used);
    printf("Free space: %llu bytes\n", dir.free);

    return 0;
}