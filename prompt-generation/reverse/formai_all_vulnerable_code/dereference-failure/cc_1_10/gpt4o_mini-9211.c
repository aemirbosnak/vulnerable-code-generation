//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define LOG_FILE "backup_log.txt"

void logActivity(const char *message) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile) {
        fprintf(logFile, "%s\n", message);
        fclose(logFile);
    }
}

void copyFile(const char *source, const char *destination) {
    FILE *srcFile = fopen(source, "rb");
    if (!srcFile) {
        printf("Error: Could not open source file %s for reading.\n", source);
        logActivity("Failed to open source file for reading.");
        return;
    }

    FILE *destFile = fopen(destination, "wb");
    if (!destFile) {
        printf("Error: Could not open destination file %s for writing.\n", destination);
        fclose(srcFile);
        logActivity("Failed to open destination file for writing.");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, destFile);
    }

    printf("File %s successfully backed up to %s\n", source, destination);
    
    fclose(srcFile);
    fclose(destFile);
    logActivity("Backup completed successfully.");
}

void backupDirectory(const char *sourceDir, const char *destDir) {
    struct dirent *entry;
    DIR *dp = opendir(sourceDir);
    if (dp == NULL) {
        printf("Error: Could not open directory %s.\n", sourceDir);
        logActivity("Failed to open source directory.");
        return;
    }

    mkdir(destDir, 0755); // Create destination directory

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char srcPath[512];
            char destPath[512];
            snprintf(srcPath, sizeof(srcPath), "%s/%s", sourceDir, entry->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

            if (entry->d_type == DT_DIR) {
                backupDirectory(srcPath, destPath); // Recursive backup for directories
            } else {
                copyFile(srcPath, destPath); // Backup file
            }
        }
    }
    closedir(dp);
}

void backupData(const char *source) {
    struct stat st;
    if (stat(source, &st) == -1) {
        printf("Error: Could not access source %s.\n", source);
        logActivity("Failed to access source.");
        return;
    }

    char dest[512];
    snprintf(dest, sizeof(dest), "%s_backup", source);

    if (S_ISDIR(st.st_mode)) {
        backupDirectory(source, dest);
    } else {
        copyFile(source, dest);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_or_directory_to_backup>\n", argv[0]);
        return 1;
    }

    logActivity("Backup process started.");
    backupData(argv[1]);
    logActivity("Backup process completed.");

    return 0;
}