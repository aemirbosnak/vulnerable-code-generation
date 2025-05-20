//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry
{
    char name[255];
    struct FileEntry* next;
} FileEntry;

void backup(FileEntry* head)
{
    FILE* file = fopen("backup.txt", "w");
    fprintf(file, "Files:\n");

    for (FileEntry* current = head; current; current = current->next)
    {
        fprintf(file, "%s\n", current->name);
    }

    fclose(file);
}

int main()
{
    FileEntry* head = NULL;

    // Simulate file creation and addition
    for (int i = 0; i < MAX_FILES; i++)
    {
        FileEntry* newEntry = malloc(sizeof(FileEntry));
        strcpy(newEntry->name, "File " + i);
        newEntry->next = head;
        head = newEntry;
    }

    // Backup files
    backup(head);

    // Print backup file contents
    FILE* file = fopen("backup.txt", "r");
    char line[255];
    while (fgets(line, 255, file) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(file);

    return 0;
}