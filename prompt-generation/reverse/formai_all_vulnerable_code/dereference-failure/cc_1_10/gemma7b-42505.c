//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileHeader
{
    char filename[256];
    int size;
    struct FileHeader* next;
} FileHeader;

FileHeader* CreateFileHeader(char* filename, int size)
{
    FileHeader* header = (FileHeader*)malloc(sizeof(FileHeader));

    strcpy(header->filename, filename);
    header->size = size;
    header->next = NULL;

    return header;
}

void AddFileHeader(FileHeader* head, char* filename, int size)
{
    FileHeader* newHeader = CreateFileHeader(filename, size);

    if (head == NULL)
    {
        head = newHeader;
    }
    else
    {
        head->next = newHeader;
        head = newHeader;
    }
}

int main()
{
    FileHeader* head = NULL;

    // Add some file headers
    AddFileHeader(head, "a.txt", 10);
    AddFileHeader(head, "b.txt", 20);
    AddFileHeader(head, "c.txt", 30);

    // Recover file headers
    FileHeader* currentHeader = head;
    while (currentHeader)
    {
        printf("Filename: %s, Size: %d\n", currentHeader->filename, currentHeader->size);
        currentHeader = currentHeader->next;
    }

    return 0;
}