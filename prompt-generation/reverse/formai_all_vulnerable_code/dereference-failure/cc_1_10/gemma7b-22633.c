//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct FileEntry {
    char *name;
    long size;
    struct FileEntry *next;
} FileEntry;

FileEntry *getFileEntry(char *name, long size) {
    FileEntry *newEntry = malloc(sizeof(FileEntry));
    newEntry->name = strdup(name);
    newEntry->size = size;
    newEntry->next = NULL;

    return newEntry;
}

void addFileEntry(FileEntry *head, char *name, long size) {
    FileEntry *newEntry = getFileEntry(name, size);

    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }
}

void backupFiles(FileEntry *head) {
    FILE *backupFile = fopen("backup.txt", "w");

    fprintf(backupFile, "Backup file for: %s\n", getpid());

    for (FileEntry *currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "File name: %s, Size: %ld\n", currentEntry->name, currentEntry->size);
    }

    fclose(backupFile);
}

int main() {
    FileEntry *head = NULL;

    // Add some file entries
    addFileEntry(head, "my_file.txt", 100);
    addFileEntry(head, "another_file.doc", 200);
    addFileEntry(head, "large_file.rar", 500);

    // Backup the files
    backupFiles(head);

    return 0;
}