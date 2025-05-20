//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Define the maximum length of a file path
#define MAX_PATH_LENGTH 256

// Define the maximum number of files to backup
#define MAX_FILES 100

// Define the backup directory
#define BACKUP_DIR "backups"

// Function to create a backup directory if it doesn't exist
void create_backup_directory() {
    // Check if the backup directory exists
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        // Create the backup directory
        mkdir(BACKUP_DIR, 0755);
    }
}

// Function to get the current time
char* get_current_time() {
    // Get the current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Format the current time as a string
    char* time_string = malloc(20);
    strftime(time_string, 20, "%Y-%m-%d %H:%M:%S", tm);

    // Return the current time string
    return time_string;
}

// Function to get a list of files in a directory
char** get_files_in_directory(char* directory) {
    // Open the directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        return NULL;
    }

    // Get a list of files in the directory
    char** files = malloc(sizeof(char*) * MAX_FILES);
    int num_files = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Add the file to the list
        files[num_files] = strdup(entry->d_name);
        num_files++;
    }

    // Close the directory
    closedir(dir);

    // Return the list of files
    return files;
}

// Function to copy a file
int copy_file(char* source_file, char* destination_file) {
    // Open the source file
    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        return -1;
    }

    // Open the destination file
    FILE *destination = fopen(destination_file, "wb");
    if (destination == NULL) {
        fclose(source);
        return -1;
    }

    // Copy the file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    // Close the files
    fclose(source);
    fclose(destination);

    // Return 0 if the file was copied successfully
    return 0;
}

// Function to backup a file
int backup_file(char* file) {
    // Get the current time
    char* current_time = get_current_time();

    // Create the backup file name
    char backup_file_name[MAX_PATH_LENGTH];
    snprintf(backup_file_name, MAX_PATH_LENGTH, "%s/%s-%s", BACKUP_DIR, file, current_time);

    // Copy the file to the backup directory
    int result = copy_file(file, backup_file_name);

    // Free the current time string
    free(current_time);

    // Return the result of the copy operation
    return result;
}

// Function to backup a directory
int backup_directory(char* directory) {
    // Create the backup directory if it doesn't exist
    create_backup_directory();

    // Get a list of files in the directory
    char** files = get_files_in_directory(directory);
    if (files == NULL) {
        return -1;
    }

    // Backup each file in the directory
    int result = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i] == NULL) {
            break;
        }

        // Create the full path to the file
        char file_path[MAX_PATH_LENGTH];
        snprintf(file_path, MAX_PATH_LENGTH, "%s/%s", directory, files[i]);

        // Backup the file
        result = backup_file(file_path);
        if (result != 0) {
            break;
        }
    }

    // Free the list of files
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i] != NULL) {
            free(files[i]);
        }
    }
    free(files);

    // Return the result of the backup operation
    return result;
}

int main() {
    // Backup the current directory
    int result = backup_directory(".");

    // Print the result of the backup operation
    if (result == 0) {
        printf("Backup successful.\n");
    } else {
        printf("Backup failed.\n");
    }

    return result;
}