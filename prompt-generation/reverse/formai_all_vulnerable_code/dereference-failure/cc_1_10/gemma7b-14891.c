//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry
{
    char filename[256];
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* filename)
{
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
    }

    return head;
}

void backupFiles(FileEntry* head)
{
    FILE* filePtr;
    char backupDir[256];
    sprintf(backupDir, "/backup/%s", head->filename);

    filePtr = fopen(backupDir, "w");

    fprintf(filePtr, "%s", head->filename);
    fprintf(filePtr, "\n");

    fclose(filePtr);
}

int main()
{
    FileEntry* head = NULL;
    char filename[256];

    printf("Enter filename: ");
    scanf("%s", filename);

    insertFile(head, filename);

    printf("Enter another filename (optional): ");
    scanf("%s", filename);

    if (filename[0] != '\0')
    {
        insertFile(head, filename);
    }

    backupFiles(head);

    printf("Files backed up successfully!\n");

    return 0;
}