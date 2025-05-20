//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>

// This function checks if the given path is a directory or not
int isDirectory(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if ((st.st_mode & S_IFDIR) != 0) {
            return 1;
        }
    }
    return 0;
}

// This function copies a file from sourcePath to destPath
void copyFile(const char *sourcePath, const char *destPath) {
    char buffer[BUFSIZ];
    size_t count;
    FILE *sourceFile = fopen(sourcePath, "rb");
    FILE *destFile = fopen(destPath, "wb");
    while ((count = fread(buffer, 1, BUFSIZ, sourceFile)) > 0) {
        fwrite(buffer, 1, count, destFile);
    }
    fclose(sourceFile);
    fclose(destFile);
}

// This function copies a directory from sourcePath to destPath
void copyDirectory(const char *sourcePath, const char *destPath) {
    DIR *dir;
    struct dirent *entry;
    char sourceBuffer[BUFSIZ], destBuffer[BUFSIZ];

    dir = opendir(sourcePath);
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        sprintf(sourceBuffer, "%s/%s", sourcePath, entry->d_name);
        sprintf(destBuffer, "%s/%s", destPath, entry->d_name);

        if (isDirectory(sourceBuffer)) {
            mkdir(destBuffer, 0777);
            copyDirectory(sourceBuffer, destBuffer);
        } else {
            copyFile(sourceBuffer, destBuffer);
        }
    }
    closedir(dir);
}

// This function synchronizes a directory from sourcePath to destPath
void syncDirectory(const char *sourcePath, const char *destPath) {
    DIR *dir;
    struct dirent *entry;
    char sourceBuffer[BUFSIZ], destBuffer[BUFSIZ];

    dir = opendir(sourcePath);
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        sprintf(sourceBuffer, "%s/%s", sourcePath, entry->d_name);
        sprintf(destBuffer, "%s/%s", destPath, entry->d_name);

        if (isDirectory(sourceBuffer)) {
            if (!isDirectory(destBuffer)) {
                mkdir(destBuffer, 0777);
            }
            syncDirectory(sourceBuffer, destBuffer);
        } else {
            struct stat sourceStat, destStat;
            if (stat(sourceBuffer, &sourceStat) < 0) {
                perror("stat");
                continue;
            }
            if (stat(destBuffer, &destStat) < 0) {
                copyFile(sourceBuffer, destBuffer);
                continue;
            }
            if (difftime(sourceStat.st_mtime, destStat.st_mtime) > 0) {
                copyFile(sourceBuffer, destBuffer);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source_dir] [dest_dir]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!isDirectory(argv[1])) {
        printf("Error: %s is not a directory.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (!isDirectory(argv[2])) {
        printf("Error: %s is not a directory.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    syncDirectory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}