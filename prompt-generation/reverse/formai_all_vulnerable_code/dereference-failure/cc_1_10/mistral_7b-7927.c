//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 20
#define MAX_FILE_CONTENT_LENGTH 50

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    struct File *next;
} File;

File *fileSystem = NULL;

void createFile(char *name) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = fileSystem;
    fileSystem = newFile;
}

void writeToFile(char *name, char *content) {
    File *current = fileSystem;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->content, content);
            printf("File %s content updated successfully.\n", name);
            return;
        }
        current = current->next;
    }
    printf("File %s not found.\n", name);
}

void readFromFile(char *name) {
    File *current = fileSystem;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Content of %s:\n%s\n", name, current->content);
            return;
        }
        current = current->next;
    }
    printf("File %s not found.\n", name);
}

int main() {
    createFile("file1.txt");
    createFile("file2.txt");

    writeToFile("file1.txt", "Hello World!");
    writeToFile("file2.txt", "Welcome to the file system simulation!");

    readFromFile("file1.txt");
    readFromFile("file2.txt");

    writeToFile("file1.txt", "Updated content for file1.txt");
    readFromFile("file1.txt");

    return 0;
}