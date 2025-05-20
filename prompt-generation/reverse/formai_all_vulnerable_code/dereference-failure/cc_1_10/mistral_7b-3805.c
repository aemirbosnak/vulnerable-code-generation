//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
#define MAX_LINE_LENGTH 1024

typedef struct Node {
    char fileName[MAX_FILE_NAME];
    struct stat fileStat;
    struct Node *next;
} Node;

Node *head = NULL;

void backupFile(char *fileName) {
    int fd, ret;
    char *buffer;
    off_t fileSize;

    struct stat fileStat;
    if (stat(fileName, &fileStat) < 0) {
        perror("Error: Could not stat file.\n");
        return;
    }

    fileSize = fileStat.st_size;
    buffer = malloc(fileSize + 1);

    fd = open(fileName, O_RDONLY);
    if (fd < 0) {
        perror("Error: Could not open file for reading.\n");
        free(buffer);
        return;
    }

    ret = read(fd, buffer, fileSize);
    if (ret != fileSize) {
        perror("Error: Could not read file completely.\n");
        free(buffer);
        close(fd);
        return;
    }

    // Create a new node for the backup file
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->fileName, fileName);
    stat(fileName, &newNode->fileStat);
    newNode->next = head;

    // Write the backup data to a new file with the same name and "_backup" suffix
    char backupFileName[MAX_FILE_NAME];
    strcpy(backupFileName, fileName);
    strcat(backupFileName, "_backup");

    int fd_backup = open(backupFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_backup < 0) {
        perror("Error: Could not open backup file for writing.\n");
        free(newNode);
        free(buffer);
        close(fd);
        return;
    }

    write(fd_backup, buffer, fileSize);
    close(fd_backup);

    // Update the size of the new backup node
    newNode->fileStat.st_size = fileSize;

    // Add the new node to the head of the linked list
    head = newNode;

    free(buffer);
    close(fd);
    printf("File '%s' backed up successfully.\n", fileName);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_backup>\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];
    backupFile(fileName);

    return 0;
}