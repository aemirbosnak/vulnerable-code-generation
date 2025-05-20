//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file system entry
typedef struct FileEntry {
    char name[256];
    struct FileEntry* next;
    int isDirectory;
    char data[1024];
} FileEntry;

// Define a function to create a new file system entry
FileEntry* createEntry(char* name, int isDirectory) {
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;
    newEntry->isDirectory = isDirectory;
    return newEntry;
}

// Define a function to list all files in a directory
void listDirectory(FileEntry* directory) {
    FILE* file = fopen("files.txt", "w");
    fprintf(file, "Files in %s:\n", directory->name);
    for (FileEntry* entry = directory->next; entry; entry = entry->next) {
        fprintf(file, "%s\n", entry->name);
    }
    fclose(file);
}

// Define a function to add a file to a directory
void addFile(FileEntry* directory, char* name, int isDirectory) {
    FileEntry* newEntry = createEntry(name, isDirectory);
    if (directory->next == NULL) {
        directory->next = newEntry;
    } else {
        for (FileEntry* entry = directory->next; entry->next; entry = entry->next) {
            if (strcmp(entry->name, name) == 0) {
                printf("Error: File already exists.\n");
                return;
            }
        }
        directory->next->next = newEntry;
    }
}

// Define a function to remove a file from a directory
void removeFile(FileEntry* directory, char* name) {
    for (FileEntry* entry = directory->next; entry; entry = entry->next) {
        if (strcmp(entry->name, name) == 0) {
            FileEntry* previousEntry = NULL;
            for (FileEntry* previous = directory->next; previous && previous->next != entry; previous = previous->next) {
                previousEntry = previous;
            }
            if (previousEntry) {
                previousEntry->next = entry->next;
            } else {
                directory->next = entry->next;
            }
            free(entry);
            return;
        }
    }
    printf("Error: File does not exist.\n");
}

int main() {
    FileEntry* root = createEntry("Root", 1);
    FILE* file = fopen("files.txt", "w");
    fprintf(file, "Welcome to the File System!\n");
    fclose(file);

    // Add some files to the root directory
    addFile(root, "text.txt", 0);
    addFile(root, "image.jpg", 0);
    addFile(root, "directory", 1);

    // List all files in the root directory
    listDirectory(root);

    // Remove a file from the root directory
    removeFile(root, "text.txt");

    // List all files in the root directory after removal
    listDirectory(root);

    return 0;
}