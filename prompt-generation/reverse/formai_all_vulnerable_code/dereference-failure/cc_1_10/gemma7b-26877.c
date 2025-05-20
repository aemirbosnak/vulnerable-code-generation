//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 1024

typedef struct FileEntry {
    char filename[256];
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* filename) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void backupFiles(FileEntry* head) {
    FILE* backupFile = fopen("backup.txt", "w");
    fprintf(backupFile, "Files:\n");

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    // Insert some file entries
    insertFile(head, "a.txt");
    insertFile(head, "b.txt");
    insertFile(head, "c.txt");

    // Backup the files
    backupFiles(head);

    return 0;
}