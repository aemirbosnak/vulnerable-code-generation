//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>
#include <dirent.h>

#define SIZE_UNITS_COUNT 4
#define MAX_PATH_LENGTH 1024

const char *size_units[SIZE_UNITS_COUNT] = {"B", "KB", "MB", "GB"};

void print_size(unsigned long long size) {
    unsigned long long unit = 1;
    int unit_index = 0;

    while (size >= 1024 && unit_index < SIZE_UNITS_COUNT - 1) {
        size /= 1024;
        unit_index++;
    }

    printf("%llu %s\n", size, size_units[unit_index]);
}

void analyze_directory(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("Failed to get file system statistics");
        return;
    }

    unsigned long long total = stat.f_blocks * stat.f_frsize;
    unsigned long long free = stat.f_bfree * stat.f_frsize;
    unsigned long long used = total - free;

    printf("Analyzing Disk Space for: %s\n", path);
    printf("Total Space: ");
    print_size(total);
    printf("Used Space: ");
    print_size(used);
    printf("Free Space: ");
    print_size(free);
    printf("\n");
}

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    printf("Files in directory: %s\n", path);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            printf("- %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void analyze_subdirectories(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR && entry->d_name[0] != '.') {
            char sub_path[MAX_PATH_LENGTH];
            snprintf(sub_path, sizeof(sub_path), "%s/%s", path, entry->d_name);
            analyze_directory(sub_path);
            list_files(sub_path);
            analyze_subdirectories(sub_path); // Recursively analyze subdirectories
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);
    list_files(argv[1]);
    analyze_subdirectories(argv[1]);

    return EXIT_SUCCESS;
}