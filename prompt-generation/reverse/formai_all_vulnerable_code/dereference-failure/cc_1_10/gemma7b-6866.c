//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

FileEntry* CreateFileEntry(char* filename)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;
    return newEntry;
}

void AppendFileEntry(FileEntry* head, char* filename)
{
    FileEntry* newEntry = CreateFileEntry(filename);
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

int BackupFiles(FileEntry* head)
{
    int totalBytes = 0;
    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next)
    {
        struct stat statBuf;
        stat(currentEntry->filename, &statBuf);
        totalBytes += statBuf.st_size;
    }
    return totalBytes;
}

int main()
{
    FileEntry* fileHead = NULL;
    AppendFileEntry(fileHead, "file1.txt");
    AppendFileEntry(fileHead, "file2.txt");
    AppendFileEntry(fileHead, "file3.txt");

    int totalBytes = BackupFiles(fileHead);
    printf("Total bytes backed up: %d\n", totalBytes);

    return 0;
}