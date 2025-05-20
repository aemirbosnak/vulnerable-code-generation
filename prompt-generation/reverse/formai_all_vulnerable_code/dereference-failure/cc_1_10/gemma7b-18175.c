//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

typedef struct BackupSystem {
    FileEntry* head;
    FILE* backupFile;
} BackupSystem;

void insertFileEntry(BackupSystem* system, char* filename) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (system->head == NULL) {
        system->head = newEntry;
    } else {
        system->head->next = newEntry;
    }
}

void backupFiles(BackupSystem* system) {
    system->backupFile = fopen("backup.txt", "w");

    FileEntry* currentEntry = system->head;
    while (currentEntry) {
        fprintf(system->backupFile, "%s\n", currentEntry->filename);
        currentEntry = currentEntry->next;
    }

    fclose(system->backupFile);
}

int main() {
    BackupSystem* system = malloc(sizeof(BackupSystem));
    system->head = NULL;
    system->backupFile = NULL;

    insertFileEntry(system, "example.txt");
    insertFileEntry(system, "another.txt");

    backupFiles(system);

    return 0;
}