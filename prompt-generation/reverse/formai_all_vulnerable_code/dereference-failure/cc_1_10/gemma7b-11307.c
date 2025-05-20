//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry
{
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

FileEntry* head = NULL;

void insertFile(char* filename, int size)
{
    FileEntry* newNode = malloc(sizeof(FileEntry));
    strcpy(newNode->filename, filename);
    newNode->size = size;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        FileEntry* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    insertFile("test.txt", 10);
    insertFile("image.jpg", 100);
    insertFile("document.doc", 20);

    FileEntry* current = head;
    while (current)
    {
        printf("Filename: %s, Size: %d\n", current->filename, current->size);
        current = current->next;
    }

    return 0;
}