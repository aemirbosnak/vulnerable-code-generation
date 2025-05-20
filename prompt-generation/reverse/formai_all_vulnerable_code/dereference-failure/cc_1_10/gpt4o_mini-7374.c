//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

void printWelcomeMessage() {
    printf("====================================\n");
    printf(" Welcome to the C File Backup System!\n");
    printf("====================================\n");
    printf(" Type 'exit' to quit the program.\n");
}

void showFiles(const char *path) {
    DIR *d;
    struct dirent *dir;
    
    d = opendir(path);
    if (d) {
        printf("Files in '%s':\n", path);
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) { // Only show regular files
                printf(" - %s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        perror("Could not open directory");
    }
}

void backupFile(const char *srcFilePath, const char *destFilePath) {
    FILE *sourceFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    sourceFile = fopen(srcFilePath, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return;
    }

    destFile = fopen(destFilePath, "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    printf("Successfully backed up '%s' to '%s'\n", srcFilePath, destFilePath);
    fclose(sourceFile);
    fclose(destFile);
}

void backupFilesFromDirectory(const char *sourceDir, const char *destDir) {
    DIR *d;
    struct dirent *dir;
    char srcFilePath[MAX_PATH];
    char destFilePath[MAX_PATH];

    d = opendir(sourceDir);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) { // Backup only regular files
                snprintf(srcFilePath, MAX_PATH, "%s/%s", sourceDir, dir->d_name);
                snprintf(destFilePath, MAX_PATH, "%s/%s", destDir, dir->d_name);
                backupFile(srcFilePath, destFilePath);
            }
        }
        closedir(d);
    } else {
        perror("Could not open source directory");
    }
}

int main() {
    char srcDir[MAX_PATH], destDir[MAX_PATH];
    char command[MAX_PATH];

    printWelcomeMessage();

    printf("Enter the source directory for backup: ");
    fgets(srcDir, MAX_PATH, stdin);
    srcDir[strcspn(srcDir, "\n")] = 0; // Remove newline

    printf("Enter the destination directory for backup: ");
    fgets(destDir, MAX_PATH, stdin);
    destDir[strcspn(destDir, "\n")] = 0; // Remove newline

    struct stat sb;
    if (stat(destDir, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Destination directory does not exist or is not a directory.\n");
        exit(1);
    }

    showFiles(srcDir);
    
    printf("Would you like to backup all files? [y/n]: ");
    fgets(command, MAX_PATH, stdin);
    command[strcspn(command, "\n")] = 0; // Remove newline

    if (strcmp(command, "y") == 0 || strcmp(command, "Y") == 0) {
        backupFilesFromDirectory(srcDir, destDir);
    } else {
        printf("Backup operation canceled.\n");
    }

    printf("Thank you for using the C File Backup System! Type 'exit' to quit.\n");
    fgets(command, MAX_PATH, stdin); // Wait for user to press enter
    return 0;
}