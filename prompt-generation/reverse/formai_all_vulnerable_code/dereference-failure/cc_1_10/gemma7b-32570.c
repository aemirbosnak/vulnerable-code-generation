//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_DIRECTORY_NAME_LENGTH 255
#define MAX_NUMBER_OF_FILES 1000

typedef struct FileEntry
{
    char filename[MAX_FILE_NAME_LENGTH];
    char directory[MAX_DIRECTORY_NAME_LENGTH];
    time_t timestamp;
    struct FileEntry* next;
} FileEntry;

typedef struct FileSystem
{
    FileEntry* head;
    int numberOfFiles;
} FileSystem;

FileSystem* createFileSystem()
{
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->head = NULL;
    fs->numberOfFiles = 0;
    return fs;
}

void addFile(FileSystem* fs, char* filename, char* directory)
{
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    strcpy(newEntry->directory, directory);
    newEntry->timestamp = time(NULL);
    newEntry->next = NULL;

    if (fs->head == NULL)
    {
        fs->head = newEntry;
    }
    else
    {
        fs->head->next = newEntry;
    }

    fs->numberOfFiles++;
}

void listFiles(FileSystem* fs)
{
    FileEntry* currentEntry = fs->head;
    while (currentEntry)
    {
        printf("%s (%s) - %s\n", currentEntry->filename, currentEntry->directory, ctime(currentEntry->timestamp));
        currentEntry = currentEntry->next;
    }
}

int main()
{
    FileSystem* fs = createFileSystem();

    // Add some files
    addFile(fs, "myphoto.jpg", "Pictures");
    addFile(fs, "mydocument.doc", "Documents");
    addFile(fs, "mymusic.mp3", "Music");

    // List all files
    listFiles(fs);

    return 0;
}