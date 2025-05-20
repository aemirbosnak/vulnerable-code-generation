//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFileEntry(FileEntry* head, char* filename) {
    time_t timestamp = time(NULL);

    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->timestamp = timestamp;
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

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "File: %s, Timestamp: %ld\n", currentEntry->filename, currentEntry->timestamp);
    }

    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    // Insert some file entries
    insertFileEntry(head, "a.txt");
    insertFileEntry(head, "b.txt");
    insertFileEntry(head, "c.txt");

    // Backup the files
    backupFiles(head);

    return 0;
}