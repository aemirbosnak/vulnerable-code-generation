//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to calculate the total size of files in a directory
long get_directory_size(const char *path) {
    struct dirent *entry;
    struct stat file_stat;
    long total_size = 0;
    DIR *directory = opendir(path);
    
    if (directory == NULL) {
        perror("opendir");
        return 0;
    }

    while ((entry = readdir(directory)) != NULL) {
        // Skip the '.' and '..' directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) < 0) {
            perror("stat");
            continue;
        }
        
        if (S_ISDIR(file_stat.st_mode)) {
            total_size += get_directory_size(full_path); // Recursive call for directories
        } else {
            total_size += file_stat.st_size; // Add file size
        }
    }
    
    closedir(directory);
    return total_size;
}

// Function to convert bytes to a human-readable format
void print_human_readable_size(long size) {
    const char *units[] = { "B", "KB", "MB", "GB", "TB" };
    int i = 0;

    while (size >= 1024 && i < 4) {
        size /= 1024;
        i++;
    }

    printf("%ld %s\n", size, units[i]);
}

// Main function to execute the disk space analysis
int main(int argc, char *argv[]) {
    char *start_path;
    
    // Check for path argument
    if (argc < 2) {
        start_path = ".";
    } else {
        start_path = argv[1];
    }

    printf("Analyzing disk space usage for: %s\n\n", start_path);
    
    long total_size = get_directory_size(start_path);
    
    if (total_size < 0) {
        fprintf(stderr, "Error calculating size for %s\n", start_path);
        return 1;
    }
    
    printf("Total size of '%s': ", start_path);
    print_human_readable_size(total_size);

    return 0;
}