//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry
{
    char name[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
    struct FileEntry* parent;
    int size;
    FILE* file;
} FileEntry;

typedef struct DirectoryEntry
{
    char name[MAX_FILE_NAME_LENGTH];
    struct DirectoryEntry* next;
    struct DirectoryEntry* parent;
    FileEntry** files;
} DirectoryEntry;

DirectoryEntry* rootDirectory = NULL;

void createFile(char* name, int size)
{
    FileEntry* newFile = malloc(sizeof(FileEntry));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->file = fopen(name, "w");
    newFile->next = NULL;
    newFile->parent = NULL;

    if (rootDirectory == NULL)
    {
        rootDirectory = malloc(sizeof(DirectoryEntry));
        strcpy(rootDirectory->name, "/");
        rootDirectory->next = NULL;
        rootDirectory->parent = NULL;
        rootDirectory->files = NULL;
    }

    DirectoryEntry* currentDirectory = rootDirectory;
    while (currentDirectory->next)
    {
        currentDirectory = currentDirectory->next;
    }

    currentDirectory->files = newFile;
}

void listFiles(DirectoryEntry* directory)
{
    for (FileEntry* file = directory->files; file; file = file->next)
    {
        printf("%s\n", file->name);
    }
}

int main()
{
    createFile("test.txt", 10);
    createFile("folder1", 0);
    createFile("folder2", 0);
    listFiles(rootDirectory);

    return 0;
}