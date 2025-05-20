//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry
{
    char name[256];
    struct FileEntry* next;
} FileEntry;

FileEntry* file_head = NULL;

void add_file(char* filename)
{
    FileEntry* new_file = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(new_file->name, filename);
    new_file->next = NULL;

    if (file_head == NULL)
    {
        file_head = new_file;
    }
    else
    {
        file_head->next = new_file;
        file_head = new_file;
    }
}

void backup_files()
{
    FILE* backup_file = fopen("backup.txt", "w");
    FileEntry* current_file = file_head;

    fprintf(backup_file, "Backup file for %s\n", "Date: " __DATE__);
    fprintf(backup_file, "---------------------------\n");

    while (current_file)
    {
        fprintf(backup_file, "File name: %s\n", current_file->name);
        fprintf(backup_file, "---------------------------\n");
        current_file = current_file->next;
    }

    fclose(backup_file);
}

int main()
{
    add_file("file1.txt");
    add_file("file2.txt");
    add_file("file3.txt");

    backup_files();

    return 0;
}