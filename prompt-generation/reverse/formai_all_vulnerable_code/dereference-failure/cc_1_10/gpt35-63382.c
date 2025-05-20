//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

int main(int argc, char* argv[]) {
    // check for directory argument
    if (argc != 2) {
        printf("Usage: disk-space-analyzer <directory>\n");
        return 0;
    }

    // get directory path
    char* dir_path = argv[1];
    DIR* dir = opendir(dir_path);
    if (!dir) {
        printf("Error: Unable to open directory %s.\n", dir_path);
        return 0;
    }

    struct dirent* entry;
    char file_path[1024];
    struct stat file_stats;
    unsigned long long total_size = 0;
    unsigned long long direct_size = 0;
    unsigned long long indirect_size = 0;
    int file_count = 0;
    while ((entry = readdir(dir)) != NULL) {
        // ignore . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // create full file path
        sprintf(file_path, "%s/%s", dir_path, entry->d_name);

        // get file stats
        if (stat(file_path, &file_stats) != 0) {
            printf("Error: Unable to get stats for file %s.\n", entry->d_name);
            continue;
        }

        unsigned long long file_size = (unsigned long long)file_stats.st_size;
        total_size += file_size;
        file_count += 1;

        // check if file is a directory
        if (S_ISDIR(file_stats.st_mode)) {
            indirect_size += file_size;
        } else {
            direct_size += file_size;
        }
    }

    closedir(dir);

    // print results
    printf("Total size: %.2f GB\n", (double)total_size/GB);
    printf("Direct size: %.2f GB\n", (double)direct_size/GB);
    printf("Indirect size: %.2f GB\n", (double)indirect_size/GB);
    printf("File count: %d\n", file_count);

    return 0;
}