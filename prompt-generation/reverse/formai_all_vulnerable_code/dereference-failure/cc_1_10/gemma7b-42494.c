//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    struct File* next;
    FILE* fp;
    int size;
    char data[1];
} File;

File* head = NULL;

void createFile(char* name, int size)
{
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->fp = fopen(name, "w");
    newFile->size = size;
    newFile->data[0] = '\0';

    if (head == NULL)
    {
        head = newFile;
    }
    else
    {
        head->next = newFile;
        head = newFile;
    }
}

void writeFile(char* name, char* data)
{
    File* file = head;

    while (file)
    {
        if (strcmp(file->name, name) == 0)
        {
            fprintf(file->fp, data);
            break;
        }
        file = file->next;
    }

    if (file == NULL)
    {
        printf("Error: File not found.\n");
    }
}

int main()
{
    createFile("test.txt", 10);
    writeFile("test.txt", "Hello, world!");

    return 0;
}