//FormAI DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

void syncFiles(char *sourcePath, char *destPath);
void syncDir(char *sourceDirPath, char *destDirPath);
void copyFile(char *sourceFilePath, char *destFilePath);
void createDirRecursive(char *dirPath, mode_t mode);

// main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s source_path destination_path\n", argv[0]);
        return -1;
    }
    
    char *sourcePath = argv[1];
    char *destPath = argv[2];

    syncFiles(sourcePath, destPath);

    return 0;
}

// synchronize files in the given directories
void syncFiles(char *sourcePath, char *destPath) {
    struct stat sourceFileStat, destFileStat;

    if (stat(sourcePath, &sourceFileStat) == -1) {
        perror("Failed to get file information");
        exit(EXIT_FAILURE);
    }

    if (stat(destPath, &destFileStat) == -1) {
        printf("Destination path does not exist. Creating directory: %s\n", destPath);
        createDirRecursive(destPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }

    if (S_ISDIR(sourceFileStat.st_mode)) {
        syncDir(sourcePath, destPath);
    } else {
        copyFile(sourcePath, destPath);
    }
}

// synchronize directories
void syncDir(char *sourceDirPath, char *destDirPath) {
    DIR *sourceDir = opendir(sourceDirPath);
    DIR *destDir;
    struct dirent *sourceFileEntry, *destFileEntry;

    if (!sourceDir) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((sourceFileEntry = readdir(sourceDir)) != NULL) {
        char *sourceFilePath = malloc(strlen(sourceDirPath) + strlen(sourceFileEntry->d_name) + 1);
        strcpy(sourceFilePath, sourceDirPath);
        strcat(sourceFilePath, "/");
        strcat(sourceFilePath, sourceFileEntry->d_name);

        char *destFilePath = malloc(strlen(destDirPath) + strlen(sourceFileEntry->d_name) + 1);
        strcpy(destFilePath, destDirPath);
        strcat(destFilePath, "/");
        strcat(destFilePath, sourceFileEntry->d_name);

        if (strcmp(sourceFileEntry->d_name, ".") == 0 || strcmp(sourceFileEntry->d_name, "..") == 0) {
            continue;
        }

        if ((destDir = opendir(destFilePath)) != NULL) {
            while ((destFileEntry = readdir(destDir)) != NULL) {
                char *destFilePathChild = malloc(strlen(destFilePath) + strlen(destFileEntry->d_name) + 1);
                strcpy(destFilePathChild, destFilePath);
                strcat(destFilePathChild, "/");
                strcat(destFilePathChild, destFileEntry->d_name);
                
                if (strcmp(destFileEntry->d_name, ".") == 0 || strcmp(destFileEntry->d_name, "..") == 0) {
                    continue;
                }

                if (strcmp(sourceFileEntry->d_name, destFileEntry->d_name) == 0) {
                    break;
                }
            }
            closedir(destDir);
        }

        struct stat sourceFileStat, destFileStat;
        if (stat(sourceFilePath, &sourceFileStat) == -1) {
            perror("Failed to get file information");
            exit(EXIT_FAILURE);
        }
        if (stat(destFilePath, &destFileStat) == -1) {
            if (S_ISDIR(sourceFileStat.st_mode)) {
                printf("Destination directory does not exist. Creating directory: %s\n", destFilePath);
                createDirRecursive(destFilePath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            } else {
                copyFile(sourceFilePath, destFilePath);
            }
        } else {
            if (S_ISDIR(sourceFileStat.st_mode) && !S_ISDIR(destFileStat.st_mode)) {
                printf("Source is a directory and destination is a file. Skipping: %s\n", sourceFilePath);
            } else {
                if (sourceFileStat.st_mtime > destFileStat.st_mtime) {
                    if (S_ISDIR(sourceFileStat.st_mode)) {
                        syncDir(sourceFilePath, destFilePath);
                    } else {
                        copyFile(sourceFilePath, destFilePath);
                    }
                }
            }
        }
    }
    closedir(sourceDir);
}

// copy file from source to destination
void copyFile(char *sourceFilePath, char *destFilePath) {
    int sourceFile, destFile;
    char buffer[MAX_BUF_SIZE];
    ssize_t bytesRead;

    printf("Copying file: %s to %s\n", sourceFilePath, destFilePath);

    if ((sourceFile = open(sourceFilePath, O_RDONLY)) == -1) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    if ((destFile = open(destFilePath, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)) == -1) {
        perror("Failed to open destination file");
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(sourceFile, buffer, MAX_BUF_SIZE)) > 0) {
        if (write(destFile, buffer, bytesRead) != bytesRead) {
            perror("Failed to write to destination file");
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("Failed to read from source file");
        exit(EXIT_FAILURE);
    }

    if (close(sourceFile) == -1) {
        perror("Failed to close source file");
        exit(EXIT_FAILURE);
    }

    if (close(destFile) == -1) {
        perror("Failed to close destination file");
        exit(EXIT_FAILURE);
    }
}

// create directory recursively
void createDirRecursive(char *dirPath, mode_t mode) {
    char *dirPathCopy = malloc(strlen(dirPath) + 1);
    strcpy(dirPathCopy, dirPath);

    char *token = strtok(dirPathCopy, "/");
    char *partialPath = malloc(strlen(token) + 1);
    strcpy(partialPath, token);
    while (token != NULL) {
        mkdir(partialPath, mode);
        token = strtok(NULL, "/");
        if (token != NULL) {
            partialPath = realloc(partialPath, strlen(partialPath) + strlen(token) + 2);
            strcat(partialPath, "/");
            strcat(partialPath, token);
        }
    }
    free(dirPathCopy);
    free(partialPath);
}