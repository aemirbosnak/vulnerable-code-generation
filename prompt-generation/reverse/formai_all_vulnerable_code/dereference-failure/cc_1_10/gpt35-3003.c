//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define CHUNK_SIZE 1024
#define FILENAME_LENGTH 256

void createFolder(const char *name) {
    char command[FILENAME_LENGTH + 10] = "mkdir -p ";
    strcat(command, name);
    system(command);
}

void backupFile(char *filename, char *backupFolder) {
    char backupFilename[FILENAME_LENGTH] = "";
    strcat(backupFilename, backupFolder);
    strcat(backupFilename, "/");
    strcat(backupFilename, filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    FILE *backupFile = fopen(backupFilename, "wb");
    if (backupFile == NULL) {
        printf("Error creating backup file: %s\n", backupFilename);
        return;
    }

    char *buffer = malloc(CHUNK_SIZE * sizeof(char));
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), CHUNK_SIZE, file)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, backupFile);
    }

    fclose(file);
    fclose(backupFile);
    free(buffer);

    printf("Created backup for file: %s\n", filename);
}

int main(int argc, char **argv) {
    srand(time(NULL));

    char *filename = argv[1];
    char *backupFolder = argv[2];

    if (access(filename, F_OK) == -1) {
        printf("File does not exist: %s\n", filename);
        return 1;
    }

    createFolder(backupFolder);

    time_t rawTime;
    struct tm *timeInfo;
    char timestamp[20] = "";
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    strftime(timestamp, 20, "%Y%m%d_%H%M%S", timeInfo);

    char backupFolderWithTimestamp[FILENAME_LENGTH] = "";
    strcat(backupFolderWithTimestamp, backupFolder);
    strcat(backupFolderWithTimestamp, "/");
    strcat(backupFolderWithTimestamp, timestamp);
    createFolder(backupFolderWithTimestamp);

    char backupFilename[FILENAME_LENGTH] = "";
    char *dotPtr = strrchr(filename, '.');
    if (dotPtr == NULL) {
        sprintf(backupFilename, "%d", rand());
    } else {
        *dotPtr = '\0';
        sprintf(backupFilename, "%s_%d%s", filename, rand(), dotPtr);
        *dotPtr = '.';
    }

    backupFile(filename, backupFolderWithTimestamp);
    backupFile(backupFilename, backupFolderWithTimestamp);

    return 0;
}