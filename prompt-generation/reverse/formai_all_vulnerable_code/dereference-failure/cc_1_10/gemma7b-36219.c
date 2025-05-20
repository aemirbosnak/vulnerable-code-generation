//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char filename[FILE_NAME_LENGTH];
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
    FILE* file = system->backupFile;
    system->head->next = NULL;
    FileEntry* currentEntry = system->head;

    while (currentEntry) {
        fprintf(file, "%s\n", currentEntry->filename);
        currentEntry = currentEntry->next;
    }

    fclose(file);
}

int main() {
    BackupSystem* system = malloc(sizeof(BackupSystem));
    system->head = NULL;
    system->backupFile = fopen("backup.txt", "w");

    insertFileEntry(system, "test.txt");
    insertFileEntry(system, "another.txt");

    backupFiles(system);

    fclose(system->backupFile);
    free(system);

    return 0;
}