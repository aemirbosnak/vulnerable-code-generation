//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_PATH_LENGTH 1024

void createBackupDirectoryIfNotExists(char *backupPath) {
    // Check if backup directory exists, otherwise create it
    DIR *backupDir = opendir(backupPath);
    if (backupDir) {
        closedir(backupDir);
    } else {
        printf("Backup directory not found. Creating %s...\n", backupPath);
        if (mkdir(backupPath, 0700) == -1) {
            fprintf(stderr, "Error: could not create backup directory %s\n", backupPath);
            exit(EXIT_FAILURE);
        }
    }
}

void getTimestamp(char *timestamp) {
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(timestamp, MAX_FILENAME_LENGTH, "%Y%m%d-%H%M%S", timeInfo);
}

void backupFile(char *filePath, char *backupPath) {
    char backupFilePath[MAX_BACKUP_PATH_LENGTH];
    char timestamp[MAX_FILENAME_LENGTH];

    // Generate backup file path
    getTimestamp(timestamp);
    sprintf(backupFilePath, "%s/%s_%s", backupPath, timestamp, strrchr(filePath, '/') + 1);

    // Copy file to backup directory
    FILE *sourceFile = fopen(filePath, "r");
    FILE *backupFile = fopen(backupFilePath, "w");
    if (sourceFile == NULL) {
        fprintf(stderr, "Error: could not open source file %s for backup.\n", filePath);
        exit(EXIT_FAILURE);
    }
    if (backupFile == NULL) {
        fprintf(stderr, "Error: could not create backup file %s.\n", backupFilePath);
        exit(EXIT_FAILURE);
    }
    int c;
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, backupFile);
    }
    fclose(sourceFile);
    fclose(backupFile);

    printf("File %s backed up as %s.\n", filePath, backupFilePath);
}

void backupDirectory(char *directoryPath, char *backupPath) {
    DIR *directory = opendir(directoryPath);
    struct dirent *entry;
    char filePath[MAX_FILENAME_LENGTH];

    if (directory == NULL) {
        fprintf(stderr, "Error: could not open directory %s.\n", directoryPath);
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Recursively backup directories
            char subdirectoryPath[MAX_FILENAME_LENGTH];
            sprintf(subdirectoryPath, "%s/%s", directoryPath, entry->d_name);
            backupDirectory(subdirectoryPath, backupPath);
        } else if (entry->d_type == DT_REG) {
            // Backup regular files
            sprintf(filePath, "%s/%s", directoryPath, entry->d_name);
            backupFile(filePath, backupPath);
        }
    }
    closedir(directory);
}

int main(int argc, char *argv[]) {
    char *directoryPath, *backupPath;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_path> <backup_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    directoryPath = argv[1];
    backupPath = argv[2];

    createBackupDirectoryIfNotExists(backupPath);
    backupDirectory(directoryPath, backupPath);

    printf("Backup complete.\n");
    exit(EXIT_SUCCESS);
}