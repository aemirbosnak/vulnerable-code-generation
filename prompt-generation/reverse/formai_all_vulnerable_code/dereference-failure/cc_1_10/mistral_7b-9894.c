//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_NUM_OF_FILES 100

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    char content[1024];
    struct File *next;
} File;

File *fileSystem = NULL;

void createFile(char *fileName) {
    File *newFile = (File *) malloc(sizeof(File));
    strcpy(newFile->name, fileName);
    newFile->next = fileSystem;
    fileSystem = newFile;
}

void deleteFile(char *fileName) {
    File *current = fileSystem;
    File *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, fileName) == 0) {
            if (previous == NULL) {
                fileSystem = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("File not found.\n");
}

void writeFile(char *fileName, char *data) {
    File *file = fileSystem;

    while (file != NULL) {
        if (strcmp(file->name, fileName) == 0) {
            strcpy(file->content, data);
            return;
        }
        file = file->next;
    }

    printf("File not found.\n");
}

void readFile(char *fileName) {
    File *file = fileSystem;

    while (file != NULL) {
        if (strcmp(file->name, fileName) == 0) {
            printf("%s\n", file->content);
            return;
        }
        file = file->next;
    }

    printf("File not found.\n");
}

void listFiles() {
    File *file = fileSystem;
    int i = 1;

    printf("List of files:\n");

    while (file != NULL) {
        printf("%d. %s\n", i, file->name);
        file = file->next;
        i++;
    }
}

int main() {
    createFile("file1.txt");
    createFile("file2.txt");

    writeFile("file1.txt", "Hello World!");
    writeFile("file2.txt", "This is a test file.");

    listFiles();

    readFile("file1.txt");
    readFile("file3.txt");

    deleteFile("file1.txt");

    listFiles();

    return 0;
}