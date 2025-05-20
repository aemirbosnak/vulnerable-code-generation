//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

// Function to convert bytes to human-readable format
void human_readable_size(double size, char *buffer) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    while (size >= 1024 && unit_index < 4) {
        size /= 1024;
        unit_index++;
    }

    sprintf(buffer, "%.2f %s", size, units[unit_index]);
}

// Function to calculate space used in a directory
double calculate_directory_size(const char *path) {
    double total_size = 0.0;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];
    
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        // Get file status
        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // If it's a directory, recursively calculate size
            total_size += calculate_directory_size(full_path);
        } else {
            // If it's a file, add its size
            total_size += file_stat.st_size;
        }
    }
    closedir(dir);
    return total_size;
}

int main(int argc, char *argv[]) {
    const char *target_directory;
    char readable_size[20];
    double total_size;

    // Determine the target directory
    if (argc > 1) {
        target_directory = argv[1];
    } else {
        target_directory = ".";
    }

    total_size = calculate_directory_size(target_directory);

    // Print the total size in human-readable format
    human_readable_size(total_size, readable_size);
    printf("Total size of '%s': %s\n", target_directory, readable_size);

    return 0;
}