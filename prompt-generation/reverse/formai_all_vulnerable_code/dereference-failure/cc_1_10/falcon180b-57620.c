//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

typedef struct {
    char path[1024];
    struct statvfs stat;
} fs_info;

void get_filesystem_info(char* path, fs_info* info) {
    if (statvfs(path, &info->stat) == -1) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }
    strncpy(info->path, path, 1024);
}

void print_filesystem_info(fs_info* info) {
    printf("Path: %s\n", info->path);
    printf("Total space: %ld bytes\n", info->stat.f_blocks * info->stat.f_frsize);
    printf("Available space: %ld bytes\n", info->stat.f_bavail * info->stat.f_frsize);
    printf("Used space: %ld bytes\n", (info->stat.f_blocks - info->stat.f_bavail) * info->stat.f_frsize);
}

void scan_directory(char* path, fs_info* info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        char subpath[1024];
        strncpy(subpath, path, 1024);
        strncat(subpath, "/", 1024);
        strncat(subpath, ent->d_name, 1024);

        fs_info subinfo;
        get_filesystem_info(subpath, &subinfo);
        print_filesystem_info(&subinfo);
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    fs_info info;
    get_filesystem_info(argv[1], &info);
    print_filesystem_info(&info);

    scan_directory(argv[1], &info);

    return 0;
}