//FormAI DATASET v1.0 Category: File Backup System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_PATH_LENGTH 1024
#define MAX_NUM_BACKUPS 10

// Function to get the current date and time as a string
char *getCurrentDateTime() {
    time_t currentTime;
    struct tm *localTime;
    static char dateTime[50];
    
    time(&currentTime);
    localTime = localtime(&currentTime);
    
    strftime(dateTime, sizeof(dateTime), "%Y-%m-%d_%H-%M-%S", localTime);
    
    return dateTime;
}

// Function to create a backup of a file
int createBackup(char *filename, char *backupPath) {
    char *dateTime = getCurrentDateTime();
    char backupFilename[MAX_FILENAME_LENGTH];
    sprintf(backupFilename, "%s_%s", dateTime, filename);
    
    char backupFilePath[MAX_BACKUP_PATH_LENGTH];
    sprintf(backupFilePath, "%s/%s", backupPath, backupFilename);
    
    FILE *sourceFile = fopen(filename, "r");
    FILE *backupFile = fopen(backupFilePath, "w");
    
    if (sourceFile == NULL || backupFile == NULL) {
        printf("Error: Could not open file(s)!\n");
        return -1;
    }
    
    char buffer[1024];
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }
    
    fclose(sourceFile);
    fclose(backupFile);
    
    printf("Successfully created backup file: %s\n", backupFilePath);
    
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: fileBackupSystem [filename] [backup path]\n");
        return -1;
    }
    
    char *filename = argv[1];
    char *backupPath = argv[2];
    
    int backupCount = 0;
    char existingBackupFilename[MAX_FILENAME_LENGTH];
    char newBackupFilename[MAX_FILENAME_LENGTH];
    char existingBackupFilePath[MAX_BACKUP_PATH_LENGTH];
    char newBackupFilePath[MAX_BACKUP_PATH_LENGTH];
    
    // Check if the backup directory exists
    if (access(backupPath, F_OK) != 0) {
        printf("Error: Backup directory does not exist!\n");
        return -1;
    }
    
    // Check if the file exists
    if (access(filename, F_OK) != 0) {
        printf("Error: File does not exist!\n");
        return -1;
    }
    
    // Check if there are already too many backups
    for (int i = 0; i < MAX_NUM_BACKUPS; i++) {
        sprintf(existingBackupFilename, "%s.%d", filename, i);
        sprintf(existingBackupFilePath, "%s/%s", backupPath, existingBackupFilename);
        
        if (access(existingBackupFilePath, F_OK) != 0) {
            break;
        }
        
        backupCount++;
    }
    
    if (backupCount == MAX_NUM_BACKUPS) {
        printf("Error: Maximum number of backups reached!\n");
        return -1;
    }
    
    // Create new backup filename
    sprintf(newBackupFilename, "%s.%d", filename, backupCount);
    sprintf(newBackupFilePath, "%s/%s", backupPath, newBackupFilename);
    
    // Create backup
    if (createBackup(filename, backupPath) != 0) {
        printf("Error: Could not create backup!\n");
        return -1;
    }
    
    return 0;
}