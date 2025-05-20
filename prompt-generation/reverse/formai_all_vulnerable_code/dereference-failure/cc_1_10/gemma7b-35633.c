//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256

typedef struct FileEntry {
    char name[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

FileEntry* root = NULL;

void InsertFileEntry(char* name) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (root == NULL) {
        root = newEntry;
    } else {
        FileEntry* currentEntry = root;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

int FindFileEntry(char* name) {
    FileEntry* currentEntry = root;
    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            return 1;
        }
        currentEntry = currentEntry->next;
    }
    return 0;
}

int main() {
    InsertFileEntry("test.txt");
    InsertFileEntry("my.doc");
    InsertFileEntry("image.jpg");

    if (FindFileEntry("test.txt")) {
        printf("File found: test.txt\n");
    } else {
        printf("File not found: test.txt\n");
    }

    return 0;
}