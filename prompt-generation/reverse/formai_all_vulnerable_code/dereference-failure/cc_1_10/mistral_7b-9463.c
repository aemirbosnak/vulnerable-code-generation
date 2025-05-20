//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    int fd;
} FileHandle;

void readFile(FileHandle *fileHandle, char *buffer, int bufferSize) {
    ssize_t bytesRead;
    if ((fileHandle->fd) < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(fileHandle->fd, buffer, bufferSize);
    if (bytesRead < 0) {
        perror("Error reading file");
        close(fileHandle->fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';
}

int main(int argc, char *argv[]) {
    FileHandle fileHandle;
    char buffer[MAX_BUFFER_SIZE];
    char fileName[MAX_FILE_NAME_LENGTH];
    int fileMode;

    if (argc != 3) {
        printf("Usage: %s <filename> <read|write>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(fileHandle.fileName, argv[1]);

    if (strcmp(argv[2], "read") != 0 && strcmp(argv[2], "write") != 0) {
        printf("Invalid mode specified. Use 'read' or 'write'\n");
        exit(EXIT_FAILURE);
    }

    fileMode = strcmp(argv[2], "read");

    if ((fileHandle.fd = open(fileHandle.fileName, fileMode ? O_WRONLY : O_RDONLY)) < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    readFile(&fileHandle, buffer, MAX_BUFFER_SIZE);

    printf("File contents:\n%s\n", buffer);

    if (!fileMode) {
        char newContent[MAX_BUFFER_SIZE];
        printf("Enter new file content: ");
        fgets(newContent, MAX_BUFFER_SIZE, stdin);

        if (strlen(newContent) > MAX_BUFFER_SIZE - 1) {
            printf("New content too long. Maximum allowed size: %d\n", MAX_BUFFER_SIZE - 1);
            close(fileHandle.fd);
            exit(EXIT_FAILURE);
        }

        if (write(fileHandle.fd, newContent, strlen(newContent) + 1) < 0) {
            perror("Error writing to file");
            close(fileHandle.fd);
            exit(EXIT_FAILURE);
        }

        printf("File updated successfully.\n");
    }

    close(fileHandle.fd);

    return EXIT_SUCCESS;
}