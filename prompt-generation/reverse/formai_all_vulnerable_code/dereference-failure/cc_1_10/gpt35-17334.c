//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 512

void synchronize(char* source_path, char* destination_path) {
    DIR* source_dir = opendir(source_path);
    struct dirent* source_entry;
    struct stat source_stat;
    char source_file_path[MAX_PATH_LENGTH];
    char destination_file_path[MAX_PATH_LENGTH];

    // Loop through all files in source directory
    while ((source_entry = readdir(source_dir)) != NULL) {
        // Ignore '.' and '..' directories
        if (strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0) {
            continue;
        }

        // Build full filepath for source file
        snprintf(source_file_path, MAX_PATH_LENGTH, "%s/%s", source_path, source_entry->d_name);

        // Stat the source file to determine if it's a file or directory
        stat(source_file_path, &source_stat);

        if (S_ISDIR(source_stat.st_mode)) {
            // It's a directory, recursively call synchronize on the subdirectory
            char destination_subdir[MAX_PATH_LENGTH];
            snprintf(destination_subdir, MAX_PATH_LENGTH, "%s/%s", destination_path, source_entry->d_name);
            mkdir(destination_subdir, S_IRWXU);
            synchronize(source_file_path, destination_subdir);
        } else {
            // It's a file, synchronize it to the destination directory
            snprintf(destination_file_path, MAX_PATH_LENGTH, "%s/%s", destination_path, source_entry->d_name);
            FILE* source_file = fopen(source_file_path, "r");
            FILE* destination_file = fopen(destination_file_path, "w");

            if (source_file == NULL) {
                printf("Error opening source file: %s\n", source_file_path);
                exit(1);
            }

            if (destination_file == NULL) {
                printf("Error opening destination file: %s\n", destination_file_path);
                exit(1);
            }

            char buffer[1024];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof buffer, source_file)) > 0) {
                fwrite(buffer, 1, bytes_read, destination_file);
            }

            fclose(source_file);
            fclose(destination_file);
        }
    }

    closedir(source_dir);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(1);
    }

    synchronize(argv[1], argv[2]);

    printf("Synchronization complete\n");
    return 0;
}