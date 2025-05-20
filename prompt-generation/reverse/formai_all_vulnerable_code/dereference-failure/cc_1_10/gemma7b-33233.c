//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    struct File* next;
} File;

File* createFile(char* name)
{
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    file->next = NULL;
    return file;
}

void addFile(File* head, char* name)
{
    File* newFile = createFile(name);
    if (head == NULL)
    {
        head = newFile;
    }
    else
    {
        head->next = newFile;
    }
}

void listFiles(File* head)
{
    File* current = head;
    while (current)
    {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    File* files = NULL;

    // Create some files
    addFile(files, "a.txt");
    addFile(files, "b.txt");
    addFile(files, "c.txt");

    // List the files
    listFiles(files);

    // Print the files
    printf("The files are: ");
    listFiles(files);

    return 0;
}