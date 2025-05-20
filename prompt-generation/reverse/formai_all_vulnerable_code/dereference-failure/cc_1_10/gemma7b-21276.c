//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct FileEntry {
    char filename[256];
    long size;
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* filename, long size) {
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

void backupFile(FileEntry* head) {
    FILE* backupFile = fopen("backup.txt", "w");

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "Filename: %s, Size: %ld\n", currentEntry->filename, currentEntry->size);
    }

    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    // Insert some files into the list
    insertFile(head, "file1.txt", 1024);
    insertFile(head, "file2.txt", 2048);
    insertFile(head, "file3.txt", 3072);

    // Backup the files
    backupFile(head);

    return 0;
}