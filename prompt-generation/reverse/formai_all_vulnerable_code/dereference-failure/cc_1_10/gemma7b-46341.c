//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BUFFER_SIZE 256

typedef struct File {
    char name[MAX_FILES];
    struct File* next;
    int data[MAX_BUFFER_SIZE];
    int size;
} File;

File* head = NULL;

void createFile(char* name) {
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = head;
    head = newFile;
    newFile->size = 0;
}

void writeFile(char* name, int data) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            file->data[file->size++] = data;
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
            for (int i = 0; i < file->size; i++) {
                printf("%d ", file->data[i]);
            }
            printf("\n");
            return;
        }
        file = file->next;
    }

    printf("Error: File not found.\n");
}

int main() {
    createFile("test.txt");
    writeFile("test.txt", 10);
    writeFile("test.txt", 20);
    readFile("test.txt");

    return 0;
}