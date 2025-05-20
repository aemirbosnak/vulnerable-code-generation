//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct FileRecord
{
    char filename[255];
    int size;
    struct FileRecord* next;
} FileRecord;

void insertFile(FileRecord** head, char* filename, int size)
{
    FileRecord* newNode = (FileRecord*)malloc(sizeof(FileRecord));
    strcpy(newNode->filename, filename);
    newNode->size = size;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void backupFiles(FileRecord* head)
{
    FILE* backupFile = fopen("backup.dat", "w");
    fprintf(backupFile, "Total number of files: %d\n", head->size);

    for (FileRecord* current = head; current; current = current->next)
    {
        fprintf(backupFile, "Filename: %s\n", current->filename);
        fprintf(backupFile, "Size: %d bytes\n", current->size);
        fprintf(backupFile, "\n");
    }

    fclose(backupFile);
}

int main()
{
    FileRecord* head = NULL;

    insertFile(&head, "poem.txt", 100);
    insertFile(&head, "photo.jpg", 200);
    insertFile(&head, "music.mp3", 500);

    backupFiles(head);

    return 0;
}