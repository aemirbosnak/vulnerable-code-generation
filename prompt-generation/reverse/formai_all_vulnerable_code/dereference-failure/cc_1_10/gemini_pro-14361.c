//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a file name.
#define MAX_FILE_NAME_SIZE 256

// Define the maximum size of a file.
#define MAX_FILE_SIZE 1024 * 1024

// Define the number of files to backup.
#define NUM_FILES_TO_BACKUP 10

// Define the names of the files to backup.
char *files_to_backup[NUM_FILES_TO_BACKUP] = {
    "file1.txt",
    "file2.txt",
    "file3.txt",
    "file4.txt",
    "file5.txt",
    "file6.txt",
    "file7.txt",
    "file8.txt",
    "file9.txt",
    "file10.txt"
};

// Define the name of the backup file.
char *backup_file_name = "backup.zip";

// Main function.
int main() {
    // Open the backup file.
    FILE *backup_file = fopen(backup_file_name, "wb");

    // Check if the backup file was opened successfully.
    if (backup_file == NULL) {
        printf("Error: Could not open backup file.\n");
        return 1;
    }

    // Loop through the files to backup.
    for (int i = 0; i < NUM_FILES_TO_BACKUP; i++) {
        // Open the file to backup.
        FILE *file_to_backup = fopen(files_to_backup[i], "rb");

        // Check if the file to backup was opened successfully.
        if (file_to_backup == NULL) {
            printf("Error: Could not open file to backup.\n");
            return 1;
        }

        // Read the file to backup into a buffer.
        char buffer[MAX_FILE_SIZE];
        fread(buffer, MAX_FILE_SIZE, 1, file_to_backup);

        // Write the buffer to the backup file.
        fwrite(buffer, MAX_FILE_SIZE, 1, backup_file);

        // Close the file to backup.
        fclose(file_to_backup);
    }

    // Close the backup file.
    fclose(backup_file);

    // Return 0 to indicate success.
    return 0;
}