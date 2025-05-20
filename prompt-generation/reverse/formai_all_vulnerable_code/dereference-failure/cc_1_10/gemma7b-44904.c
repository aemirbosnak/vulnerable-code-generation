//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_FILES 10

typedef struct FileEntry
{
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    struct FileEntry* next;
} FileEntry;

void add_file(FileEntry** head, char* file_name, int file_size)
{
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->file_name, file_name);
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

    // Add some files to the backup system
    add_file(&head, "my_file.txt", 100);
    add_file(&head, "my_image.jpg", 500);
    add_file(&head, "my_music.mp3", 200);

    // Print the file list
    for (FileEntry* current = head; current; current = current->next)
    {
        printf("%s (size: %d bytes)\n", current->file_name, current->file_size);
    }

    return 0;
}