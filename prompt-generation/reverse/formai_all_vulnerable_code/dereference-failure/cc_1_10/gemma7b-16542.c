//Gemma-7B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    int size;
    struct File* next;
} File;

void insertFile(File** head, char* name, int size)
{
    File* newNode = (File*)malloc(sizeof(File));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

int main()
{
    File* head = NULL;

    insertFile(&head, "file1.txt", 100);
    insertFile(&head, "file2.txt", 200);
    insertFile(&head, "file3.txt", 300);
    insertFile(&head, "file4.txt", 400);

    FILE* filePointer = fopen("file2.txt", "r");
    if (filePointer == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        printf("File contents:\n");
        char buffer[1024];
        int readBytes = fread(buffer, 1, 1024, filePointer);
        printf("%s", buffer);
        fclose(filePointer);
    }

    return 0;
}