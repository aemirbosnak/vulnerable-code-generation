//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[256];
    struct FileEntry* next;
} FileEntry;

void insertFile(FileEntry** head, char* filename) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

void backupFiles(FileEntry* head) {
    FILE* file;
    char backupDirectory[256];
    sprintf(backupDirectory, "/path/to/backup/directory");

    file = fopen(backupDirectory, "w");
    fprintf(file, "Backup of files on %s\n", __DATE__);

    for (FileEntry* current = head; current; current = current->next) {
        fprintf(file, "Filename: %s\n", current->filename);
        file = fopen(current->filename, "r");
        fprintf(file, "%s\n", fread(NULL, 1, 1024, file));
        fclose(file);
    }

    fclose(file);
}

int main() {
    FileEntry* head = NULL;
    insertFile(&head, "file1.txt");
    insertFile(&head, "file2.txt");
    insertFile(&head, "file3.txt");

    backupFiles(head);

    return 0;
}