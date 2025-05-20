//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry
{
    char filename[255];
    int size;
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFileEntry(FileEntry* head, char* filename, int size)
{
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
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
    FileEntry* currentEntry = head;

    while (currentEntry)
    {
        filePtr = fopen(currentEntry->filename, "rb");
        if (filePtr == NULL)
        {
            printf("Error opening file: %s", currentEntry->filename);
            return;
        }

        // Backup file data
        unsigned char* data = (unsigned char*)malloc(currentEntry->size);
        fread(data, 1, currentEntry->size, filePtr);

        // Write data to backup file
        FILE* backupFile = fopen("backup.dat", "a");
        fwrite(data, 1, currentEntry->size, backupFile);

        fclose(filePtr);
        fclose(backupFile);

        currentEntry = currentEntry->next;
    }
}

int main()
{
    FileEntry* head = NULL;

    // Insert file entries
    insertFileEntry(head, "file1.txt", 1024);
    insertFileEntry(head, "file2.jpg", 2048);
    insertFileEntry(head, "file3.doc", 512);

    // Backup files
    backupFiles(head);

    return 0;
}