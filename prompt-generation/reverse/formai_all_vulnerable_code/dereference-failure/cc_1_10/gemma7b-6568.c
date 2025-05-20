//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

void insertFileEntry(FileEntry** head, char* filename)
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

void backupFiles(FileEntry* head)
{
    FILE* backupFile = fopen("backup.dat", "w");

    for (FileEntry* currentEntry = head; currentEntry != NULL; currentEntry = currentEntry->next)
    {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main()
{
    FileEntry* fileHead = NULL;

    insertFileEntry(&fileHead, "file1.txt");
    insertFileEntry(&fileHead, "file2.doc");
    insertFileEntry(&fileHead, "file3.jpg");

    backupFiles(fileHead);

    return 0;
}