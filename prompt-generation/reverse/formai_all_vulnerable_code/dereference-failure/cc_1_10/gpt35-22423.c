//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
/*
 * File Synchronizer Example Program
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256

void sync_files(char* source_dir, char* dest_dir);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* source_dir = argv[1]; // Directory to sync from
    char* dest_dir = argv[2];   // Directory to sync to

    sync_files(source_dir, dest_dir);

    printf("Files synchronized successfully!\n");

    return 0;
}

void sync_files(char* source_dir, char* dest_dir) {
    DIR* dir;
    struct dirent* entry;

    if((dir = opendir(source_dir)) == NULL) {
        printf("Error opening directory %s: %s\n", source_dir, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_REG) { // If entry is a file
            char source_path[MAX_PATH_LENGTH] = "";
            strcat(source_path, source_dir);
            strcat(source_path, "/");
            strcat(source_path, entry->d_name); // Get full path to source file

            char dest_path[MAX_PATH_LENGTH] = "";
            strcat(dest_path, dest_dir);
            strcat(dest_path, "/");
            strcat(dest_path, entry->d_name); // Get full path to destination file

            FILE* source_file = fopen(source_path, "r");

            if(source_file == NULL) {
                printf("Error opening file %s: %s\n", source_path, strerror(errno));
                closedir(dir);
                exit(EXIT_FAILURE);
            }

            FILE* dest_file = fopen(dest_path, "w");

            if(dest_file == NULL) {
                printf("Error opening file %s: %s\n", dest_path, strerror(errno));
                fclose(source_file);
                closedir(dir);
                exit(EXIT_FAILURE);
            }

            char buffer[BUFSIZ];
            size_t size;

            while((size = fread(buffer, 1, BUFSIZ, source_file)) > 0) {
                fwrite(buffer, 1, size, dest_file);
            }

            fclose(source_file);
            fclose(dest_file);
        } else if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // If entry is a directory
            char subdir_source_path[MAX_PATH_LENGTH] = "";
            strcat(subdir_source_path, source_dir);
            strcat(subdir_source_path, "/");
            strcat(subdir_source_path, entry->d_name); // Get full path to source subdirectory

            char subdir_dest_path[MAX_PATH_LENGTH] = "";
            strcat(subdir_dest_path, dest_dir);
            strcat(subdir_dest_path, "/");
            strcat(subdir_dest_path, entry->d_name); // Get full path to destination subdirectory

            mkdir(subdir_dest_path, 0777); // Create destination directory

            sync_files(subdir_source_path, subdir_dest_path); // Recursively sync subdirectory
        }
    }

    closedir(dir);
}