//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define BUFFER_SIZE 256

typedef struct FileEntry
{
    char filename[256];
    struct FileEntry* next;
} FileEntry;

void backup_file(FileEntry* head, char* filename, char* data)
{
    FileEntry* new_entry = malloc(sizeof(FileEntry));

    strcpy(new_entry->filename, filename);
    new_entry->next = NULL;

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        head->next = new_entry;
    }

    FILE* file = fopen(filename, "w");
    fprintf(file, data);
    fclose(file);
}

int main()
{
    FileEntry* head = NULL;

    // Backup a few files
    backup_file(head, "myfile.txt", "This is my file data.");
    backup_file(head, "myimage.jpg", "Binary data for my image.");

    // Print the list of backed up files
    FileEntry* current = head;
    while (current)
    {
        printf("%s\n", current->filename);
        current = current->next;
    }

    return 0;
}