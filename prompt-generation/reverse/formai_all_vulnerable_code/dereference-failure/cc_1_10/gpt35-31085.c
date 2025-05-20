//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define PATH_SIZE 200
#define NAME_SIZE 100

void print_usage() {
    printf("Usage: disk-analyzer <directory_path> <max_depth>\n");
}

void analyze_directory(char* path, int depth, int max_depth) {
    DIR* dir;
    struct dirent* entry;
    struct stat file_stat;
    char sub_path[PATH_SIZE];
    char file_name[NAME_SIZE];
    long long int total_size = 0;
    int num_files = 0;

    dir = opendir(path);
    if (!dir) {
        printf("Failed to open directory %s: %s\n", path, strerror(errno));
        return;
    }

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 &&
                strcmp(entry->d_name, "..") != 0 && depth < max_depth) {
            // Recursively analyze subdirectories
            snprintf(sub_path, PATH_SIZE, "%s/%s", path, entry->d_name);
            analyze_directory(sub_path, depth + 1, max_depth);
        }
        else if (entry->d_type == DT_REG) {
            // Analyze regular files
            snprintf(sub_path, PATH_SIZE, "%s/%s", path, entry->d_name);
            strncpy(file_name, entry->d_name, NAME_SIZE);
            if (stat(sub_path, &file_stat) == 0) {
                long long int size = file_stat.st_size;
                total_size += size;
                num_files++;
            }
            else {
                printf("Failed to get file stats for file %s: %s\n",
                        sub_path, strerror(errno));
            }
        }
    }

    printf("Directory: %s\n", path);
    printf("Number of files: %d\n", num_files);
    printf("Total size: %lld bytes\n\n", total_size);

    closedir(dir);
}

int main(int argc, char* argv[]) {
    char* dir_path;
    int max_depth;

    if (argc != 3) {
        print_usage();
        return 1;
    }

    dir_path = argv[1];
    max_depth = atoi(argv[2]);

    printf("Starting disk analyzer...\n\n");

    analyze_directory(dir_path, 0, max_depth);

    printf("Disk analysis complete.\n");

    return 0;
}