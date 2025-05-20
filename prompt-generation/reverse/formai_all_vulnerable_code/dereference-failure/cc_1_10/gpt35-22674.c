//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_PATH_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void backup_file(char* filepath);
void create_backup_dir(char* directory_path);

int main(int argc, char** argv) {
    // check if a file is specified
    if (argc != 2) {
        printf("Usage: %s <filepath>\n", argv[0]);
        exit(1);
    }

    // get filepath
    char filepath[MAX_PATH_LENGTH];
    strcpy(filepath, argv[1]);

    // backup the file
    backup_file(filepath);

    return 0;
}

void backup_file(char* filepath) {
    // open the file
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(errno);
    }

    // get file information
    char* filename = strrchr(filepath, '/');
    if (filename == NULL) {
        filename = filepath;
    } else {
        filename++;
    }

    char backup_path[MAX_PATH_LENGTH] = "backup/";
    strcat(backup_path, filename);

    create_backup_dir("backup");

    // create backup file
    FILE* backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", strerror(errno));
        exit(errno);
    }

    // copy file contents to backup
    char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    // close files
    fclose(file);
    fclose(backup_file);

    printf("File backed up to: %s\n", backup_path);
}

void create_backup_dir(char* directory_path) {
    // create directory if it doesn't exist
    struct tm* time_info;
    time_t current_time;
    char timestamp[MAX_BUFFER_SIZE];
    char full_path[MAX_PATH_LENGTH];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", time_info);

    sprintf(full_path, "%s/%s", directory_path, timestamp);

    int status = mkdir(full_path, 0777);

    if (status == 0) {
        printf("Backup directory created: %s\n", full_path);
    } else if (errno == EEXIST) {
        printf("Backup directory already exists: %s\n", full_path);
    } else {
        printf("Error creating backup directory: %s\n", strerror(errno));
        exit(errno);
    }
}