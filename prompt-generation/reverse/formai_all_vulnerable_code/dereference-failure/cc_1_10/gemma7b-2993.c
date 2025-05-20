//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    FILE* file;
} File;

File* insertFile(File* head, char* name) {
    File* newNode = (File*)malloc(sizeof(File));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->file = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void listFiles(File* head) {
    File* current = head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    File* files = NULL;

    // Insert some files
    insertFile(files, "a.txt");
    insertFile(files, "b.txt");
    insertFile(files, "c.txt");

    // List all files
    listFiles(files);

    // Open a file
    FILE* file = fopen("a.txt", "r");
    if (file) {
        printf("File opened successfully!\n");
    }

    return 0;
}