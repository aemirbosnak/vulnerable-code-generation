//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BACKUP_NUM 10
#define MAX_TIME_FORMAT 64

// Utility function to get current time in a specific format
char* getFormattedTime() {
    time_t rawtime = time(NULL);
    struct tm* timeinfo = localtime(&rawtime);
    char* buffer = (char*) malloc(MAX_TIME_FORMAT * sizeof(char));
    strftime(buffer, MAX_TIME_FORMAT, "%Y%m%d_%H%M%S", timeinfo);
    return buffer;
}

// Recursive function to backup all files and subdirectories in a directory
void backupDirectory(const char* sourceDir, const char* targetDir, int backupCount) {
    DIR* dir = opendir(sourceDir);
    if (dir == NULL) {
        printf("Error: could not open source directory '%s'\n", sourceDir);
        return;
    }

    // Create target directory with a unique name based on current time and backup number
    char* backupTime = getFormattedTime();
    char* backupDir = (char*) malloc(MAX_PATH_LENGTH * sizeof(char));
    sprintf(backupDir, "%s/%s_backup_%d", targetDir, backupTime, backupCount);
    mkdir(backupDir, 0777);
    free(backupTime);

    // Traverse all files and subdirectories in source directory
    struct dirent* dirEntry = readdir(dir);
    while (dirEntry != NULL) {
        char* entryName = dirEntry->d_name;
        if (strcmp(entryName, ".") == 0 || strcmp(entryName, "..") == 0) {
            // Ignore current and parent directories
        } else {
            // Create full path names for source file/directory and target file/directory
            char* sourcePath = (char*) malloc(MAX_PATH_LENGTH * sizeof(char));
            char* targetPath = (char*) malloc(MAX_PATH_LENGTH * sizeof(char));
            sprintf(sourcePath, "%s/%s", sourceDir, entryName);
            sprintf(targetPath, "%s/%s", backupDir, entryName);

            // Check if entry is a file or a directory
            struct stat entryStat;
            stat(sourcePath, &entryStat);
            if (S_ISREG(entryStat.st_mode)) {
                // Entry is a file, copy it to target directory
                FILE* sourceFile = fopen(sourcePath, "rb");
                FILE* targetFile = fopen(targetPath, "wb");
                if (sourceFile == NULL || targetFile == NULL) {
                    printf("Error: could not open file '%s' or '%s'\n", sourcePath, targetPath);
                } else {
                    char buffer[1024];
                    size_t size;
                    while ((size = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                        fwrite(buffer, 1, size, targetFile);
                    }
                    printf("Copied file '%s' to '%s'\n", sourcePath, targetPath);
                    fclose(sourceFile);
                    fclose(targetFile);
                }
            } else if (S_ISDIR(entryStat.st_mode)) {
                // Entry is a directory, recurse on it
                backupDirectory(sourcePath, backupDir, backupCount + 1);
            }

            free(sourcePath);
            free(targetPath);
        }

        dirEntry = readdir(dir);
    }

    closedir(dir);
}

int main() {
    const char* sourceDir = "/path/to/source/directory";
    const char* targetDir = "/path/to/target/directory";
    char* backupTime = getFormattedTime();
    char* backupDir = (char*) malloc(MAX_PATH_LENGTH * sizeof(char));
    sprintf(backupDir, "%s/%s_initial_backup", targetDir, backupTime);
    mkdir(backupDir, 0777);
    free(backupTime);

    backupDirectory(sourceDir, backupDir, 1);

    printf("Backup completed successfully\n");
    return 0;
}