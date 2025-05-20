//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 255

typedef struct File
{
    char name[MAX_FILE_NAME_LENGTH];
    struct File* next;
    FILE* file_ptr;
} File;

File* head = NULL;

void add_file(char* name)
{
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->next = NULL;
    new_file->file_ptr = NULL;

    if (head == NULL)
    {
        head = new_file;
    }
    else
    {
        head->next = new_file;
        head = new_file;
    }
}

void list_files()
{
    File* current_file = head;

    while (current_file)
    {
        printf("%s\n", current_file->name);
        current_file = current_file->next;
    }
}

void open_file(char* name)
{
    File* current_file = head;

    while (current_file)
    {
        if (strcmp(current_file->name, name) == 0)
        {
            current_file->file_ptr = fopen(current_file->name, "r");
            break;
        }
        current_file = current_file->next;
    }

    if (current_file == NULL)
    {
        printf("Error: File not found.\n");
    }
}

int main()
{
    add_file("test.txt");
    add_file("another.txt");
    add_file("foo.bar");

    list_files();

    open_file("test.txt");

    fclose(head->file_ptr);

    return 0;
}