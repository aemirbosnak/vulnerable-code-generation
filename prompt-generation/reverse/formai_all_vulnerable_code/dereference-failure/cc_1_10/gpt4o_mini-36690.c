//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define BACKUP_DIR "backup"

// Function Prototypes
void createBackupDirectory();
void copyFile(const char *sourceFile, const char *backupFile);
void performBackup(const char *directory);
void listFiles(const char *directory);
void getCurrentTime(char *buffer, size_t size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_backup>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDirectory = argv[1];

    createBackupDirectory();
    performBackup(sourceDirectory);
    return EXIT_SUCCESS;
}

void createBackupDirectory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

void copyFile(const char *sourceFile, const char *backupFile) {
    int sourceFD = open(sourceFile, O_RDONLY);
    if (sourceFD < 0) {
        perror("Could not open source file");
        return;
    }

    int backupFD = open(backupFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backupFD < 0) {
        perror("Could not create backup file");
        close(sourceFD);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(sourceFD, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(backupFD, buffer, bytesRead);
        if (bytesWritten < 0) {
            perror("Error writing to backup file");
            break;
        }
    }

    close(sourceFD);
    close(backupFD);
}

void performBackup(const char *directory) {
    struct dirent *entry;
    DIR *dir = opendir(directory);
    char backupFilePath[256];
    char sourceFilePath[256];
    char currentTime[64];

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    getCurrentTime(currentTime, sizeof(currentTime));

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Check if it's a regular file
            snprintf(sourceFilePath, sizeof(sourceFilePath), "%s/%s", directory, entry->d_name);
            snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s_%s.bak", BACKUP_DIR, entry->d_name, currentTime);

            printf("Backing up: %s to %s\n", sourceFilePath, backupFilePath);
            copyFile(sourceFilePath, backupFilePath);
        }
    }

    closedir(dir);
}

void getCurrentTime(char *buffer, size_t size) {
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    strftime(buffer, size, "%Y%m%d_%H%M%S", timeinfo);
}