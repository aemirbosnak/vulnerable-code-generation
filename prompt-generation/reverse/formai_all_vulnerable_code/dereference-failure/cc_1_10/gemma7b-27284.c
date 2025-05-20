//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[255];
    int size;
    struct FileEntry* next;
} FileEntry;

FileEntry* head = NULL;

void insertFile(char* filename, int size) {
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        FileEntry* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }
}

void backupFiles() {
    FILE* backupFile = fopen("backup.txt", "w");
    fprintf(backupFile, "Backup of files:\n");

    FileEntry* currentEntry = head;
    while (currentEntry) {
        fprintf(backupFile, "%s (size: %d)\n", currentEntry->filename, currentEntry->size);
        currentEntry = currentEntry->next;
    }

    fclose(backupFile);
}

int main() {
    insertFile("my_file.txt", 100);
    insertFile("another_file.doc", 200);

    backupFiles();

    return 0;
}