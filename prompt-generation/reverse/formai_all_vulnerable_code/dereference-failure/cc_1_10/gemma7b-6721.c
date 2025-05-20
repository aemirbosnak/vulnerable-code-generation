//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry
{
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

typedef struct BackupSystem
{
    FileEntry* head;
    time_t lastBackupTime;
} BackupSystem;

void backupFile(BackupSystem* system, char* filename, int size)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (system->head == NULL)
    {
        system->head = newEntry;
    }
    else
    {
        FileEntry* currentEntry = system->head;
        while (currentEntry->next)
        {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }

    system->lastBackupTime = time(NULL);
}

int main()
{
    BackupSystem* system = malloc(sizeof(BackupSystem));
    system->head = NULL;
    system->lastBackupTime = time(NULL);

    backupFile(system, "my_precious_file.txt", 1000);
    backupFile(system, "my_even_more_precious_file.txt", 2000);
    backupFile(system, "my_completely_unimportant_file.txt", 500);

    FILE* file = fopen("backup.txt", "w");
    fprintf(file, "Files backed up:\n");
    for (FileEntry* entry = system->head; entry; entry = entry->next)
    {
        fprintf(file, "%s (size: %d bytes)\n", entry->filename, entry->size);
    }
    fclose(file);

    return 0;
}