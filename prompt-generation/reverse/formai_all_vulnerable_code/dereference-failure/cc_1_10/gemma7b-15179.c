//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BUFFER_SIZE 256

typedef struct File
{
    char name[256];
    char data[MAX_BUFFER_SIZE];
    struct File* next;
} File;

File* head = NULL;

void createFile(char* name, char* data)
{
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    strcpy(newFile->data, data);
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
            printf("%s\n", currentFile->data);
            break;
        }
        currentFile = currentFile->next;
    }

    if (currentFile == NULL)
    {
        printf("File not found.\n");
    }
}

void writeFile(char* name, char* data)
{
    File* currentFile = head;

    while (currentFile)
    {
        if (strcmp(currentFile->name, name) == 0)
        {
            strcpy(currentFile->data, data);
            break;
        }
        currentFile = currentFile->next;
    }

    if (currentFile == NULL)
    {
        printf("File not found.\n");
    }
}

int main()
{
    createFile("test.txt", "This is a test file.");
    writeFile("test.txt", "Updated data.");
    readFile("test.txt");

    return 0;
}