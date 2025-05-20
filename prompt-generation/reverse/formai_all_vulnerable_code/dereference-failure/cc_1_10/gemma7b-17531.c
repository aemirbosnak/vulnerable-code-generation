//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct file {
    char name[256];
    struct file* next;
    int size;
    char data[1];
} file;

file* head = NULL;

void createFile(char* name, int size) {
    file* newFile = (file*)malloc(sizeof(file));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->size = size;
    newFile->data[0] = '\0';

    if (head == NULL) {
        head = newFile;
    } else {
        file* currentFile = head;
        while (currentFile->next) {
            currentFile = currentFile->next;
        }
        currentFile->next = newFile;
    }
}

void writeFile(char* name, char* data) {
    file* currentFile = head;
    while (currentFile) {
        if (strcmp(currentFile->name, name) == 0) {
            int i = 0;
            while (data[i] != '\0') {
                currentFile->data[i] = data[i];
                i++;
            }
            currentFile->data[i] = '\0';
            return;
        }
        currentFile = currentFile->next;
    }

    printf("Error: File not found.\n");
}

int main() {
    createFile("test.txt", 10);
    writeFile("test.txt", "Hello, world!");
    writeFile("new.txt", "Goodbye, world!");

    printf("File data:\n");
    writeFile("test.txt", "Modified data");

    return 0;
}