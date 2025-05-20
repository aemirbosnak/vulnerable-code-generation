//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_FILES 10

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* filename)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));
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

    return head;
}

int main()
{
    FileEntry* head = NULL;

    // Insert files into the linked list
    insertFile(head, "Romeo.txt");
    insertFile(head, "Juliet.txt");
    insertFile(head, "Montague.txt");
    insertFile(head, "Capulet.txt");

    // Print the files in the linked list
    FileEntry* currentFile = head;
    while (currentFile)
    {
        printf("%s\n", currentFile->filename);
        currentFile = currentFile->next;
    }

    return 0;
}