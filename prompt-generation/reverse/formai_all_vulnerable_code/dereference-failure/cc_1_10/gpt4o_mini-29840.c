//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

typedef struct {
    char name[MAX_PATH];
    long size;
} FileInfo;

void print_usage() {
    printf("Usage: disk_space_analyzer <directory_path>\n");
}

void analyze_directory(const char *path, FileInfo *file_list, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    // Store file info
                    strncpy(file_list[*file_count].name, full_path, MAX_PATH);
                    file_list[*file_count].size = file_stat.st_size;
                    (*file_count)++;
                } else if (S_ISDIR(file_stat.st_mode)) {
                    // Recursive call if it's a directory
                    analyze_directory(full_path, file_list, file_count);
                }
            } else {
                perror("Could not get file stats");
            }
        }
    }
    closedir(dir);
}

void print_summary(FileInfo *file_list, int file_count) {
    long total_size = 0;
    printf("\nDisk Space Analyzer Summary:\n");
    printf("------------------------------------------------\n");
    printf("%-50s %10s\n", "File Name", "Size (bytes)");
    printf("------------------------------------------------\n");

    for (int i = 0; i < file_count; i++) {
        printf("%-50s %10ld\n", file_list[i].name, file_list[i].size);
        total_size += file_list[i].size;
    }

    printf("------------------------------------------------\n");
    printf("Total Files Analyzed: %d\n", file_count);
    printf("Total Disk Usage: %ld bytes\n", total_size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    FileInfo file_list[MAX_FILES];
    int file_count = 0;

    // Start analyzing the provided directory
    analyze_directory(argv[1], file_list, &file_count);

    // Print the summary of files found
    print_summary(file_list, file_count);

    return EXIT_SUCCESS;
}