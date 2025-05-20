//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>

// Define color codes for mystic messages
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

void createBackupDirectory(const char *backupDir) {
    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        if (mkdir(backupDir, 0700) != 0) {
            perror("Error creating backup directory");
            exit(EXIT_FAILURE);
        }
        printf(GREEN "The sacred backup directory '%s' has been conjured into existence!" RESET "\n", backupDir);
    } else {
        printf(YELLOW "Ah! The backup directory '%s' already exists, ready to receive your treasures!" RESET "\n", backupDir);
    }
}

void copyFile(const char *sourcePath, const char *destPath) {
    FILE *sourceFile = fopen(sourcePath, "rb");
    if (!sourceFile) {
        perror("Failed to open source file");
        return;
    }

    FILE *destFile = fopen(destPath, "wb");
    if (!destFile) {
        perror("Failed to create destination file");
        fclose(sourceFile);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf(BLUE "The file '%s' has been successfully copied to '%s'!" RESET "\n", sourcePath, destPath);
}

void backupFiles(const char *files[], int fileCount, const char *backupDir) {
    for (int i = 0; i < fileCount; i++) {
        const char *fileName = files[i];

        char destPath[512];
        snprintf(destPath, sizeof(destPath), "%s/%s.bak", backupDir, fileName);

        printf(YELLOW "Preparing to back up file: '%s'..." RESET "\n", fileName);
        copyFile(fileName, destPath);
    }
}

void listFilesInBackupDirectory(const char *backupDir) {
    struct dirent *entry;
    DIR *dp = opendir(backupDir);

    if (dp == NULL) {
        perror("Failed to open backup directory");
        return;
    }

    printf(GREEN "Listing all the protected treasures in the backup vault:\n" RESET);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(dp);
}

int main() {
    const char *backupDir = "my_backup_vault";
    createBackupDirectory(backupDir);
    
    const char *filesToBackup[] = { "file1.txt", "file2.txt", "important_document.docx", "magic_image.png" };
    int fileCount = sizeof(filesToBackup) / sizeof(filesToBackup[0]);

    backupFiles(filesToBackup, fileCount, backupDir);
    
    listFilesInBackupDirectory(backupDir);

    printf(GREEN "The backup ritual has concluded successfully! Your files are safe and sound!\n" RESET);
    
    return 0;
}