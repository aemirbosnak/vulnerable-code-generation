//FormAI DATASET v1.0 Category: File Backup System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILENAME_LEN 1024
#define MAX_TIME_LEN 256
#define MAX_BACKUP_FILES 5

void createBackupDirectory(char* directoryName) {
    mkdir(directoryName, S_IRWXU | S_IRWXG | S_IRWXO);
}

void createBackupFilename(char* originalFilename, char* backupFilename) {
    time_t currTime;
    struct tm* timeInfo;

    time(&currTime);
    timeInfo = localtime(&currTime);

    char timeStr[MAX_TIME_LEN];
    strftime(timeStr, MAX_TIME_LEN, "_%Y-%m-%d_%H-%M-%S", timeInfo);

    char* filenameExtension = strrchr(originalFilename, '.');
    if (filenameExtension == NULL) {
        filenameExtension = "";
    }
    snprintf(backupFilename, MAX_FILENAME_LEN, "%s/%s%s%s", "backup", originalFilename, timeStr, filenameExtension);
}

void copyFile(char* originalFilename, char* backupFilename) {
    FILE* originalFile = fopen(originalFilename, "r");
    FILE* backupFile = fopen(backupFilename, "w");
    if (originalFile == NULL || backupFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(originalFile)) != EOF) {
        fputc(ch, backupFile);
    }

    fclose(originalFile);
    fclose(backupFile);
}

void backupFile(char* originalFilename) {
    char backupFilename[MAX_FILENAME_LEN];
    createBackupFilename(originalFilename, backupFilename);
    copyFile(originalFilename, backupFilename);
}

void cleanupOldBackups(char* directoryName) {
    DIR* dir;
    struct dirent* entry;
    char filePath[MAX_FILENAME_LEN];

    dir = opendir(directoryName);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    int numBackupFiles = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            numBackupFiles++;
        }
    }

    rewinddir(dir);

    while (numBackupFiles > MAX_BACKUP_FILES && (entry = readdir(dir)) != NULL) {
        snprintf(filePath, MAX_FILENAME_LEN, "%s/%s", directoryName, entry->d_name);
        remove(filePath);
        numBackupFiles--;
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    createBackupDirectory("backup");

    backupFile(argv[1]);

    cleanupOldBackups("backup");

    return EXIT_SUCCESS;
}