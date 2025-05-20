//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum file size
#define MAX_FILE_SIZE 1024

// Define the number of files to back up
#define NUM_FILES 3

// Define the list of files to back up
char *files_to_backup[] = {"file1.txt", "file2.txt", "file3.txt"};

// Define the destination directory for the backup
char *backup_directory = "/backup/";

// Function to copy a file
int copy_file(char *source_file, char *destination_file) {
    // Open the source file
    FILE *source = fopen(source_file, "r");
    if (source == NULL) {
        return -1;
    }
    // Open the destination file
    FILE *destination = fopen(destination_file, "w");
    if (destination == NULL) {
        return -1;
    }
    // Copy the file contents
    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }
    // Close the files
    fclose(source);
    fclose(destination);
    return 0;
}

// Function to back up a file
int backup_file(char *file) {
    // Get the file name
    char *file_name = strrchr(file, '/') + 1;
    // Create the destination file path
    char *destination_file = malloc(strlen(backup_directory) + strlen(file_name) + 1);
    strcpy(destination_file, backup_directory);
    strcat(destination_file, file_name);
    // Copy the file
    int result = copy_file(file, destination_file);
    // Free the allocated memory
    free(destination_file);
    return result;
}

// Function to back up multiple files
int backup_files() {
    // Iterate over the files to back up
    for (int i = 0; i < NUM_FILES; i++) {
        // Back up each file
        int result = backup_file(files_to_backup[i]);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

// Main function
int main() {
    // Back up the files
    int result = backup_files();
    if (result == 0) {
        printf("Files backed up successfully!\n");
    } else {
        printf("Error backing up files!\n");
    }
    return result;
}