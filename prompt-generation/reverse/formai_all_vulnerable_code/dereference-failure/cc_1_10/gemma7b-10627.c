//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 256

typedef struct FileEntry {
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

typedef struct FileSystem {
    FileEntry* head;
    int numFiles;
} FileSystem;

FileSystem* CreateFileSystem() {
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->head = NULL;
    fs->numFiles = 0;
    return fs;
}

void AddFile(FileSystem* fs, char* filename, int size) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (fs->head == NULL) {
        fs->head = newEntry;
    } else {
        fs->head->next = newEntry;
    }

    fs->numFiles++;
}

void BackupFiles(FileSystem* fs) {
    FILE* backupFile = fopen("backup.dat", "w");
    fprintf(backupFile, "Number of files: %d\n", fs->numFiles);

    for (FileEntry* entry = fs->head; entry; entry = entry->next) {
        fprintf(backupFile, "Filename: %s\n", entry->filename);
        fprintf(backupFile, "Size: %d\n", entry->size);
        fprintf(backupFile, "\n");
    }

    fclose(backupFile);
}

int main() {
    FileSystem* fs = CreateFileSystem();

    AddFile(fs, "test.txt", 10);
    AddFile(fs, "image.jpg", 1024);
    AddFile(fs, "document.doc", 2048);

    BackupFiles(fs);

    return 0;
}