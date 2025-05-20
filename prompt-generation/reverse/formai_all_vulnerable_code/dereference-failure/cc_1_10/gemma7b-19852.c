//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    struct File* next;
} File;

File* head = NULL;

void addFile(char* name)
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

void searchFile(char* name)
{
    File* currentFile = head;
    while (currentFile)
    {
        if (strcmp(currentFile->name, name) == 0)
        {
            printf("File found: %s\n", currentFile->name);
            return;
        }
        currentFile = currentFile->next;
    }

    printf("File not found.\n");
}

int main()
{
    // Add some files
    addFile("test.txt");
    addFile("my.doc");
    addFile("image.jpg");

    // List the files
    listFiles();

    // Search for a file
    searchFile("my.doc");

    return 0;
}