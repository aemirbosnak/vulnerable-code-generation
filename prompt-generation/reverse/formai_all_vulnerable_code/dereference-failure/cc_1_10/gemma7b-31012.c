//Gemma-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct File
{
    char name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    struct File *next;
} File;

File *head = NULL;

void createFile(char *name)
{
    File *new = malloc(sizeof(File));
    strcpy(new->name, name);
    new->fp = fopen(name, "w");
    new->next = head;
    head = new;
}

void writeFile(char *name, char *data)
{
    File *file = head;
    while (file)
    {
        if (strcmp(file->name, name) == 0)
        {
            fprintf(file->fp, data);
            fclose(file->fp);
            return;
        }
        file = file->next;
    }
    printf("Error: File not found.\n");
}

int main()
{
    createFile("test.txt");
    writeFile("test.txt", "This is a file");
    writeFile("another.txt", "Another file");

    FILE *fp = fopen("test.txt", "r");
    char data[1024];
    fscanf(fp, "%s", data);
    printf("%s", data);

    fclose(fp);

    return 0;
}