//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry
{
    char name[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

typedef struct DirectoryEntry
{
    char name[MAX_FILE_NAME_LENGTH];
    struct DirectoryEntry* next;
    FileEntry* files;
} DirectoryEntry;

DirectoryEntry* root;

void createDirectory(char* name)
{
    DirectoryEntry* newDir = (DirectoryEntry*)malloc(sizeof(DirectoryEntry));
    strcpy(newDir->name, name);
    newDir->next = root;
    root = newDir;
}

void createFile(char* name, char* data)
{
    FileEntry* newFile = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    if (root == NULL)
    {
        createDirectory(".");
    }
    DirectoryEntry* currentDir = root;
    while (currentDir->next)
    {
        if (strcmp(currentDir->name, name) == 0)
        {
            currentDir->files = newFile;
            return;
        }
        currentDir = currentDir->next;
    }
    currentDir->files = newFile;
}

void listFiles(char* dirName)
{
    DirectoryEntry* currentDir = root;
    while (currentDir)
    {
        if (strcmp(currentDir->name, dirName) == 0)
        {
            FileEntry* file = currentDir->files;
            while (file)
            {
                printf("%s\n", file->name);
                file = file->next;
            }
        }
        currentDir = currentDir->next;
    }
}

int main()
{
    createDirectory("./");
    createFile("test.txt", "This is a file");
    listFiles("./");
    return 0;
}