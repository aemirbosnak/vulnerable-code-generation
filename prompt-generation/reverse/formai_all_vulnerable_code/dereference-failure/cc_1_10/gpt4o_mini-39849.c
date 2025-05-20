//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if a file or directory exists.
int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Function to copy a file from source to destination.
int copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }
    
    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }
    
    char buffer[1024];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
    return 0;
}

// Function to synchronize files from src_dir to dest_dir.
void synchronize_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;
    
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char src_path[1024], dest_path[1024];
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
            
            if (entry->d_type == DT_DIR) {
                // Recursively synchronize directories
                if (!file_exists(dest_path)) {
                    mkdir(dest_path, 0755);
                }
                synchronize_directories(src_path, dest_path);
            } else { // It's a file
                if (!file_exists(dest_path) || (stat(src_path, NULL) != stat(dest_path, NULL))) {
                    if (copy_file(src_path, dest_path) == 0) {
                        printf("Copied: %s to %s\n", src_path, dest_path);
                    }
                }
            }
        }
    }
    
    closedir(dir);
}

// Main function to handle user input and initiate synchronization.
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];
    
    // Ensure source directory exists
    if (!file_exists(source_directory) || !file_exists(destination_directory)) {
        fprintf(stderr, "Error: Source or Destination directory does not exist.\n");
        return EXIT_FAILURE;
    }
    
    // Start synchronization
    synchronize_directories(source_directory, destination_directory);
    
    printf("Synchronization complete.\n");
    return EXIT_SUCCESS;
}