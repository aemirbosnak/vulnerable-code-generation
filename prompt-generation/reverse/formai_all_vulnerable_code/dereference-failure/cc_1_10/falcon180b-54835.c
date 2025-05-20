//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    size_t size;
    size_t files;
    size_t directories;
} DirectoryStats;

void get_directory_stats(const char* path, DirectoryStats* stats) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            stats->directories++;
        } else {
            stats->files++;
        }
    }

    closedir(dir);

    stats->size = 0;
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        stats->size = buf.f_blocks * buf.f_frsize;
    }
}

void print_directory_stats(const char* path, const DirectoryStats* stats) {
    printf("Path: %s\n", path);
    printf("Size: %zu bytes\n", stats->size);
    printf("Files: %zu\n", stats->files);
    printf("Directories: %zu\n", stats->directories);
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    DirectoryStats stats;
    get_directory_stats(argv[1], &stats);
    print_directory_stats(argv[1], &stats);

    return 0;
}