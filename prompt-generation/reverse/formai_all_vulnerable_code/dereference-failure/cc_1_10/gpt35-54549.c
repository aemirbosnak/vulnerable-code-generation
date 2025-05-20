//FormAI DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 260
#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_COUNT 1000

void sync_files(char* source_path, char* destination_path);

int main() {
    char source[MAX_PATH_LENGTH] = "source_folder/";
    char dest[MAX_PATH_LENGTH] = "destination_folder/";

    sync_files(source, dest);

    return 0;
}

void sync_files(char* source_path, char* destination_path) {
    DIR *source_dir, *dest_dir;
    struct dirent *source_dp, *dest_dp; 
    struct stat source_file, dest_file;

    char source_filepath[MAX_PATH_LENGTH], dest_filepath[MAX_PATH_LENGTH];

    char filenames[MAX_FILE_COUNT][MAX_FILENAME_LENGTH];
    int file_count = 0;

    // Open source directory
    if ((source_dir = opendir(source_path)) == NULL) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }

    // Open destination directory
    if ((dest_dir = opendir(destination_path)) == NULL) {
        perror("Unable to open destination directory");
        exit(EXIT_FAILURE);
    }

    // Read all filenames in source directory
    while ((source_dp = readdir(source_dir)) != NULL) {
        if (strcmp(source_dp->d_name, ".") != 0 && strcmp(source_dp->d_name, "..") != 0) {
            strcpy(filenames[file_count++], source_dp->d_name);
        }
    }

    // Sync files from source to destination
    for (int i = 0; i < file_count; i++) {
        snprintf(source_filepath, MAX_PATH_LENGTH, "%s/%s", source_path, filenames[i]);
        snprintf(dest_filepath, MAX_PATH_LENGTH, "%s/%s", destination_path, filenames[i]);

        // Check if file exists in destination directory
        if (stat(dest_filepath, &dest_file) != -1) {
            // Check modification time
            stat(source_filepath, &source_file);

            if (difftime(source_file.st_mtime, dest_file.st_mtime) > 0) {
                // Newer file in source directory, need to update it in destination folder
                if (unlink(dest_filepath) == -1) {
                    perror("Error deleting old file");
                    exit(EXIT_FAILURE);
                }

                printf("Replacing file %s.\n", filenames[i]);

                if (link(source_filepath, dest_filepath) == -1) {
                    perror("Error copying new file");
                    exit(EXIT_FAILURE);
                }
            }
        }
        else {
            // File does not exist in destination directory
            printf("Copying file %s.\n", filenames[i]);

            if (link(source_filepath, dest_filepath) == -1) {
                perror("Error copying new file");
                exit(EXIT_FAILURE);
            }
        }
    }

    closedir(source_dir);
    closedir(dest_dir);
}