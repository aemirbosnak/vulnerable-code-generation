//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[50];
    struct FileEntry* next;
} FileEntry;

FileEntry* CreateFileEntry(char* filename) {
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;
    return newEntry;
}

void AddFileEntry(FileEntry* head, char* filename) {
    FileEntry* newEntry = CreateFileEntry(filename);
    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }
}

int SearchFile(FileEntry* head, char* filename) {
    while (head) {
        if (strcmp(head->filename, filename) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    FileEntry* fileHead = NULL;

    // Add some file entries
    AddFileEntry(fileHead, "Sherlock.txt");
    AddFileEntry(fileHead, "Watson.doc");
    AddFileEntry(fileHead, "The.Case.of.the.Missing.Tweedle.pdf");

    // Search for a file
    if (SearchFile(fileHead, "Watson.doc") == 1) {
        printf("File found!\n");
    } else {
        printf("File not found.\n");
    }

    return 0;
}