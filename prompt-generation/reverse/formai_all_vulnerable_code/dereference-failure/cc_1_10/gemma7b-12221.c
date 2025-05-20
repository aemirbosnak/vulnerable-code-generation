//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_NUM_FILES 100

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

void InsertFileEntry(FileEntry** head, char* filename)
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

int SearchFileEntry(FileEntry* head, char* filename)
{
    while (head)
    {
        if (strcmp(head->filename, filename) == 0)
        {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main()
{
    FileEntry* fileHead = NULL;
    InsertFileEntry(&fileHead, "test.txt");
    InsertFileEntry(&fileHead, "another.txt");
    InsertFileEntry(&fileHead, "foo.bar");

    if (SearchFileEntry(fileHead, "test.txt") == 1)
    {
        printf("File found.\n");
    }
    else
    {
        printf("File not found.\n");
    }

    return 0;
}