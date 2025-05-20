//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1024 * 1024
#define BUFFER_SIZE 256

typedef struct {
    char fileName[BUFFER_SIZE];
    char fileContent[MAX_FILE_SIZE];
} FileHandler;

void error_handler(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int readFile(const char *fileName, char *buffer, size_t size) {
    int fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        error_handler("open");
    }

    ssize_t bytesRead = read(fd, buffer, size);
    if (bytesRead < 0) {
        error_handler("read");
    }

    close(fd);
    return bytesRead;
}

int writeFile(const char *fileName, const char *buffer, size_t size) {
    int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        error_handler("open");
    }

    ssize_t bytesWritten = write(fd, buffer, size);
    if (bytesWritten < 0) {
        error_handler("write");
    }

    close(fd);
    return bytesWritten;
}

int main() {
    FileHandler fileHandler;
    char *buffer = malloc(BUFFER_SIZE);

    printf("Enter file name: ");
    fgets(fileHandler.fileName, BUFFER_SIZE, stdin);

    if (readFile(fileHandler.fileName, fileHandler.fileContent, MAX_FILE_SIZE) > 0) {
        printf("File content:\n%s\n", fileHandler.fileContent);

        printf("Enter new content: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (writeFile(fileHandler.fileName, buffer, strlen(buffer)) > 0) {
            printf("File content updated successfully.\n");
        } else {
            printf("Failed to update file content.\n");
        }
    } else {
        printf("Failed to read file.\n");
    }

    free(buffer);
    return 0;
}