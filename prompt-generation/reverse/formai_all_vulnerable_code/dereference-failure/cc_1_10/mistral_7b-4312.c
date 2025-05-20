//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 100

void backup_file(char *filename) {
    char backup_filename[MAX_FILENAME_LENGTH];
    int fd_original, fd_backup;
    char buffer[4096];
    struct stat file_stats;

    // Create backup filename
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    // Open original file for reading
    if ((fd_original = open(filename, O_RDONLY)) < 0) {
        perror("Error opening original file");
        return;
    }

    // Open backup file for writing
    if ((fd_backup = open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error creating backup file");
        close(fd_original);
        return;
    }

    // Read and write contents of original file to backup file
    ssize_t bytes_read;
    while ((bytes_read = read(fd_original, buffer, sizeof(buffer))) > 0) {
        write(fd_backup, buffer, bytes_read);
    }

    // Check for errors during read or write operations
    if (bytes_read < 0) {
        perror("Error reading or writing files");
    }

    // Close files
    close(fd_original);
    close(fd_backup);

    // Print success message
    printf("Backup of %s created successfully.\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}