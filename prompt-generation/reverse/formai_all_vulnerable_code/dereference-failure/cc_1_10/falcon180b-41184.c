//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char path[MAX_PATH_LEN];
    long long size;
    long long num_files;
    long long num_dirs;
} DirectoryStats;

void get_directory_stats(const char* path, DirectoryStats* stats) {
    DIR* dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Error: could not open directory '%s'\n", path);
        exit(1);
    }

    stats->size = 0;
    stats->num_files = 0;
    stats->num_dirs = 0;

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            stats->num_files++;
        } else if (ent->d_type == DT_DIR) {
            stats->num_dirs++;
        }

        char full_path[MAX_PATH_LEN];
        snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, ent->d_name);

        struct stat st;
        if (stat(full_path, &st) == 0) {
            stats->size += st.st_size;
        }
    }

    closedir(dir);
}

void print_directory_stats(const DirectoryStats* stats) {
    printf("Path: %s\n", stats->path);
    printf("Size: %lld bytes\n", stats->size);
    printf("Files: %d\n", stats->num_files);
    printf("Directories: %d\n", stats->num_dirs);
    printf("\n");
}

void analyze_directory(const char* path) {
    DirectoryStats stats;
    get_directory_stats(path, &stats);
    print_directory_stats(&stats);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}