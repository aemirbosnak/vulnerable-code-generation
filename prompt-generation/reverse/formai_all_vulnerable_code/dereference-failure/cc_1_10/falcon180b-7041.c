//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
} disk_info;

void get_disk_info(disk_info* disk, const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf)!= 0) {
        printf("Error getting disk info for %s\n", path);
        exit(1);
    }

    disk->total_space = buf.f_blocks * buf.f_frsize;
    disk->used_space = buf.f_blocks - buf.f_bfree;
    disk->free_space = buf.f_bavail * buf.f_frsize;

    strncpy(disk->path, path, MAX_PATH);
}

void print_disk_info(disk_info* disk) {
    printf("Path: %s\n", disk->path);
    printf("Total Space: %llu bytes\n", disk->total_space);
    printf("Used Space: %llu bytes\n", disk->used_space);
    printf("Free Space: %llu bytes\n", disk->free_space);
    printf("\n");
}

void print_header() {
    printf("Path\tTotal Space\tUsed Space\tFree Space\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    disk_info disk;
    get_disk_info(&disk, argv[1]);

    print_header();
    print_disk_info(&disk);

    return 0;
}