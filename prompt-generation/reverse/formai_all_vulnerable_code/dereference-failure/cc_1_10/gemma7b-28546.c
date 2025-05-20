//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[25];
    struct File* next;
    int size;
    int data[1];
} File;

File* head = NULL;

void createFile(char* name, int size) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->size = size;
    newFile->data[0] = 0;

    if (head == NULL) {
        head = newFile;
    } else {
        head->next = newFile;
        head = newFile;
    }
}

void writeFile(char* name, int data) {
    File* file = head;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            file->data[0] = data;
            return;
        }
        file = file->next;
    }

    printf("Error: File not found.\n");
}

void readFile(char* name) {
    File* file = head;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            printf("Data: %d\n", file->data[0]);
            return;
        }
        file = file->next;
    }

    printf("Error: File not found.\n");
}

int main() {
    createFile("test.txt", 10);
    writeFile("test.txt", 5);
    readFile("test.txt");

    return 0;
}