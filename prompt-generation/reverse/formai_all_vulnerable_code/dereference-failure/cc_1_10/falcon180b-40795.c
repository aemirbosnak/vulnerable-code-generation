//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    size_t size;
    size_t used;
    size_t available;
    size_t percentage;
} disk_info;

void get_disk_space(disk_info *info, const char *path) {
    struct statvfs sv;
    if (statvfs(path, &sv)!= 0) {
        fprintf(stderr, "Error: could not get disk space for %s\n", path);
        exit(1);
    }
    info->size = sv.f_blocks * sv.f_frsize;
    info->used = sv.f_blocks - sv.f_bfree;
    info->available = sv.f_bfree * sv.f_frsize;
    info->percentage = (info->used * 100) / info->size;
}

void print_disk_info(disk_info *info) {
    printf("Path: %s\n", info->path);
    printf("Total size: %zu bytes\n", info->size);
    printf("Used space: %zu bytes\n", info->used);
    printf("Available space: %zu bytes\n", info->available);
    printf("Percentage used: %zu%%\n\n", info->percentage);
}

void print_header() {
    printf("Path\tTotal\tUsed\tAvailable\tPercentage\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }
    char path[MAX_PATH];
    strcpy(path, argv[1]);
    disk_info info;
    get_disk_space(&info, path);
    print_disk_info(&info);
    return 0;
}