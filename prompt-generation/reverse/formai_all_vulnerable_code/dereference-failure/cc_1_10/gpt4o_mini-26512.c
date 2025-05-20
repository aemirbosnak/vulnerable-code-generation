//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to calculate the hash (simple checksum) of a file
unsigned long calculate_checksum(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return 0;

    unsigned long checksum = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        checksum += c; // Update checksum
    }

    fclose(file);
    return checksum;
}

// Function to copy a file
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    if (!src || !dest) {
        fprintf(stderr, "Error opening files: %s -> %s\n", source, destination);
        return;
    }

    char buffer[1024];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to sync the files from source directory to destination directory
void sync_directories(const char *source, const char *destination) {
    DIR *dir = opendir(source);
    struct dirent *entry;

    if (!dir) {
        fprintf(stderr, "Cannot open directory: %s\n", source);
        return;
    }

    // Ensure destination directory exists
    struct stat st = {0};
    if (stat(destination, &st) == -1) {
        mkdir(destination, 0700);
    }

    // Iterate over the contents of the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[512], dest_path[512];
        snprintf(src_path, sizeof(src_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // If entry is a directory, sync contents recursively
            sync_directories(src_path, dest_path);
        } else {
            // If entry is a file, check if it needs to be synced
            unsigned long src_checksum = calculate_checksum(src_path);
            unsigned long dest_checksum = calculate_checksum(dest_path);

            if (src_checksum != dest_checksum) {
                printf("Syncing file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            } else {
                printf("File unchanged: %s\n", src_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting synchronization process...\n");
    sync_directories(argv[1], argv[2]);
    printf("Synchronization completed.\n");

    return EXIT_SUCCESS;
}