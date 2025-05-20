//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 512

typedef struct {
    char* sourcePath;
    char* destinationPath;
} FilePair;

void syncDirectories(char* source, char* destination);
void syncFiles(char* source, char* destination);
void syncFilePair(FilePair p);
void createDirectory(char* path);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s SOURCE DESTINATION\n", argv[0]);
        exit(1);
    }

    syncDirectories(argv[1], argv[2]);

    return 0;
}

void syncDirectories(char* source, char* destination) {
    DIR* sourceDir = opendir(source);
    DIR* destDir = opendir(destination);

    if (sourceDir == NULL) {
        printf("Error: could not open %s\n", source);
        exit(1);
    }

    if (destDir == NULL) {
        createDirectory(destination);
        destDir = opendir(destination);
    }

    struct dirent* sourceEntry = readdir(sourceDir);

    while (sourceEntry != NULL) {
        char* sourceFileName = sourceEntry->d_name;

        if (strcmp(sourceFileName, ".") == 0 || strcmp(sourceFileName, "..") == 0) {
            sourceEntry = readdir(sourceDir);
            continue;
        }

        char* sourcePath = malloc(strlen(source) + 1 + strlen(sourceFileName) + 1);
        strcpy(sourcePath, source);
        strcat(sourcePath, "/");
        strcat(sourcePath, sourceFileName);

        char* destPath = malloc(strlen(destination) + 1 + strlen(sourceFileName) + 1);
        strcpy(destPath, destination);
        strcat(destPath, "/");
        strcat(destPath, sourceFileName);

        struct stat sourceStat;
        stat(sourcePath, &sourceStat);

        if (S_ISREG(sourceStat.st_mode)) {
            // If source is a regular file, sync it
            FilePair pair = {sourcePath, destPath};
            syncFilePair(pair);
        } else if (S_ISDIR(sourceStat.st_mode)) {
            // If source is a directory, sync it recursively
            syncDirectories(sourcePath, destPath);
        }

        free(sourcePath);
        free(destPath);

        sourceEntry = readdir(sourceDir);
    }

    closedir(sourceDir);
    closedir(destDir);
}

void syncFiles(char* source, char* destination) {
    FILE* sourceFile = fopen(source, "r");
    FILE* destFile = fopen(destination, "r");

    if (sourceFile == NULL) {
        printf("Error: could not open %s\n", source);
        exit(1);
    }

    if (destFile == NULL) {
        // If destination does not exist, copy source to destination
        destFile = fopen(destination, "w");

        if (destFile == NULL) {
            printf("Error: could not create %s\n", destination);
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        size_t numRead;

        while ((numRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
            fwrite(buffer, 1, numRead, destFile);
        }
    } else {
        // If destination already exists, compare timestamps
        struct stat sourceStat, destStat;
        stat(source, &sourceStat);
        stat(destination, &destStat);

        if (difftime(sourceStat.st_mtime, destStat.st_mtime) > 0) {
            // If source is newer than destination, copy it
            destFile = fopen(destination, "w");

            if (destFile == NULL) {
                printf("Error: could not open %s for writing\n", destination);
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            size_t numRead;

            while ((numRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
                fwrite(buffer, 1, numRead, destFile);
            }
        }
    }

    fclose(sourceFile);
    fclose(destFile);
}

void syncFilePair(FilePair p) {
    syncFiles(p.sourcePath, p.destinationPath);
}

void createDirectory(char* path) {
    int status = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    if (status != 0) {
        printf("Error: could not create directory %s\n", path);
        exit(1);
    }
}