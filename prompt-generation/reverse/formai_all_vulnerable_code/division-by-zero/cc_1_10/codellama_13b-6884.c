//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: safe
// Safe C Disk Space Analyzer Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_PATH_LEN 1024

// Struct to store disk information
typedef struct {
    char* name;
    unsigned long total_size;
    unsigned long free_size;
    unsigned long used_size;
    unsigned long percent_used;
} disk_info_t;

// Function to get disk information
disk_info_t get_disk_info(const char* path) {
    struct statvfs stats;
    disk_info_t info;

    if (statvfs(path, &stats) == -1) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    info.name = strdup(path);
    info.total_size = stats.f_blocks * stats.f_bsize;
    info.free_size = stats.f_bfree * stats.f_bsize;
    info.used_size = stats.f_blocks * stats.f_bsize - stats.f_bfree * stats.f_bsize;
    info.percent_used = (info.used_size * 100) / info.total_size;

    return info;
}

// Function to print disk information
void print_disk_info(disk_info_t* info) {
    printf("Disk: %s\n", info->name);
    printf("Total size: %lu bytes\n", info->total_size);
    printf("Free size: %lu bytes\n", info->free_size);
    printf("Used size: %lu bytes\n", info->used_size);
    printf("Percent used: %lu%%\n", info->percent_used);
}

int main(int argc, char* argv[]) {
    disk_info_t info;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    info = get_disk_info(argv[1]);
    print_disk_info(&info);

    return 0;
}