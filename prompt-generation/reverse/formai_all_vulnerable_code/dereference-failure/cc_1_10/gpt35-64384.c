//FormAI DATASET v1.0 Category: File Synchronizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 1000
#define BUFFER_SIZE 1000

// function to check if a file exists or not
int file_exists(char* path) {
    struct stat buffer;
    int status = stat(path, &buffer);

    return (status == 0);
}

// function to remove a file
void remove_file(char* path) {
    if (remove(path) != 0) {
        printf("Error deleting file %s\n", path);
    }
}

// function to copy a file
void copy_file(char* source_path, char* destination_path) {
    FILE* source_file = fopen(source_path, "rb");
    FILE* destination_file = fopen(destination_path, "wb");

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
}

// function to sync all files in a directory with another directory
void sync_directory(char* source_directory, char* destination_directory) {
    DIR* dir;
    struct dirent* entry;
    char* source_path = (char*) malloc(MAX_FILENAME_LENGTH);
    char* destination_path = (char*) malloc(MAX_FILENAME_LENGTH);

    dir = opendir(source_directory);

    // loop through all files in the source directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        sprintf(source_path, "%s/%s", source_directory, entry->d_name);
        sprintf(destination_path, "%s/%s", destination_directory, entry->d_name);

        // if the file exists in the destination directory, check if it is the same
        if (file_exists(destination_path)) {
            // if the file is different, replace it with the one from the source directory
            if (access(source_path, F_OK) != -1 && access(destination_path, F_OK) != -1) {
                struct stat source_stat;
                struct stat destination_stat;

                stat(source_path, &source_stat);
                stat(destination_path, &destination_stat);

                if (source_stat.st_mtime != destination_stat.st_mtime) {
                    printf("Replacing %s with %s\n", destination_path, source_path);
                    remove_file(destination_path);
                    copy_file(source_path, destination_path);
                }
            }
        } else {
            // if the file does not exist in the destination directory, copy it over
            printf("Copying %s to %s\n", source_path, destination_path);
            copy_file(source_path, destination_path);
        }
    }

    closedir(dir);

    free(source_path);
    free(destination_path);
}

int main(int argc, char** argv) {
    char* source_directory = argv[1];
    char* destination_directory = argv[2];

    if (!file_exists(source_directory)) {
        printf("Source directory does not exist!\n");
        exit(EXIT_FAILURE);
    }

    if (!file_exists(destination_directory)) {
        printf("Destination directory does not exist!\n");
        exit(EXIT_FAILURE);
    }

    sync_directory(source_directory, destination_directory);

    return 0;
}