//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void createBackupDirectory(const char *backupDir) {
    // Create backup directory if it does not exist
    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        mkdir(backupDir, 0700);
    }
}

void copyFile(const char *sourceFile, const char *backupFile) {
    FILE *src = fopen(sourceFile, "rb");
    FILE *dest = fopen(backupFile, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    if (src == NULL) {
        perror("Error opening source file");
        return;
    }
    if (dest == NULL) {
        perror("Error opening backup file");
        fclose(src);
        return;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

void listBackedUpFiles(const char *backupDir) {
    struct dirent *entry;
    DIR *dp = opendir(backupDir);

    if (dp == NULL) {
        perror("Error opening backup directory");
        return;
    }

    printf("Backed Up Files:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(dp);
}

void backupFile(const char *backupDir, const char *fileToBackup) {
    char backupFilePath[256];
    snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s", backupDir, fileToBackup);
    
    copyFile(fileToBackup, backupFilePath);
    printf("Backed up %s to %s\n", fileToBackup, backupFilePath);
}

int main() {
    const char *backupDir = "backup";
    createBackupDirectory(backupDir);
    
    char fileToBackup[256];
    char choice;

    do {
        printf("Enter the path of the file to back up: ");
        scanf("%s", fileToBackup);
        backupFile(backupDir, fileToBackup);
        
        printf("Do you want to backup another file? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    listBackedUpFiles(backupDir);
    
    return 0;
}