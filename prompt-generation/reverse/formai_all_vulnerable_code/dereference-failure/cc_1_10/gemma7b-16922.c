//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry
{
    char filename[256];
    struct FileEntry* next;
} FileEntry;

int main()
{
    // Create a linked list of file entries
    FileEntry* head = NULL;

    // Simulate the case by adding some file entries
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->filename, "Sherlock.doc");
    new_entry->next = head;
    head = new_entry;

    new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->filename, "Watson.doc");
    new_entry->next = head;
    head = new_entry;

    // The client's files have been stolen! Search for them...
    FileEntry* current_entry = head;
    while (current_entry)
    {
        printf("Searching for file: %s\n", current_entry->filename);

        // Check if the file is missing...
        if (strcmp(current_entry->filename, "Sherlock.doc") == 0)
        {
            printf("File found: Sherlock.doc\n");
        }
        else if (strcmp(current_entry->filename, "Watson.doc") == 0)
        {
            printf("File found: Watson.doc\n");
        }
        else
        {
            printf("File not found: %s\n", current_entry->filename);
        }

        current_entry = current_entry->next;
    }

    return 0;
}