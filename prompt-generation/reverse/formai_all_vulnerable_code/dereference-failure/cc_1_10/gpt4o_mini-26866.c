//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if the source file is newer than the destination file
int is_newer(const char *src_path, const char *dest_path) {
    struct stat src_stat, dest_stat;

    // Get the file stats
    if (stat(src_path, &src_stat) != 0) {
        perror("Failed to get source file stats");
        return 0; // Error condition
    }
    
    if (stat(dest_path, &dest_stat) != 0) {
        return 1; // Destination file does not exist, so it's newer
    }

    // Compare modification times
    return difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0;
}

// Function to copy a file from src to dst
void copy_file(const char *src, const char *dst) {
    FILE *src_file = fopen(src, "rb");
    FILE *dst_file = fopen(dst, "wb");

    if (src_file == NULL || dst_file == NULL) {
        perror("Failed to open file");
        if (src_file) fclose(src_file);
        if (dst_file) fclose(dst_file);
        return;
    }

    char buffer[1024];
    size_t bytes;

    // Copy the file content
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

// Function to synchronize files from a source directory to a destination directory
void sync_files(const char *src_dir, const char *dst_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);

    if (dp == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[1024];
        char dst_path[1024];

        // Build the source and destination paths
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Create the destination directory
            mkdir(dst_path, 0755);
            // Recursively synchronize the subdirectory
            sync_files(src_path, dst_path);
        } else if (entry->d_type == DT_REG) {
            // If the file is newer, copy it
            if (is_newer(src_path, dst_path)) {
                printf("Copying: %s to %s\n", src_path, dst_path);
                copy_file(src_path, dst_path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    // Create the destination directory if it does not exist
    mkdir(dst_dir, 0755);
    
    // Start the synchronization process
    sync_files(src_dir, dst_dir);

    printf("Synchronization complete.\n");
    return EXIT_SUCCESS;
}