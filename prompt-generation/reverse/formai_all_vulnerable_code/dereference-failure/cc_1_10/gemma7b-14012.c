//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 10
#define FILE_SIZE_MAX 1024

typedef struct FileEntry
{
    char name[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void backup_file(FileEntry** head, char* filename, int size)
{
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->name, filename);
    new_entry->size = size;
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
    char filename[256];
    int size;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter file size: ");
    scanf("%d", &size);

    backup_file(&head, filename, size);

    printf("File backup successful.\n");

    return 0;
}