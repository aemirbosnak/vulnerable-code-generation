//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_FILE_EXTENSION ".bak"

// Function to create a backup file
void createBackup(char *fileName) {
    int fileDescriptor = open(fileName, O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening file for read");
        return;
    }

    char backupFileName[MAX_FILE_NAME_LENGTH];
    strcpy(backupFileName, fileName);
    strcat(backupFileName, BACKUP_FILE_EXTENSION);

    int backupFileDescriptor = open(backupFileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backupFileDescriptor == -1) {
        perror("Error opening file for write");
        close(fileDescriptor);
        return;
    }

    ssize_t bytesRead;
    char buffer[4096];
    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        write(backupFileDescriptor, buffer, bytesRead);
    }

    close(fileDescriptor);
    close(backupFileDescriptor);
}

// Function to check if a file has been modified
int fileHasBeenModified(char *fileName) {
    struct stat fileStats;
    int fileDescriptor = open(fileName, O_RDONLY);

    if (stat(fileName, &fileStats) == -1) {
        perror("Error getting file statistics");
        close(fileDescriptor);
        return -1;
    }

    close(fileDescriptor);

    struct stat backupFileStats;
    char backupFileName[MAX_FILE_NAME_LENGTH];
    strcpy(backupFileName, fileName);
    strcat(backupFileName, BACKUP_FILE_EXTENSION);

    if (stat(backupFileName, &backupFileStats) == -1) {
        perror("Error getting backup file statistics");
        return -1;
    }

    if (fileStats.st_mtime != backupFileStats.st_mtime) {
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char fileName[MAX_FILE_NAME_LENGTH];
    strcpy(fileName, argv[1]);

    while (1) {
        if (fileHasBeenModified(fileName)) {
            createBackup(fileName);
            printf("File %s has been modified. Backup created.\n", fileName);
        }

        usleep(100000); // Sleep for 100ms before checking again
    }

    return 0;
}