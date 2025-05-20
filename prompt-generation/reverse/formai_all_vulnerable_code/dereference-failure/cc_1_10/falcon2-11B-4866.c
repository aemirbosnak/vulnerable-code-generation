//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024 * 1024 // 1MB

// Function to backup a file to a new file
void backupFile(char* fileName, char* backupFileName) {
    FILE* file = fopen(fileName, "rb");
    FILE* backupFile = fopen(backupFileName, "wb");

    if (file == NULL || backupFile == NULL) {
        printf("Error: Could not open file for backup\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(fileSize + 1);
    fread(buffer, fileSize, 1, file);
    fclose(file);

    fwrite(buffer, fileSize, 1, backupFile);
    free(buffer);
    fclose(backupFile);

    printf("Backup completed: %s\n", backupFileName);
}

// Main function
int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    char backupFileName[MAX_FILE_NAME_LENGTH];

    // Get file name from user
    printf("Enter the file name: ");
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);

    // Get backup file name from user
    printf("Enter the backup file name: ");
    fgets(backupFileName, MAX_FILE_NAME_LENGTH, stdin);

    // Check if file name is valid
    if (strlen(fileName) == 0) {
        printf("Error: File name cannot be empty\n");
        return 1;
    }

    if (strlen(backupFileName) == 0) {
        printf("Error: Backup file name cannot be empty\n");
        return 1;
    }

    // Check if file exists
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: File does not exist\n");
        return 1;
    }

    // Backup file
    backupFile(fileName, backupFileName);

    return 0;
}