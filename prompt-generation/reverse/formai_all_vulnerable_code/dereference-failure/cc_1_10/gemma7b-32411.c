//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    struct File* next;
    char data[1024];
} File;

File* head = NULL;

void createFile(char* name, char* data)
{
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = head;
    head = newFile;

    if (data)
    {
        strcpy(newFile->data, data);
    }
}

void readFile(char* name)
{
    File* currentFile = head;

    while (currentFile)
    {
        if (strcmp(currentFile->name, name) == 0)
        {
            printf("%s\n", currentFile->data);
            return;
        }
        currentFile = currentFile->next;
    }

    printf("File not found.\n");
}

int main()
{
    // Create some files
    createFile("my.txt", "This is my file.");
    createFile("another.txt", "This is another file.");

    // Read a file
    readFile("my.txt");

    // Read a file that does not exist
    readFile("non-existent.txt");

    return 0;
}