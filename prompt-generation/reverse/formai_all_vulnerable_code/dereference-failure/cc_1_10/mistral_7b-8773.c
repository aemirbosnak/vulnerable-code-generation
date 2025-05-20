//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUPS 10

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char backupFileName[MAX_FILE_NAME_LENGTH];
    time_t backupTime;
} FileEntry;

FileEntry backups[MAX_BACKUPS];
int backupIndex = 0;

void createBackup(char *filePath) {
    FILE *sourceFile = fopen(filePath, "rb");
    FILE *backupFile = NULL;
    char fileName[MAX_FILE_NAME_LENGTH];
    strcpy(fileName, filePath);
    strcat(fileName, ".bkp");

    if (sourceFile == NULL) {
        printf("Error: Unable to open source file.\n");
        return;
    }

    backupFile = fopen(fileName, "wb");

    if (backupFile == NULL) {
        printf("Error: Unable to create backup file.\n");
        fclose(sourceFile);
        return;
    }

    fseek(sourceFile, 0, SEEK_END);
    long fileSize = ftell(sourceFile);
    fseek(sourceFile, 0, SEEK_SET);

    char buffer[fileSize];
    fread(buffer, fileSize, 1, sourceFile);
    fwrite(buffer, fileSize, 1, backupFile);

    strcpy(backups[backupIndex].fileName, fileName);
    strcpy(backups[backupIndex].backupFileName, filePath);
    backups[backupIndex].backupTime = time(NULL);

    printf("Backup created successfully: %s -> %s\n", filePath, fileName);
    fclose(sourceFile);
    fclose(backupFile);

    if (backupIndex >= MAX_BACKUPS - 1) {
        printf("Warning: Maximum backups limit reached.\n");
        remove(fileName);
    } else {
        backupIndex++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    createBackup(argv[1]);

    for (int i = 0; i < backupIndex; i++) {
        printf("\nBackup Details:\n");
        printf("File: %s\n", backups[i].fileName);
        printf("Backup: %s\n", backups[i].backupFileName);
        printf("Time: %s", ctime(&backups[i].backupTime));
    }

    return 0;
}