//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
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

int main()
{
    // Create a few files
    addFile("The Book of Secrets");
    addFile("The Last Hope");
    addFile("The Road to Freedom");

    // List the files
    listFiles();

    // Print the contents of a file
    printf("The contents of The Book of Secrets are:\n");
    FILE* file = fopen("The Book of Secrets", "r");
    char content[1024];
    fgets(content, 1024, file);
    printf("%s", content);
    fclose(file);

    return 0;
}