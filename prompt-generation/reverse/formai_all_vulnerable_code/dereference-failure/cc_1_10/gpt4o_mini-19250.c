//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void displayUsage() {
    printf("Usage: file_backup <source_path1> <source_path2> ... <source_pathN> <backup_directory>\n");
}

void copyFile(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    FILE *destFile = fopen(dest, "wb");
    
    if (sourceFile == NULL || destFile == NULL) {
        perror("File operation failed");
        if (sourceFile) fclose(sourceFile);
        if (destFile) fclose(destFile);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    printf("Copied %s to %s\n", src, dest);
}

void backupFile(const char *source, const char *backupDir) {
    struct stat statbuf;
    
    if (stat(source, &statbuf) < 0) {
        perror("Stat failed");
        return;
    }

    if (S_ISDIR(statbuf.st_mode)) {
        DIR *dir = opendir(source);
        struct dirent *entry;

        if (dir == NULL) {
            perror("Directory open failed");
            return;
        }

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char srcPath[MAX_FILENAME_LENGTH];
                char destPath[MAX_FILENAME_LENGTH];

                snprintf(srcPath, sizeof(srcPath), "%s/%s", source, entry->d_name);
                snprintf(destPath, sizeof(destPath), "%s/%s", backupDir, entry->d_name);

                backupFile(srcPath, backupDir);
            }
        }
        closedir(dir);
    } else {
        char destPath[MAX_FILENAME_LENGTH];
        snprintf(destPath, sizeof(destPath), "%s/%s", backupDir, strrchr(source, '/') + 1);
        copyFile(source, destPath);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        displayUsage();
        return EXIT_FAILURE;
    }

    const char *backupDir = argv[argc - 1];
    
    struct stat st;
    if (stat(backupDir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Backup directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc - 1; ++i) {
        backupFile(argv[i], backupDir);
    }

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}