//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry
{
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void insertFileEntry(FileEntry** head, char* filename, int size)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));

    strcpy(newEntry->filename, filename);
    newEntry->size = size;
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
    FILE* filePtr;
    FileEntry* currentEntry = head;

    while (currentEntry)
    {
        filePtr = fopen(currentEntry->filename, "r");
        if (filePtr)
        {
            int fileSize = currentEntry->size;
            char* buffer = malloc(fileSize);

            fread(buffer, fileSize, 1, filePtr);
            fclose(filePtr);

            printf("Backup of file %s successful!\n", currentEntry->filename);
            free(buffer);
        }
        else
        {
            printf("Error backing up file %s.\n", currentEntry->filename);
        }

        currentEntry = currentEntry->next;
    }
}

int main()
{
    FileEntry* head = NULL;
    insertFileEntry(&head, "test.txt", 1024);
    insertFileEntry(&head, "image.jpg", 512);
    insertFileEntry(&head, "document.doc", 2048);

    backupFiles(head);

    return 0;
}