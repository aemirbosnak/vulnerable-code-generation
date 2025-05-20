//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    struct File* next;
    int size;
    FILE* file;
} File;

File* head = NULL;

void createFile(char* name, int size)
{
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->file = fopen(name, "w");
    newFile->next = head;
    head = newFile;
}

void listFiles()
{
    File* currentFile = head;
    while (currentFile)
    {
        printf("%s (size: %d)\n", currentFile->name, currentFile->size);
        currentFile = currentFile->next;
    }
}

int main()
{
    // Create some files
    createFile("my_file.txt", 1024);
    createFile("another_file.txt", 2048);
    createFile("third_file.txt", 3072);

    // List the files
    listFiles();

    // Close the files
    File* currentFile = head;
    while (currentFile)
    {
        fclose(currentFile->file);
        currentFile = currentFile->next;
    }

    return 0;
}