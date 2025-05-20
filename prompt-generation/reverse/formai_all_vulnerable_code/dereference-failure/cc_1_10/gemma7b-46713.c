//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

void AddFileEntry(FileEntry** head, char* filename)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (*head == NULL)
    {
        *head = newEntry;
    }
    else
    {
        (*head)->next = newEntry;
    }
}

void BackupFiles(FileEntry* head)
{
    FILE* backupFile = fopen("backup.txt", "w");

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next)
    {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main()
{
    FileEntry* head = NULL;

    // Add some file entries
    AddFileEntry(&head, "a.txt");
    AddFileEntry(&head, "b.txt");
    AddFileEntry(&head, "c.txt");

    // Backup the files
    BackupFiles(head);

    return 0;
}