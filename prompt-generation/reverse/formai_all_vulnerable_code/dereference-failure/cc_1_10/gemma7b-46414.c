//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_NUM_FILES 100

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

FileEntry* InsertFileEntry(FileEntry* head, char* filename)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));
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

void BackupFiles(FileEntry* head)
{
    FILE* backupFile = fopen("backup.txt", "w");
    fprintf(backupFile, "Files:\n");

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next)
    {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main()
{
    FileEntry* head = NULL;

    // Insert some file entries
    InsertFileEntry(head, "my-file.txt");
    InsertFileEntry(head, "another-file.doc");
    InsertFileEntry(head, "third-file.jpg");

    // Backup the files
    BackupFiles(head);

    // Print the backed up files
    FILE* backupFile = fopen("backup.txt", "r");
    char line[MAX_FILE_NAME_LENGTH];
    while (fgets(line, MAX_FILE_NAME_LENGTH, backupFile) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(backupFile);

    return 0;
}