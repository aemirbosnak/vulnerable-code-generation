//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

// Define the maximum number of files to be backed up
#define MAX_FILES 100

// Define the maximum length of a file path
#define MAX_PATH_LENGTH 256

// Define the the backup directory
#define BACKUP_DIR "/backup"

// Function to get the current date and time
char *get_current_date_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *date_time = malloc(sizeof(char) * 20);
    strftime(date_time, 20, "%Y-%m-%d %H:%M:%S", tm);
    return date_time;
}

// Function to create a directory
int create_directory(char *dir_name) {
    int status = mkdir(dir_name, 0777);
    if (status == 0) {
        printf("Directory %s created successfully\n", dir_name);
    } else {
        printf("Error creating directory %s: %s\n", dir_name, strerror(errno));
    }
    return status;
}

// Function to copy a file
int copy_file(char *source_file, char *destination_file) {
    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        printf("Error opening source file %s: %s\n", source_file, strerror(errno));
        return -1;
    }

    FILE *destination = fopen(destination_file, "wb");
    if (destination == NULL) {
        printf("Error opening destination file %s: %s\n", destination_file, strerror(errno));
        fclose(source);
        return -1;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    fclose(source);
    fclose(destination);

    return 0;
}

// Function to backup files
int backup_files(char *source_dir, char *destination_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error opening directory %s: %s\n", source_dir, strerror(errno));
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *source_file = malloc(sizeof(char) * (strlen(source_dir) + strlen(entry->d_name) + 2));
        strcpy(source_file, source_dir);
        strcat(source_file, "/");
        strcat(source_file, entry->d_name);

        char *destination_file = malloc(sizeof(char) * (strlen(destination_dir) + strlen(entry->d_name) + 2));
        strcpy(destination_file, destination_dir);
        strcat(destination_file, "/");
        strcat(destination_file, entry->d_name);

        if (copy_file(source_file, destination_file) == 0) {
            printf("File %s backed up successfully\n", entry->d_name);
        }

        free(source_file);
        free(destination_file);
    }

    closedir(dir);

    return 0;
}

// Main function
int main() {
    // Get the current date and time
    char *date_time = get_current_date_time();

    // Create the backup directory
    create_directory(BACKUP_DIR);

    // Create the backup directory for the current date and time
    char *backup_dir = malloc(sizeof(char) * (strlen(BACKUP_DIR) + strlen(date_time) + 2));
    strcpy(backup_dir, BACKUP_DIR);
    strcat(backup_dir, "/");
    strcat(backup_dir, date_time);
    create_directory(backup_dir);

    // Backup the files
    backup_files("/home/user/Documents", backup_dir);

    // Free the allocated memory
    free(date_time);
    free(backup_dir);

    return 0;
}