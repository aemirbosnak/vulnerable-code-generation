//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

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
    FILE* filePointer;
    char backupDirectory[256];
    sprintf(backupDirectory, "/home/backup/%s", head->filename);

    filePointer = fopen(backupDirectory, "w");
    fprintf(filePointer, "%s", head->filename);
    fprintf(filePointer, "\n");
    fprintf(filePointer, "%d", head->size);
    fprintf(filePointer, "\n");

    fclose(filePointer);
}

int main() {
    FileEntry* head = NULL;
    insertFileEntry(&head, "file1.txt", 100);
    insertFileEntry(&head, "file2.txt", 200);
    insertFileEntry(&head, "file3.txt", 300);

    backupFiles(head);

    return 0;
}