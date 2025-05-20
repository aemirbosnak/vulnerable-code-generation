//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 100
#define BACKUP_DIR "backup"

// Function to create a backup of a file
void create_backup(char *file_path) {
    char backup_file_path[MAX_FILENAME_LENGTH];
    int file_fd, backup_fd;
    struct stat file_stat;

    // Construct the backup file path
    strcpy(backup_file_path, BACKUP_DIR "/");
    strcat(backup_file_path, file_path + strlen(file_path) + 1); // +1 to skip the last '/' in file_path
    strcat(backup_file_path, "_backup");
    strcat(backup_file_path, ".bak");

    // Open the original file for reading
    if ((file_fd = open(file_path, O_RDONLY)) < 0) {
        perror("Error opening file for reading");
        return;
    }

    // Open the backup file for writing
    if ((backup_fd = open(backup_file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error creating backup file");
        close(file_fd);
        return;
    }

    // Read the contents of the original file and write to the backup file
    ssize_t read_size;
    char buffer[4096];
    while ((read_size = read(file_fd, buffer, sizeof(buffer))) > 0) {
        write(backup_fd, buffer, read_size);
    }

    // Close the file descriptors
    close(file_fd);
    close(backup_fd);

    // Print a message to confirm the backup was created
    printf("Backup created: %s\n", backup_file_path);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    create_backup(argv[1]);

    return 0;
}