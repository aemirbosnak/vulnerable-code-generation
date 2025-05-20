//FormAI DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 50
#define MAX_BACKUP_FOLDER 100

void createBackupFolder(char* backupDir) {
    time_t currentTime;
    char timestamp[MAX_FILE_NAME];
    struct tm* backupTimeInfo;

    // Get current time
    currentTime = time(NULL);
    backupTimeInfo = localtime(&currentTime);

    // Create backup folder with timestamp
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H-%M-%S", backupTimeInfo);
    sprintf(backupDir, "%s/%s", MAX_BACKUP_FOLDER, timestamp);
    mkdir(backupDir, 0777);
}

void backupFile(char* fileName, char* backupDir) {
    // Calculate the length of the file name
    int fileNameLength = strlen(fileName);
    char backupFilePath[MAX_FILE_NAME + MAX_BACKUP_FOLDER];

    // Create backup file path
    sprintf(backupFilePath, "%s/%s", backupDir, fileName);

    // Open both files and copy the contents of the source file to the backup file
    FILE* inputFile = fopen(fileName, "r");
    FILE* backupFile = fopen(backupFilePath, "w");
    if (inputFile == NULL || backupFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), sizeof(buffer), inputFile))) {
        fwrite(buffer, sizeof(char), bytes, backupFile);
    }

    // Close files
    fclose(inputFile);
    fclose(backupFile);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 0;
    }

    char backupDir[MAX_BACKUP_FOLDER + MAX_FILE_NAME];

    // Create backup folder with timestamp
    createBackupFolder(backupDir);
    printf("Created backup folder: %s\n", backupDir);

    // Backup file
    backupFile(argv[1], backupDir);
    printf("Backup created: %s/%s\n", backupDir, argv[1]);

    return 0;
}