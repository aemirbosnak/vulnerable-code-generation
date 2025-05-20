//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUP_COUNT 100

void createBackup(char fileName[], char backupFolder[]) {
    time_t currentTime;
    struct tm* localTime;
    char backupFileName[MAX_FILENAME_LENGTH];

    // Get local current time
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    // Generate backup file name
    sprintf(backupFileName, "%s_%04d%02d%02d_%02d%02d%02d.bak", fileName,
            localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
            localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    // Generate complete backup file path
    char backupFilePath[MAX_FILENAME_LENGTH];
    sprintf(backupFilePath, "%s/%s", backupFolder, backupFileName);

    // Open original file for reading
    FILE* originalFile = fopen(fileName, "r");
    if (originalFile == NULL) {
        printf("Error: Could not open file %s for reading.\n", fileName);
        return;
    }

    // Create backup file for writing
    FILE* backupFile = fopen(backupFilePath, "w");
    if (backupFile == NULL) {
        printf("Error: Could not create backup file %s.\n", backupFileName);
        fclose(originalFile);
        return;
    }

    // Copy contents of original file to backup file
    char buffer[1024];
    int count;
    while ((count = fread(buffer, sizeof(char), sizeof(buffer), originalFile)) > 0) {
        fwrite(buffer, sizeof(char), count, backupFile);
    }

    // Close files
    fclose(originalFile);
    fclose(backupFile);

    printf("Created backup file %s.\n", backupFileName);
}

void listBackups(char backupFolder[]) {
    char command[MAX_FILENAME_LENGTH + 10];
    sprintf(command, "ls %s", backupFolder);

    // Execute 'ls' command to list backup files
    FILE* listPipe = popen(command, "r");
    if (listPipe == NULL) {
        printf("Error: Could not list backup files.\n");
        return;
    }

    printf("Backup files:\n");

    char backupFileName[MAX_FILENAME_LENGTH];
    int backupCount = 0;
    while (fgets(backupFileName, sizeof(backupFileName), listPipe)) {
        // Strip newline character from file name
        strtok(backupFileName, "\n");

        printf("%d. %s\n", ++backupCount, backupFileName);

        // Stop listing backups if maximum count is reached
        if (backupCount >= MAX_BACKUP_COUNT) {
            break;
        }
    }

    pclose(listPipe);
}

void restoreBackup(char backupFolder[], int backupNumber, char restoreFileName[]) {
    char backupFileName[MAX_FILENAME_LENGTH];
    char command[MAX_FILENAME_LENGTH + 15];
    sprintf(backupFileName, "%s/%d_*", backupFolder, backupNumber);
    sprintf(command, "ls -tr %s | tail -1", backupFileName);

    // Get most recent backup file for the given backup number
    FILE* recentFilePipe = popen(command, "r");
    if (recentFilePipe == NULL) {
        printf("Error: Could not find backup file to restore.\n");
        return;
    }

    char backupFilePath[MAX_FILENAME_LENGTH];
    if (fgets(backupFilePath, sizeof(backupFilePath), recentFilePipe) == NULL) {
        printf("Error: Could not find backup file to restore.\n");
        pclose(recentFilePipe);
        return;
    }

    // Strip newline character from file path
    strtok(backupFilePath, "\n");

    pclose(recentFilePipe);

    // Open backup file for reading
    FILE* backupFile = fopen(backupFilePath, "r");
    if (backupFile == NULL) {
        printf("Error: Could not open backup file %s for reading.\n", backupFilePath);
        return;
    }

    // Create restore file for writing
    FILE* restoreFile = fopen(restoreFileName, "w");
    if (restoreFile == NULL) {
        printf("Error: Could not create restore file %s.\n", restoreFileName);
        fclose(backupFile);
        return;
    }

    // Copy contents of backup file to restore file
    char buffer[1024];
    int count;
    while ((count = fread(buffer, sizeof(char), sizeof(buffer), backupFile)) > 0) {
        fwrite(buffer, sizeof(char), count, restoreFile);
    }

    // Close files
    fclose(backupFile);
    fclose(restoreFile);

    printf("Restored backup file %s to %s.\n", backupFilePath, restoreFileName);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file name> [backup folder]\n", argv[0]);
        return 1;
    }

    char* fileName = argv[1];
    char backupFolder[MAX_FILENAME_LENGTH];
    if (argc >= 3) {
        // Use specified backup folder
        strncpy(backupFolder, argv[2], sizeof(backupFolder));
    }
    else {
        // Use default backup folder './backup'
        strcpy(backupFolder, "./backup");
    }

    // Create backup folder if it does not exist
    char command[MAX_FILENAME_LENGTH + 10];
    sprintf(command, "mkdir -p %s", backupFolder);
    system(command);

    printf("File Backup System\n");
    printf("==================\n");
    printf("File name: %s\n", fileName);
    printf("Backup folder: %s\n", backupFolder);

    // Create backup of file
    createBackup(fileName, backupFolder);

    // List available backups
    listBackups(backupFolder);

    // Restore backup
    int backupNumber;
    printf("Enter backup number to restore: ");
    scanf("%d", &backupNumber);

    char restoreFileName[MAX_FILENAME_LENGTH];
    printf("Enter restore file name: ");
    scanf("%s", restoreFileName);

    restoreBackup(backupFolder, backupNumber, restoreFileName);

    return 0;
}