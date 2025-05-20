//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File
{
    char name[20];
    struct File* next;
} File;

File* head = NULL;

void createFile(char* name)
{
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
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

void listFiles()
{
    File* currentFile = head;

    while (currentFile)
    {
        printf("%s\n", currentFile->name);
        currentFile = currentFile->next;
    }
}

int main()
{
    createFile("test.txt");
    createFile("hello.c");
    createFile("my.doc");

    listFiles();

    return 0;
}