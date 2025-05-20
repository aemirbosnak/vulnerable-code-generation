//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define BLOCK_SIZE 1024

void display_usage() {
    printf("Usage: ./disk_space_analyzer <directory_path>\n");
}

void analyze_directory(const char* dir_path) {
    struct statvfs stat;

    // Get filesystem statistics
    if (statvfs(dir_path, &stat) != 0) {
        perror("statvfs");
        return;
    }

    // Calculate total and free space in GB
    unsigned long total_size = (stat.f_blocks * stat.f_frsize) / (BLOCK_SIZE * BLOCK_SIZE);
    unsigned long free_size = (stat.f_bfree * stat.f_frsize) / (BLOCK_SIZE * BLOCK_SIZE);
    unsigned long used_size = total_size - free_size;

    printf("Analyzing directory: %s\n", dir_path);
    printf("Total Size: %lu GB\n", total_size);
    printf("Used Size: %lu GB\n", used_size);
    printf("Free Size: %lu GB\n\n", free_size);
}

void list_files(const char* dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Files in directory: %s\n", dir_path);
    while ((entry = readdir(dp)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
    printf("\n");
}

void analyze_directory_and_list(const char* dir_path) {
    analyze_directory(dir_path);
    list_files(dir_path);
}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char* dir_path = argv[1];

    // Analyze the provided directory and list files
    analyze_directory_and_list(dir_path);

    return EXIT_SUCCESS;
}