//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileBackupEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    int version;
    struct FileBackupEntry* next;
} FileBackupEntry;

FileBackupEntry* InsertFileEntry(FileBackupEntry* head, char* filename, int version)
{
    FileBackupEntry* newEntry = malloc(sizeof(FileBackupEntry));
    strcpy(newEntry->filename, filename);
    newEntry->version = version;
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
    }

    return head;
}

void PrintFileEntries(FileBackupEntry* head)
{
    FileBackupEntry* currentEntry = head;

    while (currentEntry)
    {
        printf("Filename: %s, Version: %d\n", currentEntry->filename, currentEntry->version);
        currentEntry = currentEntry->next;
    }
}

int main()
{
    FileBackupEntry* head = NULL;

    InsertFileEntry(head, "test.txt", 1);
    InsertFileEntry(head, "image.jpg", 2);
    InsertFileEntry(head, "document.doc", 3);

    PrintFileEntries(head);

    return 0;
}