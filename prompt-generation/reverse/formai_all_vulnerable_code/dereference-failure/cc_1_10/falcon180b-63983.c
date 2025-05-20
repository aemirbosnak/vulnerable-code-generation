//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long int size;
    unsigned long long int used;
    unsigned long long int free;
} Directory;

void getDirSize(char* path, Directory* dir) {
    DIR* dp;
    struct dirent* dirp;
    struct statvfs buf;

    dp = opendir(path);
    if (dp == NULL) {
        perror("");
        exit(1);
    }

    dir->size = 0;
    dir->used = 0;
    dir->free = 0;

    while ((dirp = readdir(dp))!= NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;

        char fullPath[MAX_PATH];
        strcat(fullPath, path);
        strcat(fullPath, "/");
        strcat(fullPath, dirp->d_name);

        if (statvfs(fullPath, &buf)!= 0) {
            perror("");
            exit(1);
        }

        dir->size += buf.f_blocks * buf.f_frsize;
        dir->used += buf.f_blocks - buf.f_bfree;
        dir->free += buf.f_bfree;
    }

    closedir(dp);
}

void printDir(Directory dir) {
    printf("Path: %s\n", dir.path);
    printf("Size: %llu bytes\n", dir.size);
    printf("Used: %llu bytes\n", dir.used);
    printf("Free: %llu bytes\n\n", dir.free);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    Directory dir;
    strcpy(dir.path, argv[1]);

    getDirSize(dir.path, &dir);
    printDir(dir);

    return 0;
}