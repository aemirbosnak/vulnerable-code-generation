//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_DIR "backup"

// Function to copy a file
int copy_file(const char *source, const char *destination) {
    FILE *source_file = fopen(source, "rb");
    if (source_file == NULL) {
        perror("fopen");
        return -1;
    }

    FILE *destination_file = fopen(destination, "wb");
    if (destination_file == NULL) {
        perror("fopen");
        return -1;
    }

    char buffer[BUFSIZ];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    return 0;
}

// Function to create a backup of a file
int backup_file(const char *file_path) {
    // Get the file name
    char file_name[MAX_FILE_NAME_LENGTH];
    strrchr(file_path, '/') + 1;
    strcpy(file_name, file_path);

    // Create the backup directory if it doesn't exist
    struct stat st;
    if (stat(BACKUP_DIR, &st) != 0) {
        mkdir(BACKUP_DIR, 0755);
    }

    // Create the backup file path
    char backup_file_path[MAX_FILE_NAME_LENGTH];
    sprintf(backup_file_path, "%s/%s", BACKUP_DIR, file_name);

    // Copy the file to the backup directory
    return copy_file(file_path, backup_file_path);
}

// Function to backup all files in a directory
int backup_directory(const char *directory_path) {
    // Open the directory
    DIR *directory = opendir(directory_path);
    if (directory == NULL) {
        perror("opendir");
        return -1;
    }

    // Get the files in the directory
    struct dirent *file;
    while ((file = readdir(directory)) != NULL) {
        // Skip hidden files
        if (file->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char file_path[MAX_FILE_NAME_LENGTH];
        sprintf(file_path, "%s/%s", directory_path, file->d_name);

        // Backup the file
        backup_file(file_path);
    }

    // Close the directory
    closedir(directory);

    return 0;
}

int main() {
    // Get the current time
    time_t current_time = time(NULL);

    // Create a backup directory with the current time as the name
    char backup_dir_name[MAX_FILE_NAME_LENGTH];
    strftime(backup_dir_name, sizeof(backup_dir_name), "%Y-%m-%d_%H-%M-%S", localtime(&current_time));
    char backup_dir_path[MAX_FILE_NAME_LENGTH];
    sprintf(backup_dir_path, "%s/%s", BACKUP_DIR, backup_dir_name);
    mkdir(backup_dir_path, 0755);

    // Backup all files in the current directory
    backup_directory(".");

    return 0;
}