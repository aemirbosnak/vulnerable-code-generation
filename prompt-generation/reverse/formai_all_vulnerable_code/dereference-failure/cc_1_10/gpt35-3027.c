//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 256  // maximum path length
#define MAX_FILE_COUNT 100   // maximum number of files to synchronize

/*
 * Function to synchronize files in two directories.
 * Params:
 * - source: the path to the source directory.
 * - destination: the path to the destination directory.
 * - file_count: pointer to a variable that will contain the number of files synchronized.
 * Returns:
 * - 0 on success, -1 on error.
 */
int sync_files(char* source, char* destination, int* file_count) {
    // Open source directory
    DIR* dir = opendir(source);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    // Create destination directory
    if (mkdir(destination, 0755) == -1) {
        perror("mkdir");
        return -1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL && *file_count < MAX_FILE_COUNT) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build path to source file
        char source_path[MAX_PATH_LENGTH];
        snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source, entry->d_name);

        // Build path to destination file
        char destination_path[MAX_PATH_LENGTH];
        snprintf(destination_path, MAX_PATH_LENGTH, "%s/%s", destination, entry->d_name);

        // Check if file already exists in destination
        struct stat dest_stat;
        if (stat(destination_path, &dest_stat) == 0) {
            // Check if source file was updated more recently than destination file
            struct stat source_stat;
            if (stat(source_path, &source_stat) == 0 && difftime(source_stat.st_mtime, dest_stat.st_mtime) > 0) {
                // Source file is newer, overwrite destination file
                FILE* source_file = fopen(source_path, "rb");
                if (!source_file) {
                    perror("fopen");
                    return -1;
                }
                FILE* dest_file = fopen(destination_path, "wb");
                if (!dest_file) {
                    fclose(source_file);
                    perror("fopen");
                    return -1;
                }
                char buffer[1024];
                size_t read_count;
                while ((read_count = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                    fwrite(buffer, 1, read_count, dest_file);
                }
                fclose(source_file);
                fclose(dest_file);
                *file_count += 1;
            }
        } else {
            // File does not exist in destination, copy it over
            FILE* source_file = fopen(source_path, "rb");
            if (!source_file) {
                perror("fopen");
                return -1;
            }
            FILE* dest_file = fopen(destination_path, "wb");
            if (!dest_file) {
                fclose(source_file);
                perror("fopen");
                return -1;
            }
            char buffer[1024];
            size_t read_count;
            while ((read_count = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                fwrite(buffer, 1, read_count, dest_file);
            }
            fclose(source_file);
            fclose(dest_file);
            *file_count += 1;
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int file_count = 0;
    if (sync_files(argv[1], argv[2], &file_count) == -1) {
        fprintf(stderr, "Failed to synchronize files\n");
        return EXIT_FAILURE;
    }

    printf("Synchronized %d files from %s to %s\n", file_count, argv[1], argv[2]);
    return EXIT_SUCCESS;
}