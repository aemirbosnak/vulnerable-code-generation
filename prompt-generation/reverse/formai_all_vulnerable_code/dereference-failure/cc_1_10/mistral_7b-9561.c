//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_FOLDER "Backups"

// Function to generate unique backup filename
char* generate_backup_filename(char* original_filename) {
    static int backup_number = 0;
    char backup_filename[MAX_FILE_NAME_LENGTH];
    strcpy(backup_filename, original_filename);
    strcat(backup_filename, "_backup_");
    sprintf(backup_filename + strlen(backup_filename), "%d.bk", backup_number++);
    return backup_filename;
}

// Function to create a backup of a file
void create_backup(char* original_filename) {
    int file_fd, backup_fd;
    char original_path[MAX_FILE_NAME_LENGTH], backup_path[MAX_FILE_NAME_LENGTH];
    char* backup_filename = generate_backup_filename(original_filename);

    // Open original file for reading
    strcpy(original_path, ".");
    strcat(original_path, "/");
    strcat(original_path, original_filename);
    if ((file_fd = open(original_path, O_RDONLY)) < 0) {
        perror("Error opening original file");
        free(backup_filename);
        return;
    }

    // Create backup folder if it doesn't exist
    mkdir(BACKUP_FOLDER, 0755);

    // Open backup file for writing
    strcpy(backup_path, BACKUP_FOLDER "/");
    strcat(backup_path, backup_filename);
    if ((backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error opening backup file");
        close(file_fd);
        free(backup_filename);
        return;
    }

    // Read and write data from original file to backup file
    ssize_t bytes_read;
    char buffer[1024];
    while ((bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
        write(backup_fd, buffer, bytes_read);
    }

    // Close files and free memory
    close(file_fd);
    close(backup_fd);
    free(backup_filename);

    printf("Backup created: %s\n", backup_filename);
}

// Function to handle command line arguments and create backups for specified files
int main(int argc, char* argv[]) {
    int i;
    if (argc < 2) {
        printf("Usage: %s <file1> [file2] ...\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        create_backup(argv[i]);
    }

    return 0;
}