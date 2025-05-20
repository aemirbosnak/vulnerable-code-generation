//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void displayFileList(const char *directory);
int createBackup(const char *sourceFile, const char *backupDir);
int isDirectoryExists(const char *dirPath);
void printUsage(const char *programName);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDirectory = argv[1];
    const char *backupDirectory = argv[2];

    if (!isDirectoryExists(sourceDirectory)) {
        fprintf(stderr, "Error: Source directory does not exist or cannot be accessed.\n");
        return EXIT_FAILURE;
    }

    if (!isDirectoryExists(backupDirectory)) {
        fprintf(stderr, "Error: Backup directory does not exist or cannot be accessed.\n");
        return EXIT_FAILURE;
    }

    printf("Files in directory '%s' to backup:\n", sourceDirectory);
    displayFileList(sourceDirectory);

    struct dirent *entry;
    DIR *dp = opendir(sourceDirectory);
    
    if (dp == NULL) {
        fprintf(stderr, "Error: Could not open source directory.\n");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char sourceFilePath[1024];
            snprintf(sourceFilePath, sizeof(sourceFilePath), "%s/%s", sourceDirectory, entry->d_name);
            if (createBackup(sourceFilePath, backupDirectory) == 0) {
                printf("Successfully backed up: %s\n", entry->d_name);
            } else {
                fprintf(stderr, "Failed to backup: %s\n", entry->d_name);
            }
        }
    }

    closedir(dp);
    return EXIT_SUCCESS;
}

void displayFileList(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        fprintf(stderr, "Error: Could not open directory to display files.\n");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(dp);
}

int createBackup(const char *sourceFile, const char *backupDir) {
    char backupFilePath[1024];
    snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s.bak", backupDir, strrchr(sourceFile, '/') + 1);

    FILE *source = fopen(sourceFile, "rb");
    if (source == NULL) {
        return -1; // Source file open error
    }

    FILE *backup = fopen(backupFilePath, "wb");
    if (backup == NULL) {
        fclose(source);
        return -1; // Backup file open error
    }

    char buffer[8192];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, backup);
    }

    fclose(source);
    fclose(backup);
    return 0; // Success
}

int isDirectoryExists(const char *dirPath) {
    struct stat st;
    return (stat(dirPath, &st) == 0 && S_ISDIR(st.st_mode));
}

void printUsage(const char *programName) {
    printf("Usage: %s <source_directory> <backup_directory>\n", programName);
    printf("This program backs up all files from the source directory to the backup directory.\n");
}