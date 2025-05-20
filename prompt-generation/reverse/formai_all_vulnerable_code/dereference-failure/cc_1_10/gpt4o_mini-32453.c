//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_info;
    char full_path[MAX_PATH];
    long total_size = 0;

    DIR *directory = opendir(dir_path);
    if (!directory) {
        perror("Unable to open directory");
        return; // Exit function if directory cannot be opened
    }

    printf("\n--- Analyzing Directory: %s ---\n", dir_path);
    printf("%-30s %10s\n", "File Name", "Size (bytes)");
    printf("------------------------------------------\n");

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            if (stat(full_path, &file_info) == 0) {
                printf("%-30s %10ld\n", entry->d_name, file_info.st_size);
                total_size += file_info.st_size;
            } else {
                perror("Could not get file info");
            }
        }
    }
    
    closedir(directory);
    printf("\nTOTAL SIZE OF FILES: %ld bytes\n", total_size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyze_directory(argv[1]);

    return 0;
}