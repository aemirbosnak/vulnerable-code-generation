//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void createBackupDirectory(const char *backupPath) {
    struct stat st = {0};

    if (stat(backupPath, &st) == -1) {
        mkdir(backupPath, 0700);
    }
}

void copyFile(const char *source, const char *destination) {
    FILE *srcFile = fopen(source, "rb");
    FILE *destFile = fopen(destination, "wb");

    if (srcFile == NULL || destFile == NULL) {
        perror("Error opening file");
        if (srcFile) fclose(srcFile);
        if (destFile) fclose(destFile);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

void backupFiles(const char *sourceDir, const char *backupDir) {
    DIR *dir = opendir(sourceDir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char sourcePath[512];
            char destPath[512];
            snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", backupDir, entry->d_name);
            copyFile(sourcePath, destPath);
        }
    }

    closedir(dir);
}

void promptUser() {
    printf("File Backup System\n");
    printf("===================\n");
    printf("1. Backup files\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char *sourceDir = malloc(512);
    char *backupDir = malloc(512);

    if (sourceDir == NULL || backupDir == NULL) {
        perror("Unable to allocate memory");
        return EXIT_FAILURE;
    }

    int option;

    do {
        promptUser();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the source directory: ");
                scanf("%s", sourceDir);
                printf("Enter the backup directory: ");
                scanf("%s", backupDir);

                createBackupDirectory(backupDir);
                backupFiles(sourceDir, backupDir);
                
                printf("Backup completed successfully!\n");
                break;

            case 2:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (option != 2);

    free(sourceDir);
    free(backupDir);
    return EXIT_SUCCESS;
}