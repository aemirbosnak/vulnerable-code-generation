//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    struct FileEntry* next;
} FileEntry;

FileEntry* InsertFileEntry(FileEntry* head, char* filename)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));

    strcpy(newEntry->filename, filename);
    newEntry->timestamp = time(NULL);
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

void PrintFileEntries(FileEntry* head)
{
    FileEntry* currentEntry = head;

    while (currentEntry)
    {
        printf("Filename: %s, Timestamp: %ld\n", currentEntry->filename, currentEntry->timestamp);
        currentEntry = currentEntry->next;
    }
}

int main()
{
    FileEntry* head = NULL;

    InsertFileEntry(head, "test.txt");
    InsertFileEntry(head, "image.jpg");
    InsertFileEntry(head, "music.mp3");

    PrintFileEntries(head);

    return 0;
}