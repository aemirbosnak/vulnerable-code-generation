//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

// Function prototypes
void extract_metadata(const char *file_path);
void format_permissions(mode_t mode);
void print_metadata(const char *file_name, struct stat *file_stat);

int main(int argc, char *argv[]) {
    // Ensure a directory argument is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_path = argv[1];
    DIR *dir = opendir(dir_path);
    
    // Check if the directory can be opened
    if (dir == NULL) {
        perror("Could not open directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    // Loop through directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the file path
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
        
        // Extract and print metadata for the file
        extract_metadata(file_path);
    }

    closedir(dir);
    return EXIT_SUCCESS;
}

// Extract file metadata using fstat
void extract_metadata(const char *file_path) {
    struct stat file_stat;

    // Get file statistics
    if (stat(file_path, &file_stat) == -1) {
        perror("Could not get file stats");
        return;
    }

    // Print the metadata
    print_metadata(file_path, &file_stat);
}

// Print detailed metadata
void print_metadata(const char *file_name, struct stat *file_stat) {
    printf("File: %s\n", file_name);
    printf("Size: %ld bytes\n", file_stat->st_size);
    printf("Last modified: %s", ctime(&file_stat->st_mtime));
    printf("Permissions: ");
    format_permissions(file_stat->st_mode);
    printf("\n\n");
}

// Format file permissions into a human-readable format
void format_permissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}