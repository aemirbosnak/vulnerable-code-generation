//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to calculate the size of a directory recursively
unsigned long long calculate_directory_size(const char *path) {
    unsigned long long total_size = 0;
    struct dirent *entry;
    struct stat entry_stat;
    DIR *directory = opendir(path);

    if (directory == NULL) {
        perror("Unable to open directory");
        return 0;
    }

    while ((entry = readdir(directory)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &entry_stat) == 0) {
                if (S_ISDIR(entry_stat.st_mode)) {
                    // It's a directory, so recurse into it
                    total_size += calculate_directory_size(full_path);
                } else {
                    // It's a file, so add its size
                    total_size += entry_stat.st_size;
                }
            }
        }
    }

    closedir(directory);
    return total_size;
}

// Function to format byte size into human-readable form
void format_size(unsigned long long size, char *buffer, size_t bufsize) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    double size_in_units = (double)size;
    while (size_in_units >= 1024.0 && unit_index < 4) {
        size_in_units /= 1024.0;
        unit_index++;
    }
    snprintf(buffer, bufsize, "%.2f %s", size_in_units, units[unit_index]);
}

// Main function to analyze disk space
int main(int argc, char *argv[]) {
    char *path;
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

    printf("Analyzing disk space for directory: %s\n", path);
    
    unsigned long long total_size = calculate_directory_size(path);
    char formatted_size[64];
    format_size(total_size, formatted_size, sizeof(formatted_size));

    printf("Total size: %s\n", formatted_size);

    return 0;
}