//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Define the maximum file name length
#define MAX_FILE_NAME_LENGTH 1024

// Define the maximum number of files to synchronize
#define MAX_NUM_FILES 100

// Define the directory separator
#define DIR_SEPARATOR '/'

// Define the file extension to synchronize
#define FILE_EXTENSION ".txt"

// Define the synchronization mode
#define SYNC_MODE_OVERWRITE 0
#define SYNC_MODE_APPEND 1

// Define the error codes
#define ERROR_NONE 0
#define ERROR_INVALID_DIRECTORY 1
#define ERROR_INVALID_FILE 2
#define ERROR_FILE_NOT_FOUND 3

// Define the synchronization function
int synchronize(char *source_directory, char *destination_directory, int mode);

// Define the main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <source_directory> <destination_directory> <mode>\n", argv[0]);
        printf("Where <mode> can be either \"overwrite\" or \"append\".\n");
        return 1;
    }

    // Get the source directory
    char *source_directory = argv[1];

    // Get the destination directory
    char *destination_directory = argv[2];

    // Get the synchronization mode
    int mode;
    if (strcmp(argv[3], "overwrite") == 0) {
        mode = SYNC_MODE_OVERWRITE;
    } else if (strcmp(argv[3], "append") == 0) {
        mode = SYNC_MODE_APPEND;
    } else {
        printf("Invalid synchronization mode: %s\n", argv[3]);
        return 1;
    }

    // Synchronize the files
    int error_code = synchronize(source_directory, destination_directory, mode);

    // Check for errors
    if (error_code != ERROR_NONE) {
        printf("Error: %d\n", error_code);
        return 1;
    }

    // Success
    printf("Files synchronized successfully.\n");
    return 0;
}

// Define the synchronization function
int synchronize(char *source_directory, char *destination_directory, int mode) {
    // Open the source directory
    DIR *source_dir = opendir(source_directory);
    if (source_dir == NULL) {
        return ERROR_INVALID_DIRECTORY;
    }

    // Open the destination directory
    DIR *destination_dir = opendir(destination_directory);
    if (destination_dir == NULL) {
        return ERROR_INVALID_DIRECTORY;
    }

    // Get the list of files in the source directory
    struct dirent **source_files;
    int num_source_files = scandir(source_directory, &source_files, NULL, alphasort);
    if (num_source_files < 0) {
        return ERROR_INVALID_DIRECTORY;
    }

    // Get the list of files in the destination directory
    struct dirent **destination_files;
    int num_destination_files = scandir(destination_directory, &destination_files, NULL, alphasort);
    if (num_destination_files < 0) {
        return ERROR_INVALID_DIRECTORY;
    }

    // Synchronize the files
    for (int i = 0; i < num_source_files; i++) {
        // Get the source file name
        char *source_file_name = source_files[i]->d_name;

        // Get the destination file name
        char *destination_file_name = malloc(strlen(destination_directory) + strlen(source_file_name) + 1);
        strcpy(destination_file_name, destination_directory);
        strcat(destination_file_name, DIR_SEPARATOR);
        strcat(destination_file_name, source_file_name);

        // Check if the destination file exists
        int destination_file_exists = 0;
        for (int j = 0; j < num_destination_files; j++) {
            if (strcmp(destination_files[j]->d_name, source_file_name) == 0) {
                destination_file_exists = 1;
                break;
            }
        }

        // Open the source file
        FILE *source_file = fopen(source_file_name, "r");
        if (source_file == NULL) {
            return ERROR_INVALID_FILE;
        }

        // Open the destination file
        FILE *destination_file;
        if (mode == SYNC_MODE_OVERWRITE) {
            destination_file = fopen(destination_file_name, "w");
        } else if (mode == SYNC_MODE_APPEND) {
            destination_file = fopen(destination_file_name, "a");
        }
        if (destination_file == NULL) {
            return ERROR_INVALID_FILE;
        }

        // Copy the contents of the source file to the destination file
        char buffer[MAX_FILE_NAME_LENGTH];
        while (fgets(buffer, MAX_FILE_NAME_LENGTH, source_file) != NULL) {
            fputs(buffer, destination_file);
        }

        // Close the source file
        fclose(source_file);

        // Close the destination file
        fclose(destination_file);

        // Free the destination file name
        free(destination_file_name);
    }

    // Free the source files
    free(source_files);

    // Free the destination files
    free(destination_files);

    // Close the source directory
    closedir(source_dir);

    // Close the destination directory
    closedir(destination_dir);

    // Success
    return ERROR_NONE;
}