//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[25];
    struct File* next;
    FILE* fp;
} File;

File* head = NULL;

void createFile(char* name) {
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->fp = NULL;

    if (head == NULL) {
        head = newFile;
    } else {
        head->next = newFile;
        head = newFile;
    }
}

void openFile(char* name) {
    File* file = head;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            file->fp = fopen(file->name, "r");
            break;
        }
        file = file->next;
    }

    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

void closeFile(char* name) {
    File* file = head;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            fclose(file->fp);
            break;
        }
        file = file->next;
    }

    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

int main() {
    createFile("test.txt");
    openFile("test.txt");
    closeFile("test.txt");

    return 0;
}