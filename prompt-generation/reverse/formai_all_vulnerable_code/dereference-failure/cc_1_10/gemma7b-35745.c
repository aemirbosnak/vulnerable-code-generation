//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[20];
    struct File* next;
    FILE* file;
} File;

File* head = NULL;

void createFile(char* name) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->file = fopen(name, "w");
    if (head == NULL) {
        head = newFile;
    } else {
        head->next = newFile;
        head = newFile;
    }
}

void listFiles() {
    File* currentFile = head;
    while (currentFile) {
        printf("%s\n", currentFile->name);
        currentFile = currentFile->next;
    }
}

void deleteFile(char* name) {
    File* previousFile = NULL;
    File* currentFile = head;
    while (currentFile) {
        if (strcmp(currentFile->name, name) == 0) {
            if (previousFile) {
                previousFile->next = currentFile->next;
            } else {
                head = currentFile->next;
            }
            fclose(currentFile->file);
            free(currentFile);
            return;
        }
        previousFile = currentFile;
        currentFile = currentFile->next;
    }
    printf("File not found.\n");
}

int main() {
    createFile("Romeo.txt");
    createFile("Juliet.txt");
    listFiles();
    deleteFile("Romeo.txt");
    listFiles();
    return 0;
}