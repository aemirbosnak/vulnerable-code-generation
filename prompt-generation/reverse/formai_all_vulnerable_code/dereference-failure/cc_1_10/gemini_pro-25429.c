//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#define MAX_PATH 256
#define MAX_FILES 100

// Define the configuration options
typedef struct {
    char *source_path;
    char *destination_path;
    int interval;
    int files_to_keep;
} backup_config_t;

// Function to read the configuration file
void read_config(backup_config_t *config) {
    FILE *fp;
    char buffer[BUF_SIZE];

    // Open the configuration file
    fp = fopen("backup.conf", "r");
    if (fp == NULL) {
        perror("Error opening configuration file");
        exit(EXIT_FAILURE);
    }

    // Read the source path
    fgets(buffer, BUF_SIZE, fp);
    config->source_path = malloc(strlen(buffer) + 1);
    strcpy(config->source_path, buffer);

    // Read the destination path
    fgets(buffer, BUF_SIZE, fp);
    config->destination_path = malloc(strlen(buffer) + 1);
    strcpy(config->destination_path, buffer);

    // Read the backup interval
    fgets(buffer, BUF_SIZE, fp);
    config->interval = atoi(buffer);

    // Read the number of files to keep
    fgets(buffer, BUF_SIZE, fp);
    config->files_to_keep = atoi(buffer);

    // Close the configuration file
    fclose(fp);
}

// Function to create a directory
int create_directory(const char *path) {
    int status;

    // Create the directory
    status = mkdir(path, 0755);
    if (status == -1) {
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Function to copy a file
int copy_file(const char *source, const char *destination) {
    int source_fd, destination_fd;
    int status;
    char buffer[BUF_SIZE];

    // Open the source file
    source_fd = open(source, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open the destination file
    destination_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd == -1) {
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    // Copy the file data
    while ((status = read(source_fd, buffer, BUF_SIZE)) > 0) {
        write(destination_fd, buffer, status);
    }

    // Close the files
    close(source_fd);
    close(destination_fd);

    return 0;
}

// Function to delete a file
int delete_file(const char *path) {
    int status;

    // Delete the file
    status = remove(path);
    if (status == -1) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Function to get the current time
time_t get_current_time() {
    time_t current_time;

    // Get the current time
    current_time = time(NULL);
    if (current_time == -1) {
        perror("Error getting current time");
        exit(EXIT_FAILURE);
    }

    return current_time;
}

// Function to format a time stamp
char *format_timestamp(time_t timestamp) {
    char *timestamp_string;
    struct tm *tm_info;

    // Allocate memory for the timestamp string
    timestamp_string = malloc(256);
    if (timestamp_string == NULL) {
        perror("Error allocating memory for timestamp string");
        exit(EXIT_FAILURE);
    }

    // Format the timestamp
    tm_info = localtime(&timestamp);
    strftime(timestamp_string, 256, "%Y-%m-%d %H:%M:%S", tm_info);

    return timestamp_string;
}

// Function to backup files
int backup_files(backup_config_t *config) {
    DIR *source_dir;
    struct dirent *source_file;
    char source_path[MAX_PATH];
    char destination_path[MAX_PATH];
    time_t current_time;
    char *timestamp_string;
    int file_count;
    int i;

    // Open the source directory
    source_dir = opendir(config->source_path);
    if (source_dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    // Create the destination directory
    create_directory(config->destination_path);

    // Get the current time
    current_time = get_current_time();

    // Format the timestamp
    timestamp_string = format_timestamp(current_time);

    // Loop through the files in the source directory
    file_count = 0;
    while ((source_file = readdir(source_dir)) != NULL) {
        // Skip the "." and ".." directories
        if (!strcmp(source_file->d_name, ".") || !strcmp(source_file->d_name, "..")) {
            continue;
        }

        // Create the source path
        snprintf(source_path, MAX_PATH, "%s/%s", config->source_path, source_file->d_name);

        // Create the destination path
        snprintf(destination_path, MAX_PATH, "%s/%s_%s", config->destination_path, source_file->d_name, timestamp_string);

        // Copy the file
        copy_file(source_path, destination_path);

        // Increment the file count
        file_count++;
    }

    // Close the source directory
    closedir(source_dir);

    // Delete old backups
    for (i = 0; i < file_count - config->files_to_keep; i++) {
        // Get the oldest backup file
        snprintf(destination_path, MAX_PATH, "%s/%s_*", config->destination_path, source_file->d_name);

        // Delete the file
        delete_file(destination_path);
    }

    // Free the memory allocated for the timestamp string
    free(timestamp_string);

    return 0;
}

int main() {
    backup_config_t config;

    // Read the configuration file
    read_config(&config);

    // Backup the files
    backup_files(&config);

    return 0;
}