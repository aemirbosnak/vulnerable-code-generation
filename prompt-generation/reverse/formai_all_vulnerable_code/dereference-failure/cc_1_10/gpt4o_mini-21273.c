//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <unistd.h>

#define SIZE_UNIT_COUNT 4
const char *size_units[SIZE_UNIT_COUNT] = {"B", "KB", "MB", "GB"};

void display_disk_usage(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("statvfs");
        return;  // Error happened
    }

    unsigned long total = stat.f_frsize * stat.f_blocks;
    unsigned long free = stat.f_frsize * stat.f_bfree;
    unsigned long available = stat.f_frsize * stat.f_bavail;
    unsigned long used = total - free;

    // Calculate size in human-readable format
    int size_unit = 0;
    while (total >= 1024 && size_unit < SIZE_UNIT_COUNT - 1) {
        total /= 1024;
        used /= 1024;
        free /= 1024;
        available /= 1024;
        size_unit++;
    }

    printf("\nDisk Usage for %s:\n", path);
    printf("Total Space: %lu %s\n", total, size_units[size_unit]);
    printf("Used Space : %lu %s\n", used, size_units[size_unit]);
    printf("Free Space : %lu %s\n", free, size_units[size_unit]);
    printf("Available Space: %lu %s\n", available, size_units[size_unit]);
}

void analyze_directory(const char *path, int *file_count, long long *total_size) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        return;  // Error opening directory
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {  // Regular file
            (*file_count)++;
            char filepath[1024];
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
            FILE *f = fopen(filepath, "rb");
            if (f) {
                fseek(f, 0, SEEK_END);
                *total_size += ftell(f);
                fclose(f);
            } else {
                perror("fopen");
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char subdir[1024];
            snprintf(subdir, sizeof(subdir), "%s/%s", path, entry->d_name);
            analyze_directory(subdir, file_count, total_size);
        }
    }
    closedir(dp);
}

void display_directory_info(const char *path) {
    int file_count = 0;
    long long total_size = 0;

    analyze_directory(path, &file_count, &total_size);

    // Calculate size in human-readable format
    int size_unit = 0;
    while (total_size >= 1024 && size_unit < SIZE_UNIT_COUNT - 1) {
        total_size /= 1024;
        size_unit++;
    }

    printf("\nDirectory Analysis for %s:\n", path);
    printf("Total Files: %d\n", file_count);
    printf("Total Size  : %lld %s\n", total_size, size_units[size_unit]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    display_disk_usage(path);
    display_directory_info(path);

    return EXIT_SUCCESS;
}