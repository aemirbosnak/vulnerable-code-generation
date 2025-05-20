//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

FileEntry* InsertFile(FileEntry* head, char* filename, int size) {
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void BackupFiles(FileEntry* head) {
    FILE* filePointer;
    FILE* backupFile = fopen("backup.dat", "w");

    for (FileEntry* currentEntry = head; currentEntry != NULL; currentEntry = currentEntry->next) {
        filePointer = fopen(currentEntry->filename, "r");
        fprintf(backupFile, "%s\n", currentEntry->filename);
        fread(backupFile, currentEntry->size, 1, filePointer);
        fclose(filePointer);
    }

    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    // Insert some files
    InsertFile(head, "file1.txt", 1024);
    InsertFile(head, "file2.txt", 2048);
    InsertFile(head, "file3.txt", 3072);

    // Backup the files
    BackupFiles(head);

    return 0;
}