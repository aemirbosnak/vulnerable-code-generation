//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024
#define BLOCK_SIZE 512

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

void createFile(char *fileName, int size) {
    int fd = open(fileName, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        printf("Error creating file %s\n", fileName);
        exit(1);
    }
    File *file = (File *) malloc(sizeof(File));
    strcpy(file->name, fileName);
    file->size = size;
    memset(file->data, 0, size);
    write(fd, file, sizeof(File));
    close(fd);
}

void readFile(char *fileName) {
    int fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        printf("Error reading file %s\n", fileName);
        exit(1);
    }
    File *file = (File *) malloc(sizeof(File));
    read(fd, file, sizeof(File));
    printf("File name: %s\n", file->name);
    printf("File size: %d bytes\n", file->size);
    printf("File contents:\n");
    for (int i = 0; i < file->size; i++) {
        printf("%c", file->data[i]);
    }
    close(fd);
}

void writeFile(char *fileName, char *data, int size) {
    int fd = open(fileName, O_RDWR);
    if (fd == -1) {
        printf("Error writing file %s\n", fileName);
        exit(1);
    }
    File *file = (File *) malloc(sizeof(File));
    read(fd, file, sizeof(File));
    memcpy(file->data, data, size);
    write(fd, file, sizeof(File));
    close(fd);
}

void deleteFile(char *fileName) {
    unlink(fileName);
}

int main() {
    createFile("test.txt", 10);
    writeFile("test.txt", "Hello, world!", 13);
    readFile("test.txt");
    deleteFile("test.txt");
    return 0;
}