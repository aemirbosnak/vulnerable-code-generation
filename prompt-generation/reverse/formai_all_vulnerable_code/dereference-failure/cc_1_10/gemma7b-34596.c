//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    struct File* prev;
    int data[1024];
} File;

File* head = NULL;
File* tail = NULL;

void createFile(char* name) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->prev = tail;

    if (head == NULL) {
        head = newFile;
    } else {
        tail->next = newFile;
    }

    tail = newFile;
}

void readFile(char* name) {
    File* file = head;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            printf("Data: ");
            for (int i = 0; i < file->data[0]; i++) {
                printf("%d ", file->data[i + 1]);
            }
            printf("\n");
            break;
        }
        file = file->next;
    }

    if (file == NULL) {
        printf("File not found.\n");
    }
}

void writeFile(char* name, int data) {
    File* file = head;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            file->data[0] = data;
            file->data[1] = data;
            break;
        }
        file = file->next;
    }

    if (file == NULL) {
        printf("File not found.\n");
    }
}

int main() {
    createFile("test.txt");
    writeFile("test.txt", 10);
    readFile("test.txt");
    writeFile("test.txt", 20);
    readFile("test.txt");

    return 0;
}