//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

// Function declarations
void analyze_directory(const char *dir_name);
void print_space_usage(const char *dir_name, long long *total_size);
void print_human_readable_size(long long size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);
    return EXIT_SUCCESS;
}

void analyze_directory(const char *dir_name) {
    printf("Analyzing disk space for: %s\n", dir_name);
    long long total_size = 0;

    // Print initial space usage.
    print_space_usage(dir_name, &total_size);

    // Print the total usage.
    printf("\nTotal Disk Space Used in '%s': ", dir_name);
    print_human_readable_size(total_size);
    printf("\n");
}

void print_space_usage(const char *dir_name, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char full_path[MAX_PATH];

    // Open the directory
    if ((dir = opendir(dir_name)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    // Iterate through all entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the full path
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, entry->d_name);

        // Get file or directory stats
        if (stat(full_path, &statbuf) == -1) {
            perror("Unable to stat");
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(statbuf.st_mode)) {
            printf("Directory: %s - Size: ", full_path);
            long long dir_size = 0;
            print_space_usage(full_path, &dir_size);
            printf(" (subdir total: ");
            print_human_readable_size(dir_size);
            printf(")\n");
            *total_size += dir_size; // Add to total size
        } else {
            // For files, just print the size
            printf("File: %s - Size: ", full_path);
            print_human_readable_size(statbuf.st_size);
            printf("\n");
            *total_size += statbuf.st_size; // Add to total size
        }
    }

    closedir(dir);
}

void print_human_readable_size(long long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double size_double = (double)size;

    while (size_double >= 1024 && i < 4) {
        size_double /= 1024;
        i++;
    }
    
    printf("%.2f %s", size_double, units[i]);
}