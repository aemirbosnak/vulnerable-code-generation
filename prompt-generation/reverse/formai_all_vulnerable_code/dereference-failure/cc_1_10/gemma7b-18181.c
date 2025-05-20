//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File
{
    char name[256];
    struct File* next;
    FILE* file;
} File;

File* file_create(char* name)
{
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    file->next = NULL;
    file->file = fopen(name, "w");
    return file;
}

void file_add(File* file, char* name)
{
    File* new_file = file_create(name);
    if (file)
    {
        new_file->next = file->next;
        file->next = new_file;
    }
    else
    {
        file = new_file;
    }
}

void file_list(File* file)
{
    while (file)
    {
        printf("%s\n", file->name);
        file = file->next;
    }
}

int main()
{
    File* root = NULL;

    file_add(root, "a.txt");
    file_add(root, "b.txt");
    file_add(root, "c.txt");

    file_list(root);

    fclose(root->file);
    fclose(root->next->file);
    fclose(root->next->next->file);

    free(root);
    free(root->next);
    free(root->next->next);

    return 0;
}