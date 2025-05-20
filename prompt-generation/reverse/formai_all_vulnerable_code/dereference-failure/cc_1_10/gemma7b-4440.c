//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry
{
    char filename[256];
    struct FileEntry* next;
} FileEntry;

void insertFileEntry(FileEntry* head, char* filename)
{
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
    }
}

void backupFiles(FileEntry* head)
{
    FILE* backupFile = fopen("backup.txt", "w");

    for (FileEntry* currentEntry = head; currentEntry != NULL; currentEntry = currentEntry->next)
    {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main()
{
    FileEntry* head = NULL;

    insertFileEntry(head, "test.txt");
    insertFileEntry(head, "image.jpg");
    insertFileEntry(head, "documents.pdf");

    backupFiles(head);

    return 0;
}