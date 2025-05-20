//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int is_modified(const char *src_path, const char *dest_path) {
    struct stat src_stat, dest_stat;

    if (stat(src_path, &src_stat) != 0) {
        perror("Failed to get source file stats");
        return 1;
    }

    if (stat(dest_path, &dest_stat) != 0) {
        // If the destination file doesn't exist, consider it modified
        return 1;
    }
    
    return src_stat.st_mtime > dest_stat.st_mtime; // Check if src is newer
}

void copy_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!src_file) {
        perror("Failed to open source file");
        return;
    }
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dir = opendir(src_dir);

    if (dir == NULL) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            if (is_modified(src_path, dest_path)) {
                printf("Copying %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        } else if (entry->d_type == DT_DIR) { // Subdirectory
            mkdir(dest_path, 0755); // Create subdirectory if it doesn't exist
            sync_directory(src_path, dest_path); // Recursive sync
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_directory(src_dir, dest_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}