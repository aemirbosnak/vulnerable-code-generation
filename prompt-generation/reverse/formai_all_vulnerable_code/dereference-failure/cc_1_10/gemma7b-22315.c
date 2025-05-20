//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

typedef struct FileSystem {
    FileEntry* head;
} FileSystem;

FileSystem* createFileSystem() {
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->head = NULL;
    return fs;
}

void addFileEntry(FileSystem* fs, char* filename) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (fs->head == NULL) {
        fs->head = newEntry;
    } else {
        FileEntry* currentEntry = fs->head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

int main() {
    FileSystem* fs = createFileSystem();

    // Add some file entries
    addFileEntry(fs, "file1.txt");
    addFileEntry(fs, "file2.doc");
    addFileEntry(fs, "file3.jpg");

    // Print the file entries
    FileEntry* currentEntry = fs->head;
    while (currentEntry) {
        printf("%s\n", currentEntry->filename);
        currentEntry = currentEntry->next;
    }

    return 0;
}