//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct DirStats {  // Struct to hold directory stats
    char name[256]; // Directory name
    long size;      // Size in bytes
};

typedef struct DirStats DirStats;

// Function prototypes
int compareDirStats(const void *a, const void *b);
int getDirStats(char *dir_name, DirStats *stats);

int main(int argc, char *argv[]) {
    // Check if directory name is provided
    if (argc < 2) {
        printf("Usage: %s <directory name>\n", argv[0]);
        return 1;
    }

    // Get directory stats
    DirStats stats[1000];
    int num_dirs = getDirStats(argv[1], stats);

    // Sort directory stats by size
    qsort(stats, num_dirs, sizeof(DirStats), compareDirStats);

    // Print directory stats
    printf("Directory Name\t\tSize (Bytes)\n");
    for (int i = 0; i < num_dirs; i++) {
        printf("%-30s\t%ld\n", stats[i].name, stats[i].size);
    }

    return 0;
}

// Compare function for sorting directory stats by size
int compareDirStats(const void *a, const void *b) {
    DirStats *dir1 = (DirStats *)a;
    DirStats *dir2 = (DirStats *)b;

    if (dir1->size > dir2->size) {
        return -1;
    } else if (dir1->size < dir2->size) {
        return 1;
    } else {
        return 0;
    }
}

// Recursive function to get directory stats
int getDirStats(char *dir_name, DirStats *stats) {
    DIR *dir = opendir(dir_name);

    if (dir == NULL) { // Unable to open directory
        printf("Unable to open directory %s\n", dir_name);
        return 0;
    }

    // Iterate through files and directories in current directory
    struct dirent *entry;
    int num_dirs = 0;
    while ((entry = readdir(dir)) != NULL) {
        char path[256];
        strcpy(path, dir_name);
        strcat(path, "/");
        strcat(path, entry->d_name);

        struct stat file_stat;
        if (stat(path, &file_stat) == -1) { // Unable to get file stats
            printf("Unable to get stats for %s\n", path);
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) { // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // Ignore "." and ".."
                strcpy(stats[num_dirs].name, entry->d_name);
                stats[num_dirs].size = 0;

                // Recursively get directory stats for subdirectories
                int num_subdirs = getDirStats(path, &stats[num_dirs]);
                stats[num_dirs].size += file_stat.st_size;
                for (int i = 0; i < num_subdirs; i++) {
                    stats[num_dirs].size += stats[num_dirs + i + 1].size;
                }

                num_dirs += num_subdirs + 1; // Increment number of directories
            }
        } else { // File
            stats[num_dirs].size += file_stat.st_size;
        }
    }

    closedir(dir);

    return num_dirs;
}