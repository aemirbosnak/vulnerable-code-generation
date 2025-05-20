//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_BUFFER_SIZE 1024

typedef struct File
{
    char name[256];
    struct File* next;
    int size;
    char data[MAX_BUFFER_SIZE];
} File;

File* head = NULL;

void createFile(char* name, int size)
{
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = head;
    head = newFile;
    newFile->size = size;
    newFile->data[0] = '\0';
}

void writeFile(char* name, char* data)
{
    File* file = head;
    while (file)
    {
        if (strcmp(file->name, name) == 0)
        {
            int i = 0;
            while (data[i] != '\0')
            {
                file->data[i] = data[i];
                i++;
            }
            file->data[i] = '\0';
            break;
        }
        file = file->next;
    }

    if (file == NULL)
    {
        printf("Error: File not found.\n");
    }
}

void readFile(char* name)
{
    File* file = head;
    while (file)
    {
        if (strcmp(file->name, name) == 0)
        {
            printf("File contents: %s\n", file->data);
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
    readFile("test.txt");

    return 0;
}