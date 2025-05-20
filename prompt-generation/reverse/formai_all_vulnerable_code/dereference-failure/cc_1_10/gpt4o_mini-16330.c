//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function declarations
void syncFiles(const char *srcDir, const char *destDir);
int isFileModified(const char *srcFile, const char *destFile);
void copyFile(const char *srcFile, const char *destFile);
void listFiles(const char *dirPath);
void checkAndSync(const char *srcFile, const char *destFile);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    syncFiles(argv[1], argv[2]);
    
    printf("Synchronization Complete!\n");
    return EXIT_SUCCESS;
}

void syncFiles(const char *srcDir, const char *destDir) {
    DIR *dir;
    struct dirent *entry;
    char srcFilePath[1024], destFilePath[1024];

    if (!(dir = opendir(srcDir))) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(srcFilePath, sizeof(srcFilePath), "%s/%s", srcDir, entry->d_name);
            snprintf(destFilePath, sizeof(destFilePath), "%s/%s", destDir, entry->d_name);

            struct stat st;
            if (stat(srcFilePath, &st) == 0 && S_ISREG(st.st_mode)) {
                checkAndSync(srcFilePath, destFilePath);
            }
            else if (stat(srcFilePath, &st) == 0 && S_ISDIR(st.st_mode)) {
                mkdir(destFilePath, 0777); // Create directory if it doesn't exist
                syncFiles(srcFilePath, destFilePath); // Recur for subdirectories
            }
        }
    }

    closedir(dir);
}

void checkAndSync(const char *srcFile, const char *destFile) {
    if (access(destFile, F_OK) != -1) {
        if (isFileModified(srcFile, destFile)) {
            copyFile(srcFile, destFile);
            printf("Updated: %s\n", destFile);
        }
    } else {
        copyFile(srcFile, destFile);
        printf("Created: %s\n", destFile);
    }
}

int isFileModified(const char *srcFile, const char *destFile) {
    struct stat srcStat, destStat;
    stat(srcFile, &srcStat);
    stat(destFile, &destStat);
    return srcStat.st_mtime > destStat.st_mtime; // Check for modification time
}

void copyFile(const char *srcFile, const char *destFile) {
    FILE *src = fopen(srcFile, "rb");
    FILE *dest = fopen(destFile, "wb");
    
    if (!src || !dest) {
        perror("Error opening files for copying");
        if (src) fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

void listFiles(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf("File: %s\n", entry->d_name);
        } else if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 &&
                strcmp(entry->d_name, "..") != 0) {
                printf("Directory: %s\n", entry->d_name);
            }
        }
    }
    closedir(dir);
}