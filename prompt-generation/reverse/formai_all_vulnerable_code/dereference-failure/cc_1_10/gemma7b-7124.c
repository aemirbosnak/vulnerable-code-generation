//Gemma-7B DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry {
    char *filename;
    int size;
    struct FileEntry *next;
} FileEntry;

FileEntry *readFileEntries(char *directory);

void writeEntries(FileEntry *entries, char *newFilename, int newSize);

int main() {
    char directory[] = "/home/user/mydirectory";
    FileEntry *entries = readFileEntries(directory);

    writeEntries(entries, "new.txt", 12);

    free(entries);

    return 0;
}

FileEntry *readFileEntries(char *directory) {
    FILE *directoryFile = fopen(directory, "r");
    char line[MAX_FILE_SIZE];
    FileEntry *entries = NULL;

    if (directoryFile) {
        while (fgets(line, MAX_FILE_SIZE, directoryFile) != NULL) {
            char *filename = strchr(line, '/') + 1;
            int size = atoi(strchr(line, ' ') + 1);

            FileEntry *entry = malloc(sizeof(FileEntry));
            entry->filename = strdup(filename);
            entry->size = size;
            entry->next = entries;
            entries = entry;
        }
        fclose(directoryFile);
    }

    return entries;
}

void writeEntries(FileEntry *entries, char *newFilename, int newSize) {
    FileEntry *entry = entries;

    while (entry) {
        if (strcmp(entry->filename, newFilename) == 0) {
            entry->size = newSize;
            return;
        }
        entry = entry->next;
    }

    entry = malloc(sizeof(FileEntry));
    entry->filename = strdup(newFilename);
    entry->size = newSize;
    entry->next = entries;
    entries = entry;
}