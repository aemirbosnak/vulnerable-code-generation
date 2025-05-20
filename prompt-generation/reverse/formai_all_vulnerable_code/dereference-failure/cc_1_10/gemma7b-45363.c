//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File
{
    char name[25];
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
        File* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newFile;
    }
}

void listFiles()
{
    File* temp = head;
    printf("Files:");
    while (temp)
    {
        printf(" %s", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    createFile("a.txt");
    createFile("b.txt");
    createFile("c.txt");
    listFiles();

    return 0;
}