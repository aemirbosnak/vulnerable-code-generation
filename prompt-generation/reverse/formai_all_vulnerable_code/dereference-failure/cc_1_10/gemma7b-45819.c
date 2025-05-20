//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10
#define BUFFER_SIZE 256

typedef struct FileEntry
{
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void backup_file(FileEntry* head, char* filename, int size)
{
    FileEntry* new_entry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(new_entry->filename, filename);
    new_entry->size = size;
    new_entry->next = NULL;

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        head->next = new_entry;
    }

    head = new_entry;
}

int main()
{
    FileEntry* head = NULL;
    backup_file(head, "my_file.txt", 1024);
    backup_file(head, "another_file.txt", 2048);
    backup_file(head, "a_third_file.txt", 3072);

    // Print the backup file list
    FileEntry* current = head;
    while (current)
    {
        printf("Filename: %s, Size: %d\n", current->filename, current->size);
        current = current->next;
    }

    return 0;
}