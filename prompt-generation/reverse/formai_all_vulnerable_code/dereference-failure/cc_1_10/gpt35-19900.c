//FormAI DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_LENGTH 64

void createBackup(char *filename);
void removeOldestBackup(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    createBackup(filename);

    return 0;
}

void createBackup(char *filename) {
    char backupName[MAX_FILENAME_LENGTH];
    char timestamp[MAX_BACKUP_LENGTH];

    time_t now = time(NULL);
    strftime(timestamp, MAX_BACKUP_LENGTH, "_%Y-%m-%d_%H-%M-%S", localtime(&now));

    snprintf(backupName, MAX_FILENAME_LENGTH, "%s%s", filename, timestamp);

    FILE *sourceFile = fopen(filename, "r");
    if (sourceFile == NULL) {
        printf("File %s does not exist.\n", filename);
        return;
    }

    FILE *backupFile = fopen(backupName, "w");
    if (backupFile == NULL) {
        printf("Failed to create backup file.\n");
        return;
    }

    int bufferSize = 1024 * 1024;  // 1 MB
    char buffer[bufferSize];

    while (!feof(sourceFile)) {
        size_t readBytes = fread(buffer, 1, bufferSize, sourceFile);

        if (ferror(sourceFile)) {
            printf("An error occurred while reading the file.\n");
            return;
        }

        fwrite(buffer, 1, readBytes, backupFile);

        if (ferror(backupFile)) {
            printf("Failed to create backup file.\n");
            return;
        }
    }

    fclose(sourceFile);
    fclose(backupFile);

    removeOldestBackup(filename);
}

void removeOldestBackup(char *filename) {
    char command[MAX_FILENAME_LENGTH + 10];
    snprintf(command, MAX_FILENAME_LENGTH + 10, "ls %s_* | sort | head -n -5 | xargs rm", filename);
    system(command);
}