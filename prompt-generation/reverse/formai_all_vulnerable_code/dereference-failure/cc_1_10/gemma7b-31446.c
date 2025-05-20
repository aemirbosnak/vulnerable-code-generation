//Gemma-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry
{
    char filename[MAX_BUFFER_SIZE];
    int file_size;
    struct FileEntry* next;
} FileEntry;

FILE* open_file(char* filename)
{
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL)
    {
        return NULL;
    }
    return file_ptr;
}

void close_file(FILE* file_ptr)
{
    fclose(file_ptr);
}

int read_file(FILE* file_ptr, char* buffer, int buffer_size)
{
    return fread(buffer, 1, buffer_size, file_ptr);
}

int write_file(FILE* file_ptr, char* buffer, int buffer_size)
{
    return fwrite(buffer, 1, buffer_size, file_ptr);
}

void insert_file_entry(FileEntry** head, char* filename, int file_size)
{
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->filename, filename);
    new_entry->file_size = file_size;
    new_entry->next = NULL;

    if (*head == NULL)
    {
        *head = new_entry;
    }
    else
    {
        (*head)->next = new_entry;
    }
}

int main()
{
    FileEntry* head = NULL;

    insert_file_entry(&head, "test.txt", 10);
    insert_file_entry(&head, "hello.txt", 20);
    insert_file_entry(&head, "world.txt", 30);

    char buffer[MAX_BUFFER_SIZE];

    read_file(open_file("test.txt"), buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    write_file(open_file("hello.txt"), buffer, MAX_BUFFER_SIZE);

    close_file(open_file("world.txt"));

    return 0;
}