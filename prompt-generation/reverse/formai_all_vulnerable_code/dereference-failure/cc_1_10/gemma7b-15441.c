//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileBackupEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    struct FileBackupEntry* next;
} FileBackupEntry;

void insert_file_backup(FileBackupEntry** head, char* filename)
{
    time_t timestamp = time(NULL);

    FileBackupEntry* new_entry = malloc(sizeof(FileBackupEntry));
    strcpy(new_entry->filename, filename);
    new_entry->timestamp = timestamp;
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

void print_file_backup(FileBackupEntry* head)
{
    while (head)
    {
        printf("%s - %s\n", head->filename, ctime(head->timestamp));
        head = head->next;
    }
}

int main()
{
    FileBackupEntry* head = NULL;

    insert_file_backup(&head, "a.txt");
    insert_file_backup(&head, "b.txt");
    insert_file_backup(&head, "c.txt");

    print_file_backup(head);

    return 0;
}