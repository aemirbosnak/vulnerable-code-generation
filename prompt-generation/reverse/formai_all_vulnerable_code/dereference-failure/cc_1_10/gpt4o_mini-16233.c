//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
#define MAX_DIR_NAME 256

void checkError(int status, const char *message) {
    if (status != 0) {
        perror(message);
        exit(EXIT_FAILURE);
    }
}

void createDirectory(const char *dirName) {
    struct stat st = {0};
    if (stat(dirName, &st) == -1) {
        printf("Creating directory: %s\n", dirName);
        checkError(mkdir(dirName, 0700), "Failed to create directory");
    } else {
        printf("Directory already exists: %s\n", dirName);
    }
}

void backupFile(const char *sourceFile, const char *destDirectory) {
    FILE *src = fopen(sourceFile, "rb");
    checkError(src != NULL ? 0 : -1, "Unable to open source file");

    char destFile[MAX_DIR_NAME + MAX_FILE_NAME];
    snprintf(destFile, sizeof(destFile), "%s/%s.bak", destDirectory, strrchr(sourceFile, '/') ? strrchr(sourceFile, '/') + 1 : sourceFile);

    FILE *dest = fopen(destFile, "wb");
    checkError(dest != NULL ? 0 : -1, "Unable to create destination file");

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    printf("Backup created: %s\n", destFile);

    fclose(src);
    fclose(dest);
}

void getUserInput(char *sourceFile, char *destDirectory) {
    printf("Enter the path of the file to backup: ");
    fgets(sourceFile, MAX_FILE_NAME, stdin);
    sourceFile[strcspn(sourceFile, "\n")] = 0; // Remove newline character
    
    printf("Enter the destination directory for backup: ");
    fgets(destDirectory, MAX_DIR_NAME, stdin);
    destDirectory[strcspn(destDirectory, "\n")] = 0; // Remove newline character
}

int main() {
    char sourceFile[MAX_FILE_NAME];
    char destDirectory[MAX_DIR_NAME];

    getUserInput(sourceFile, destDirectory);
    createDirectory(destDirectory);
    backupFile(sourceFile, destDirectory);

    return 0;
}