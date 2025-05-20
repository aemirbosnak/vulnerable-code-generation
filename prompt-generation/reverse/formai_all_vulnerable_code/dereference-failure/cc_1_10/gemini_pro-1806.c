//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of files to backup
#define MAX_FILES 10

// Define the maximum size of a file name
#define MAX_FILE_NAME_SIZE 256

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the backup directory
#define BACKUP_DIR "backup"

// Define the file extension for backup files
#define BACKUP_EXT ".bak"

// Function to get the current date and time
char* get_date_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *date_time = malloc(20);
    strftime(date_time, 20, "%Y-%m-%d %H:%M:%S", tm);
    return date_time;
}

// Function to create a backup directory
int create_backup_dir() {
    // Check if the backup directory exists
    if (mkdir(BACKUP_DIR, 0755) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to backup a file
int backup_file(char *file_name) {
    // Open the file to be backed up
    FILE *src_file = fopen(file_name, "rb");
    if (src_file == NULL) {
        return 0;
    }

    // Get the file size
    fseek(src_file, 0, SEEK_END);
    long file_size = ftell(src_file);
    rewind(src_file);

    // Create the backup file name
    char *backup_file_name = malloc(strlen(file_name) + strlen(BACKUP_EXT) + 1);
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_EXT);

    // Open the backup file
    FILE *dest_file = fopen(backup_file_name, "wb");
    if (dest_file == NULL) {
        free(backup_file_name);
        fclose(src_file);
        return 0;
    }

    // Copy the file contents to the backup file
    char buffer[MAX_FILE_SIZE];
    while (file_size > 0) {
        size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, src_file);
        fwrite(buffer, 1, bytes_read, dest_file);
        file_size -= bytes_read;
    }

    // Close the files
    fclose(src_file);
    fclose(dest_file);

    // Free the memory
    free(backup_file_name);

    return 1;
}

// Function to backup multiple files
int backup_files(char **file_names, int num_files) {
    // Create the backup directory
    if (!create_backup_dir()) {
        return 0;
    }

    // Backup each file
    for (int i = 0; i < num_files; i++) {
        if (!backup_file(file_names[i])) {
            return 0;
        }
    }

    return 1;
}

// Main function
int main() {
    // Get the list of files to backup
    char *file_names[MAX_FILES] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
    int num_files = 5;

    // Backup the files
    if (!backup_files(file_names, num_files)) {
        printf("Error backing up files.\n");
        return 1;
    }

    printf("Files backed up successfully.\n");

    return 0;
}