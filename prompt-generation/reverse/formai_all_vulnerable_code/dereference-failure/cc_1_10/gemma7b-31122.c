//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[20];
    struct File* next;
    int size;
    int data[1024];
} File;

File* head = NULL;

void createFile(char* name, int size) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = head;
    head = newFile;
    newFile->size = size;
    for (int i = 0; i < size; i++) {
        newFile->data[i] = 0;
    }
}

void writeFile(char* name, int data) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            file->data[file->size++] = data;
            break;
        }
        file = file->next;
    }
    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

void readFile(char* name) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            for (int i = 0; i < file->size; i++) {
                printf("%d ", file->data[i]);
            }
            break;
        }
        file = file->next;
    }
    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

int main() {
    createFile("test.txt", 10);
    writeFile("test.txt", 10);
    writeFile("test.txt", 20);
    readFile("test.txt");
    return 0;
}