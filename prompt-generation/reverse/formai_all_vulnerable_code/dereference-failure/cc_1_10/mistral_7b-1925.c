//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME_LENGTH 50
#define MAX_NUM_OF_FILES 10
#define MAX_FILE_SIZE 100

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    struct File *next;
} File;

File *head = NULL;
File *current = NULL;

void createFile(char *name, int size) {
    File *newFile = (File *) malloc(sizeof(File));

    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = head;

    if (head != NULL) {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFile;
    } else {
        head = newFile;
    }
}

void deleteFile(char *name) {
    File *temp = head;
    File *prev = NULL;

    if (head == NULL) {
        printf("File system is empty!\n");
        return;
    }

    if (strcmp(head->name, name) == 0) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("File not found!\n");
}

void displayFiles() {
    File *temp = head;

    if (head == NULL) {
        printf("File system is empty!\n");
        return;
    }

    printf("Files in the file system:\n");
    while (temp != NULL) {
        printf("%s (Size: %d)\n", temp->name, temp->size);
        temp = temp->next;
    }
}

int main() {
    createFile("file1.txt", 50);
    createFile("file2.txt", 100);
    createFile("file3.txt", 75);

    displayFiles();

    deleteFile("file2.txt");

    displayFiles();

    return 0;
}