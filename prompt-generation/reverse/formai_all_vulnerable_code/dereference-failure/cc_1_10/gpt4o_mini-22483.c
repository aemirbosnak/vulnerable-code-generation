//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void printUsage() {
    printf("Usage: ./backup <source_directory> <backup_directory>\n");
}

int createBackup(const char *sourceDir, const char *backupDir) {
    DIR *dir = opendir(sourceDir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Unable to open source directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char sourcePath[MAX_PATH];
            char backupPath[MAX_PATH];

            snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
            snprintf(backupPath, sizeof(backupPath), "%s/%s", backupDir, entry->d_name);

            // Check file type
            struct stat statbuf;
            if (stat(sourcePath, &statbuf) == -1) {
                perror("Stat error");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                // It's a directory, create it in the backup
                mkdir(backupPath, 0755);
                // Recursively backup this directory
                createBackup(sourcePath, backupPath);
            } else if (S_ISREG(statbuf.st_mode)) {
                // It's a regular file, copy it
                FILE *sourceFile = fopen(sourcePath, "rb");
                FILE *destFile = fopen(backupPath, "wb");

                if (sourceFile == NULL || destFile == NULL) {
                    perror("File open error");
                    if (sourceFile) fclose(sourceFile);
                    continue;
                }

                char buffer[BUFFER_SIZE];
                size_t bytesRead;
                while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                    fwrite(buffer, 1, bytesRead, destFile);
                }

                fclose(sourceFile);
                fclose(destFile);
            }
        }
    }
    
    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *backupDir = argv[2];

    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        mkdir(backupDir, 0755);
    }

    if (createBackup(sourceDir, backupDir) == -1) {
        return EXIT_FAILURE;
    }

    printf("Backup completed successfully from '%s' to '%s'\n", sourceDir, backupDir);
    return EXIT_SUCCESS;
}