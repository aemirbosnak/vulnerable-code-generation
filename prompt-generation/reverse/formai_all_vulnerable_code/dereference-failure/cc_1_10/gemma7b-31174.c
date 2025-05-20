//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry
{
    char name[256];
    struct FileEntry* next;
} FileEntry;

FileEntry* head = NULL;

void addFile(char* name)
{
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
        head = newEntry;
    }
}

void backupFiles()
{
    FILE* backupFile = fopen("backup.txt", "w");

    FileEntry* currentEntry = head;

    while (currentEntry)
    {
        fprintf(backupFile, "%s\n", currentEntry->name);
        currentEntry = currentEntry->next;
    }

    fclose(backupFile);
}

int main()
{
    // Add some files
    addFile("file1.txt");
    addFile("file2.txt");
    addFile("file3.txt");

    // Backup the files
    backupFiles();

    // Print the backed up files
    FILE* backupFile = fopen("backup.txt", "r");

    char line[256];

    while (fgets(line, 256, backupFile) != NULL)
    {
        printf("%s\n", line);
    }

    fclose(backupFile);

    return 0;
}