//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry {
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void insertFileEntry(FileEntry** head, char* filename, int size) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

void backupFiles(FileEntry* head) {
    FILE* filePtr;
    FileEntry* currentEntry = head;

    while (currentEntry) {
        filePtr = fopen(currentEntry->filename, "rb");
        if (filePtr) {
            fprintf(stdout, "Backing up file: %s\n", currentEntry->filename);
            fwrite(filePtr, currentEntry->size, 1, stdout);
            fclose(filePtr);
        }
        currentEntry = currentEntry->next;
    }
}

int main() {
    FileEntry* head = NULL;

    insertFileEntry(&head, "test.txt", 10);
    insertFileEntry(&head, "image.jpg", 50);
    insertFileEntry(&head, "document.doc", 20);

    backupFiles(head);

    return 0;
}