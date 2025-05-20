//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    int data[1024];
} File;

File* head = NULL;

void createFile(char* name, int data[]) {
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    memcpy(newFile->data, data, 1024);

    if (head == NULL) {
        head = newFile;
    } else {
        head->next = newFile;
        head = newFile;
    }
}

void readData(char* name) {
    File* currentFile = head;
    while (currentFile) {
        if (strcmp(currentFile->name, name) == 0) {
            printf("Data: ");
            for (int i = 0; i < 1024; i++) {
                printf("%d ", currentFile->data[i]);
            }
            printf("\n");
            return;
        }
        currentFile = currentFile->next;
    }

    printf("File not found.\n");
}

int main() {
    createFile("test.txt", (int[]){1, 2, 3, 4, 5});
    readData("test.txt");

    createFile("another.txt", (int[]){6, 7, 8, 9, 10});
    readData("another.txt");

    return 0;
}