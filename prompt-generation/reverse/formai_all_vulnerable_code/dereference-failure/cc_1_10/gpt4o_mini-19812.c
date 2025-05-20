//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SPACE_FORMAT "%.2f GB"
#define BUFFER_SIZE 1024

void analyze_directory(const char *path, float *total_space, float *used_space);
void print_usage(const char *path, float total, float used);

int main(int argc, char *argv[]) {
    // Check for proper input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    float total_space = 0;
    float used_space = 0;

    // Analyze the directory provided as the argument
    analyze_directory(argv[1], &total_space, &used_space);
    
    print_usage(argv[1], total_space, used_space);

    return 0;
}

void analyze_directory(const char *path, float *total_space, float *used_space) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char fullpath[MAX_PATH];
    
    // Try to open the directory
    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    // Walk through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || entry->d_name[1] == '.'))
            continue; // Skip "." and ".."

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        if (stat(fullpath, &statbuf) == -1) {
            perror("stat");
            continue; // Skip problematic files
        }

        // Check if it's a directory
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(fullpath, total_space, used_space);
        }

        // Aggregate total and used space
        *total_space += statbuf.st_size;
        *used_space += statbuf.st_size;
    }

    closedir(dir);
}

void print_usage(const char *path, float total, float used) {
    float total_gb = total / (1024 * 1024 * 1024); // Convert bytes to GB
    float used_gb = used / (1024 * 1024 * 1024); // Convert bytes to GB

    printf("Disk Space Analysis for: %s\n", path);
    printf("Total Space: " SPACE_FORMAT "\n", total_gb);
    printf("Used Space: " SPACE_FORMAT "\n", used_gb);
    printf("Free Space: " SPACE_FORMAT "\n", total_gb - used_gb);
    printf("Usage Percentage: %.2f%%\n", (used_gb / total_gb) * 100);
}