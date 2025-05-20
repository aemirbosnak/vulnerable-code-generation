//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry {
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void insertFileEntry(FileEntry** head, char* filename, int size) {
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
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
            int fileSize = currentEntry->size;
            char* data = (char*)malloc(fileSize);
            fread(data, fileSize, 1, filePtr);
            fclose(filePtr);

            printf("Backing up file: %s\n", currentEntry->filename);
            printf("Size: %d bytes\n", fileSize);
            printf("Data: %s\n", data);
            printf("\n");
        }
        currentEntry = currentEntry->next;
    }
}

int main() {
    FileEntry* head = NULL;
    insertFileEntry(&head, "test.txt", 10);
    insertFileEntry(&head, "image.jpg", 1000);
    insertFileEntry(&head, "documents.pdf", 2000);

    backupFiles(head);

    return 0;
}