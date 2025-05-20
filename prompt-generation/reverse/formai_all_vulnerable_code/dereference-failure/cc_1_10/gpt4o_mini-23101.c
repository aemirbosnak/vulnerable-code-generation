//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path);
void print_usage();

long total_size = 0;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *dir_path = argv[1];
    analyze_directory(dir_path);

    printf("\nTotal disk space used in '%s': %.2f MB\n", dir_path, total_size / (1024.0 * 1024.0));
    return EXIT_SUCCESS;
}

void analyze_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_stats;
    DIR *dir = opendir(dir_path);

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current and parent directories
        }

        if (stat(full_path, &file_stats) < 0) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(file_stats.st_mode)) {
            // It's a directory, analyze it recursively
            analyze_directory(full_path);
        } else {
            // It's a file, add its size
            total_size += file_stats.st_size;
            printf("File: %s, Size: %.2f MB\n", full_path, file_stats.st_size / (1024.0 * 1024.0));
        }
    }

    closedir(dir);
}

void print_usage() {
    fprintf(stderr, "Usage: ./disk_space_analyzer <directory_path>\n");
    fprintf(stderr, "Analyze disk space used by files in the given directory.\n");
}