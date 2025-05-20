//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024
#define MAX_DIRECTORIES 256
#define NAME_LENGTH 256

typedef struct {
    char name[NAME_LENGTH];
    unsigned long total;
    unsigned long free;
    unsigned long used;
} DiskSpace;

void analyze_disk_space(const char* path, DiskSpace* disk_space) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("statvfs");
        return;
    }

    disk_space->total = stat.f_blocks * stat.f_frsize;
    disk_space->free = stat.f_bfree * stat.f_frsize;
    disk_space->used = disk_space->total - disk_space->free;
    strncpy(disk_space->name, path, NAME_LENGTH);
}

void print_disk_space(const DiskSpace* disk_space) {
    printf("Disk Space for %s:\n", disk_space->name);
    printf("Total: %lu bytes\n", disk_space->total);
    printf("Free: %lu bytes\n", disk_space->free);
    printf("Used: %lu bytes\n", disk_space->used);
    printf("Usage Percentage: %.2f%%\n", 
           (disk_space->used * 100.0) / disk_space->total);
}

int main(int argc, char* argv[]) {
    char paths[MAX_DIRECTORIES][MAX_PATH];
    DiskSpace disk_spaces[MAX_DIRECTORIES];
    int num_paths = 0;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory1> <directory2> ... <directoryN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Collect paths from command-line arguments
    for (int i = 1; i < argc && i <= MAX_DIRECTORIES; i++) {
        strncpy(paths[num_paths], argv[i], MAX_PATH);
        num_paths++;
    }

    // Analyze disk space for each path
    for (int i = 0; i < num_paths; i++) {
        analyze_disk_space(paths[i], &disk_spaces[i]);
    }

    // Print disk space details
    for (int i = 0; i < num_paths; i++) {
        print_disk_space(&disk_spaces[i]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}