//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256

void backupDirectory(char *srcPath, char *destPath);
void backupFile(char *srcFile, char *destPath);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    backupDirectory(argv[1], argv[2]);

    return 0;
}

void backupDirectory(char *srcPath, char *destPath) {
    DIR *dir;
    struct dirent *entry;
    char srcFile[MAX_FILENAME_LENGTH];
    char destFile[MAX_FILENAME_LENGTH];

    // Open the source directory
    dir = opendir(srcPath);
    if (!dir) {
        perror("opendir");
        return;
    }

    // Create the destination directory if it does not exist
    if (access(destPath, F_OK) != 0) {
        mkdir(destPath, 0700);
    }

    // Loop over all files in the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full paths for the source and destination files
        snprintf(srcFile, MAX_FILENAME_LENGTH, "%s/%s", srcPath, entry->d_name);
        snprintf(destFile, MAX_FILENAME_LENGTH, "%s/%s", destPath, entry->d_name);

        // Backup the file or directory
        if (entry->d_type == DT_DIR) {
            backupDirectory(srcFile, destFile);
        } else if (entry->d_type == DT_REG) {
            backupFile(srcFile, destPath);
        }
    }

    // Close the directory
    closedir(dir);
}

void backupFile(char *srcFile, char *destPath) {
    char destFile[MAX_FILENAME_LENGTH];
    FILE *src, *dest;
    size_t n;
    char buf[1024];

    // Open the source file for reading
    src = fopen(srcFile, "r");
    if (!src) {
        perror("fopen");
        return;
    }

    // Construct the full path for the destination file
    snprintf(destFile, MAX_FILENAME_LENGTH, "%s/%s", destPath, basename(srcFile));

    // Open the destination file for writing
    dest = fopen(destFile, "w");
    if (!dest) {
        perror("fopen");
        fclose(src);
        return;
    }

    // Copy the contents of the source file to the destination file
    while ((n = fread(buf, 1, sizeof(buf), src)) > 0) {
        if (fwrite(buf, 1, n, dest) != n) {
            perror("fwrite");
            fclose(src);
            fclose(dest);
            return;
        }
    }

    // Close the files
    fclose(src);
    fclose(dest);

    // Print a message indicating that the file has been backed up
    printf("Backed up file %s to %s\n", srcFile, destFile);
}