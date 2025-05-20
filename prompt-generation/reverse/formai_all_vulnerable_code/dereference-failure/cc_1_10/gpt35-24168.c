//FormAI DATASET v1.0 Category: File Synchronizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

bool is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void sync_files(const char *source, const char *destination) {
    DIR *dir;
    struct dirent *entry;

    // Open source directory
    dir = opendir(source);
    if (dir == NULL) {
        fprintf(stderr, "Error: Could not open directory %s\n", source);
        return;
    }

    // Loop over directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build paths for source and destination files
        char source_path[BUFFER_SIZE];
        char dest_path[BUFFER_SIZE];
        snprintf(source_path, BUFFER_SIZE, "%s/%s", source, entry->d_name);
        snprintf(dest_path, BUFFER_SIZE, "%s/%s", destination, entry->d_name);

        // If entry is a directory, create directory in destination and recursively sync files
        if (is_directory(source_path)) {
            mkdir(dest_path, 0777);
            sync_files(source_path, dest_path);
        }
        // Otherwise, copy file to destination
        else {
            FILE *source_file = fopen(source_path, "rb");
            FILE *dest_file = fopen(dest_path, "wb");

            // If either file cannot be opened, skip and print error message
            if (source_file == NULL || dest_file == NULL) {
                fprintf(stderr, "Error: Could not open file %s or %s\n", source_path, dest_path);
                if (source_file != NULL) {
                    fclose(source_file);
                }
                if (dest_file != NULL) {
                    fclose(dest_file);
                }
                continue;
            }

            // Copy file contents
            char buffer[BUFFER_SIZE];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dest_file);
            }

            // Close files
            fclose(source_file);
            fclose(dest_file);
        }
    }

    // Close directory
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: file-sync SOURCE_DIR DESTINATION_DIR\n");
        return 1;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    sync_files(source, destination);

    printf("Files synced successfully.\n");

    return 0;
}