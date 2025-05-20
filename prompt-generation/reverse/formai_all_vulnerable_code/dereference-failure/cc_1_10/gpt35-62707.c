//FormAI DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

// Function to recursively copy the directory structure
void copy_directory(const char *src_path, const char *dest_path) {
    // Open the source directory
    DIR *src_dir = opendir(src_path);
    if (src_dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    // Open the destination directory or create if it doesn't exist
    DIR *dest_dir = opendir(dest_path);
    if (dest_dir == NULL) {
        mkdir(dest_path, 0777);
        dest_dir = opendir(dest_path);
        if (dest_dir == NULL) {
            perror("Error creating or opening destination directory");
            exit(EXIT_FAILURE);
        }
    }

    // Copy files and directories in the source directory to the destination directory
    struct dirent *entry;
    while ((entry = readdir(src_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            // Skip current and parent directories
            continue;
        }

        char src_file_path[MAX_BUFFER_SIZE];
        char dest_file_path[MAX_BUFFER_SIZE];
        snprintf(src_file_path, MAX_BUFFER_SIZE, "%s/%s", src_path, entry->d_name);
        snprintf(dest_file_path, MAX_BUFFER_SIZE, "%s/%s", dest_path, entry->d_name);

        struct stat file_stat;
        stat(src_file_path, &file_stat);
        if (S_ISDIR(file_stat.st_mode)) {
            // If the file is a directory, recursively copy the directory structure
            copy_directory(src_file_path, dest_file_path);
        } else {
            // If the file is a regular file, copy the file to the destination directory
            FILE *src_file = fopen(src_file_path, "r");
            if (src_file == NULL) {
                perror("Error opening source file");
                exit(EXIT_FAILURE);
            }

            FILE *dest_file = fopen(dest_file_path, "w");
            if (dest_file == NULL) {
                perror("Error opening destination file");
                fclose(src_file);
                exit(EXIT_FAILURE);
            }

            char buffer[MAX_BUFFER_SIZE];
            while (fgets(buffer, MAX_BUFFER_SIZE, src_file) != NULL) {
                fputs(buffer, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    // Close the directories
    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copy_directory(argv[1], argv[2]);
    printf("Directory synchronized successfully!\n");
    exit(EXIT_SUCCESS);
}