//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024

void analyze_directory(const char *path, unsigned long long *total_size, unsigned long long *total_files);
void display_results(const char *path, unsigned long long total_size, unsigned long long total_files);

int main(int argc, char *argv[]) {
    char *path;
    unsigned long long total_size = 0;
    unsigned long long total_files = 0;

    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    path = argv[1];
    analyze_directory(path, &total_size, &total_files);
    display_results(path, total_size, total_files);

    return EXIT_SUCCESS;
}

void analyze_directory(const char *path, unsigned long long *total_size, unsigned long long *total_files) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    char full_path[MAX_PATH_LENGTH];
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        struct statvfs stat;
        if (statvfs(full_path, &stat) == 0) {
            *total_size += (unsigned long long)stat.f_frsize * stat.f_blocks;
            (*total_files)++;
        }

        if (entry->d_type == DT_DIR) {
            analyze_directory(full_path, total_size, total_files);
        } else {
            FILE *file = fopen(full_path, "rb");
            if (file) {
                fseek(file, 0, SEEK_END);
                unsigned long long file_size = ftell(file);
                fclose(file);
                *total_size += file_size;
            }
        }
    }

    closedir(dp);
}

void display_results(const char *path, unsigned long long total_size, unsigned long long total_files) {
    printf("\nDisk Space Analysis for Directory: %s\n", path);
    printf("Total Files: %llu\n", total_files);
    printf("Total Size: %llu bytes (%.2f GB)\n", total_size, total_size / (1024.0 * 1024 * 1024));
}

// Additional utility function for easy string formatting
void format_bytes(unsigned long long bytes, char *formatted) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;
    double size = (double)bytes;

    while (size >= 1024 && unit_index < 4) {
        size /= 1024;
        unit_index++;
    }

    snprintf(formatted, 50, "%.2f %s", size, units[unit_index]);
}