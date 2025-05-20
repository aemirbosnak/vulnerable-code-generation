//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Alan Turing
#include <stdio.h>

#define MAX_FILES 10

typedef struct File
{
    char name[20];
    int size;
    struct File* next;
} File;

File* head = NULL;

void createFile(char* name, int size)
{
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = NULL;

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

void readFile(char* name)
{
    File* currentFile = head;

    while (currentFile)
    {
        if (strcmp(currentFile->name, name) == 0)
        {
            printf("File size: %d\n", currentFile->size);
            break;
        }
        currentFile = currentFile->next;
    }

    if (currentFile == NULL)
    {
        printf("File not found\n");
    }
}

int main()
{
    createFile("test.txt", 10);
    createFile("another.txt", 20);
    readFile("test.txt");
    readFile("another.txt");

    return 0;
}