//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry
{
    char *name;
    struct FileEntry *next;
} FileEntry;

void insertFileEntry(FileEntry **head, char *name)
{
    FileEntry *newEntry = malloc(sizeof(FileEntry));
    newEntry->name = strdup(name);
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

int main()
{
    FileEntry *head = NULL;

    insertFileEntry(&head, "test.txt");
    insertFileEntry(&head, "image.jpg");
    insertFileEntry(&head, "document.doc");

    FILE *fp;
    fp = fopen("backup.bin", "wb");

    FileEntry *currentEntry = head;
    while (currentEntry)
    {
        fprintf(fp, "%s\n", currentEntry->name);
        currentEntry = currentEntry->next;
    }

    fclose(fp);

    return 0;
}