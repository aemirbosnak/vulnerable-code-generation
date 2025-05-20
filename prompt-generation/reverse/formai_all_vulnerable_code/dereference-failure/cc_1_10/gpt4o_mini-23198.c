//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_size_in_human_readable_format(long size) {
    const char *units[] = { "B", "KB", "MB", "GB", "TB" };
    int unit_index = 0;
    double human_size = (double)size;

    while (human_size >= 1024 && unit_index < 4) {
        human_size /= 1024;
        unit_index++;
    }
    
    printf("%.2f %s\n", human_size, units[unit_index]);
}

void analyze_directory(const char *path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp;
    long total_size = 0;
    long file_count = 0;

    dp = opendir(path);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char full_path[MAX_PATH];

        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) { // Regular file
                total_size += file_stat.st_size;
                file_count++;
            }
        } else {
            perror("Could not get file stats");
        }
    }

    closedir(dp);
    
    printf("Directory: %s\n", path);
    printf("---------------------------\n");
    printf("Total files: %ld\n", file_count);
    printf("Total size: ");
    print_size_in_human_readable_format(total_size);
    printf("---------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 1) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(1);
    }

    const char *directory = (argc == 2) ? argv[1] : ".";

    analyze_directory(directory);
    
    return 0;
}