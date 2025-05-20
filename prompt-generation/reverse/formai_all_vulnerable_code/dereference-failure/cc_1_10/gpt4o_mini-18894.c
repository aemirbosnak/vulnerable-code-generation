//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILENAME_MAX_LENGTH 256

void copyFile(const char *source, const char *destination) {
    FILE *srcFile = fopen(source, "rb");
    if (!srcFile) {
        perror("Error opening source file");
        return;
    }

    FILE *destFile = fopen(destination, "wb");
    if (!destFile) {
        perror("Error opening destination file");
        fclose(srcFile);
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

void backupFile(const char *filePath, const char *backupDir) {
    char backupPath[FILENAME_MAX_LENGTH];
    snprintf(backupPath, sizeof(backupPath), "%s/%s.bak", backupDir, strrchr(filePath, '/') + 1);
    copyFile(filePath, backupPath);
    printf("Backup created: %s\n", backupPath);
}

void backupDirectory(const char *dirPath, const char *backupDir) {
    DIR *dir = opendir(dirPath);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and current/parent directory entries
        }

        char fullPath[FILENAME_MAX_LENGTH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        
        struct stat pathStat;
        stat(fullPath, &pathStat);
        
        if (S_ISDIR(pathStat.st_mode)) {
            char newBackupDir[FILENAME_MAX_LENGTH];
            snprintf(newBackupDir, sizeof(newBackupDir), "%s/%s", backupDir, entry->d_name);
            mkdir(newBackupDir, 0755); // Create a new directory for the backup
            backupDirectory(fullPath, newBackupDir); // Recursive backup of the directory
        } else {
            backupFile(fullPath, backupDir);
        }
    }

    closedir(dir);
}

void createBackup(const char *source, const char *destination) {
    struct stat pathStat;
    if (stat(source, &pathStat) != 0) {
        perror("Source path does not exist");
        return;
    }

    if (S_ISDIR(pathStat.st_mode)) {
        mkdir(destination, 0755); // Create backup directory if it doesn't exist
        backupDirectory(source, destination);
    } else {
        backupFile(source, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    createBackup(argv[1], argv[2]);
    printf("Backup operation completed.\n");
    
    return EXIT_SUCCESS;
}