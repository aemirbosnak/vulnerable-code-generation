//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void printWelcomeMessage() {
    printf("********************************\n");
    printf("* Welcome to Simple Backup System!\n");
    printf("* Designed with Love by ChatGPT.\n");
    printf("********************************\n");
}

void createBackupDirectory(const char *backupDir) {
    if (mkdir(backupDir, 0777) == -1) {
        perror("Error creating backup directory");
        exit(EXIT_FAILURE);
    }
}

void copyFile(const char *srcFile, const char *destFile) {
    FILE *source = fopen(srcFile, "rb");
    FILE *destination = fopen(destFile, "wb");
    
    if (!source || !destination) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    fclose(source);
    fclose(destination);
}

void backupFiles(const char *sourceDir, const char *backupDir) {
    struct dirent *entry;
    DIR *dp = opendir(sourceDir);
    
    if (dp == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only regular files
            char srcFile[MAX_PATH];
            char destFile[MAX_PATH];
            
            snprintf(srcFile, sizeof(srcFile), "%s/%s", sourceDir, entry->d_name);
            snprintf(destFile, sizeof(destFile), "%s/%s.bak", backupDir, entry->d_name);

            printf("Backing up %s to %s...\n", srcFile, destFile);
            copyFile(srcFile, destFile);
        }
    }
    
    closedir(dp);
    printf("Backup completed successfully!\n");
}

int main() {
    char sourceDir[MAX_PATH];
    char backupDir[MAX_PATH];
    
    printWelcomeMessage();
    
    // Input source directory from user
    printf("Enter the source directory to back up: ");
    fgets(sourceDir, sizeof(sourceDir), stdin);
    sourceDir[strcspn(sourceDir, "\n")] = 0; // Remove trailing newline

    // Input destination backup directory from user
    printf("Enter the backup directory: ");
    fgets(backupDir, sizeof(backupDir), stdin);
    backupDir[strcspn(backupDir, "\n")] = 0; // Remove trailing newline

    // Create backup directory if it does not exist
    struct stat st;
    if (stat(backupDir, &st) == -1) {
        createBackupDirectory(backupDir);
    } else if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Backup location exists, but is not a directory!\n");
        exit(EXIT_FAILURE);
    }

    // Perform the file backup process
    backupFiles(sourceDir, backupDir);

    return 0;
}