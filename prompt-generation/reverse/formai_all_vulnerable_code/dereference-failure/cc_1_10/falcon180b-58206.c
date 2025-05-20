//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char path[1024];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
} disk_info_t;

void analyze_directory(const char* path, disk_info_t* disk_info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s\n", path);
        exit(1);
    }

    disk_info->total_space = 0;
    disk_info->used_space = 0;
    disk_info->free_space = 0;

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char full_path[1024];
        snprintf(full_path, 1024, "%s/%s", path, entry->d_name);

        struct statvfs statvfs_info;
        if (statvfs(full_path, &statvfs_info) == -1) {
            fprintf(stderr, "Error getting statvfs info for %s\n", full_path);
            continue;
        }

        disk_info->total_space += statvfs_info.f_blocks * statvfs_info.f_frsize;
        disk_info->used_space += statvfs_info.f_blocks - statvfs_info.f_bfree;
        disk_info->free_space += statvfs_info.f_bfree * statvfs_info.f_frsize;
    }

    closedir(dir);
}

void print_disk_info(disk_info_t* disk_info) {
    printf("Path: %s\n", disk_info->path);
    printf("Total space: %llu bytes\n", disk_info->total_space);
    printf("Used space: %llu bytes\n", disk_info->used_space);
    printf("Free space: %llu bytes\n", disk_info->free_space);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    disk_info_t disk_info;
    strncpy(disk_info.path, argv[1], 1024);
    analyze_directory(disk_info.path, &disk_info);
    print_disk_info(&disk_info);

    return 0;
}