//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MB (1024*1024)

typedef struct {
    char *path;
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
} DiskInfo;

void printDiskInfo(DiskInfo *disk) {
    printf("Path: %s\n", disk->path);
    printf("Total space: %llu MB\n", disk->total_space/MB);
    printf("Used space: %llu MB\n", disk->used_space/MB);
    printf("Free space: %llu MB\n\n", disk->free_space/MB);
}

void getDiskInfo(DiskInfo *disk, const char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        disk->total_space = buf.f_blocks * buf.f_frsize;
        disk->used_space = (buf.f_blocks - buf.f_bfree) * buf.f_frsize;
        disk->free_space = buf.f_bfree * buf.f_frsize;
    } else {
        disk->total_space = 0;
        disk->used_space = 0;
        disk->free_space = 0;
    }
    disk->path = strdup(path);
}

void freeDiskInfo(DiskInfo *disk) {
    free(disk->path);
}

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd))!= NULL) {
        printf("Current working directory: %s\n\n", cwd);
    } else {
        printf("Error: failed to get current working directory\n");
        return 1;
    }

    DiskInfo root_info;
    getDiskInfo(&root_info, "/");
    printDiskInfo(&root_info);
    freeDiskInfo(&root_info);

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("."))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[1024];
                sprintf(path, "%s/%s", cwd, ent->d_name);
                DiskInfo info;
                getDiskInfo(&info, path);
                printDiskInfo(&info);
                freeDiskInfo(&info);
            }
        }
        closedir(dir);
    } else {
        printf("Error: failed to open current directory\n");
        return 1;
    }

    return 0;
}