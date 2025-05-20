//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
} File;

File* head = NULL;

void insertFile(char* name) {
    File* newNode = malloc(sizeof(File));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

int searchFile(char* name) {
    File* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void deleteFile(char* name) {
    File* current = head;
    File* previous = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    return;
}

int main() {
    insertFile("a.txt");
    insertFile("b.txt");
    insertFile("c.txt");

    if (searchFile("a.txt")) {
        printf("File a.txt found.\n");
    }

    deleteFile("b.txt");

    if (searchFile("b.txt")) {
        printf("File b.txt not found.\n");
    }

    return 0;
}