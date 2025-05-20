//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 1024

// Function prototypes
void displayMenu();
void backupFile(const char *source, const char *destination);
void backupDirectory(const char *sourceDir, const char *destDir);
void copyFile(const char *sourceFile, const char *destFile);
int isDirectory(const char *path);

int main() {
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];
    int choice;

    printf("Welcome to the File Backup System!\n");

    while (1) {
        displayMenu();
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the source file path: ");
                scanf("%s", source);
                printf("Enter the destination file path: ");
                scanf("%s", destination);
                backupFile(source, destination);
                break;
                
            case 2:
                printf("Enter the source directory path: ");
                scanf("%s", source);
                printf("Enter the destination directory path: ");
                scanf("%s", destination);
                backupDirectory(source, destination);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- File Backup System Menu ---\n");
    printf("1. Backup a File\n");
    printf("2. Backup a Directory\n");
    printf("3. Exit\n");
}

void backupFile(const char *source, const char *destination) {
    printf("Backing up file from %s to %s\n", source, destination);
    copyFile(source, destination);
}

void backupDirectory(const char *sourceDir, const char *destDir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(sourceDir)) == NULL) {
        perror("Unable to open source directory");
        return;
    }

    // Create destination directory
    struct stat st = {0};
    if (stat(destDir, &st) == -1) {
        mkdir(destDir, 0700);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char sourcePath[MAX_PATH_LENGTH];
            char destPath[MAX_PATH_LENGTH];

            snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

            if (isDirectory(sourcePath)) {
                backupDirectory(sourcePath, destPath);
            } else {
                printf("Backing up file from %s to %s\n", sourcePath, destPath);
                copyFile(sourcePath, destPath);
            }
        }
    }
    closedir(dir);
}

void copyFile(const char *sourceFile, const char *destFile) {
    FILE *sourcePtr, *destPtr;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    sourcePtr = fopen(sourceFile, "rb");
    if (sourcePtr == NULL) {
        perror("Failed to open the source file");
        return;
    }

    destPtr = fopen(destFile, "wb");
    if (destPtr == NULL) {
        perror("Failed to create the destination file");
        fclose(sourcePtr);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourcePtr)) > 0) {
        fwrite(buffer, 1, bytesRead, destPtr);
    }

    fclose(sourcePtr);
    fclose(destPtr);
    printf("Backup completed successfully for %s\n", sourceFile);
}

int isDirectory(const char *path) {
    struct stat pathStat;
    stat(path, &pathStat);
    return S_ISDIR(pathStat.st_mode);
}