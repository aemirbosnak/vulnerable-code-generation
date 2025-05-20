//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path);
void print_usage();
void accumulate_sizes(const char *file_path, long long *total_size, int *file_count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);
    return EXIT_SUCCESS;
}

void print_usage() {
    printf("Usage: disk_space_analyzer <directory_path>\n");
    printf("Analyzes the specified directory and outputs the space usage summary.\n");
}

void analyze_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    char file_path[MAX_PATH];
    long long total_size = 0;
    int file_count = 0;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') { // Skip hidden files and current/parent directories
            continue;
        }

        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
        accumulate_sizes(file_path, &total_size, &file_count);
    }

    closedir(dir);
    
    printf("Total files analyzed: %d\n", file_count);
    printf("Total size used: %lld bytes\n", total_size);
}

void accumulate_sizes(const char *file_path, long long *total_size, int *file_count) {
    struct stat file_info;

    if (stat(file_path, &file_info) == -1) {
        perror("Could not get file information");
        return;
    }

    if (S_ISREG(file_info.st_mode)) { // Regular file
        *total_size += file_info.st_size;
        (*file_count)++;
    } else if (S_ISDIR(file_info.st_mode)) { // Directory, recurse into it
        analyze_directory(file_path);
    }
}