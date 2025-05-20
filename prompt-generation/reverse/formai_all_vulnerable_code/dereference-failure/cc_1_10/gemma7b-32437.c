//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void insertFile(FileEntry** head, char* filename, int size) {
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

void backupFiles(FileEntry** head) {
    FILE* filePointer;
    FileEntry* currentEntry = *head;

    while (currentEntry) {
        filePointer = fopen(currentEntry->filename, "r");
        if (filePointer) {
            fprintf(stdout, "Backing up file: %s\n", currentEntry->filename);
            fread(currentEntry->filename, currentEntry->size, 1, filePointer);
            fclose(filePointer);
        } else {
            printf("Error backing up file: %s\n", currentEntry->filename);
        }
        currentEntry = currentEntry->next;
    }
}

int main() {
    FileEntry* head = NULL;
    insertFile(&head, "test.txt", 1024);
    insertFile(&head, "image.jpg", 12000);
    insertFile(&head, "music.mp3", 5000);

    backupFiles(&head);

    return 0;
}