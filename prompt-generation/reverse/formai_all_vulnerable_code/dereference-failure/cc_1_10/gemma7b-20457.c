//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File
{
    char name[20];
    struct File* next;
    int data[1024];
} File;

File* head = NULL;

void createFile(char* name)
{
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    newFile->data[0] = 0;
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

void writeFile(char* name, int data)
{
    File* file = head;
    while (file)
    {
        if (strcmp(file->name, name) == 0)
        {
            file->data[file->data[0]] = data;
            file->data[0]++;
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
            for (int i = 0; file->data[i] != 0; i++)
            {
                printf("%d ", file->data[i]);
            }
            printf("\n");
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
    createFile("test.dat");
    writeFile("test.dat", 10);
    writeFile("test.dat", 20);
    readFile("test.dat");
    return 0;
}