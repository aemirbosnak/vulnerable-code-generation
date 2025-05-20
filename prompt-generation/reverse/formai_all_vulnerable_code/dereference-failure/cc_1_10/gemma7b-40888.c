//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define BUFFER_SIZE 256

typedef struct File {
    char *name;
    struct File *next;
    long int size;
    time_t last_accessed;
} File;

File *createFile(char *name, int size) {
    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->next = NULL;
    file->size = size;
    file->last_accessed = time(NULL);
    return file;
}

void listFiles(File *head) {
    File *curr = head;
    while (curr) {
        printf("%s (size: %ld, last accessed: %s)\n", curr->name, curr->size, ctime(curr->last_accessed));
        curr = curr->next;
    }
}

void searchFiles(File *head, char *query) {
    File *curr = head;
    while (curr) {
        if (strstr(curr->name, query) || strstr(curr->name, query)) {
            printf("%s (size: %ld, last accessed: %s)\n", curr->name, curr->size, ctime(curr->last_accessed));
        }
        curr = curr->next;
    }
}

int main() {
    File *files = NULL;

    // Create some files
    files = createFile("file1.txt", 10);
    files = createFile("file2.txt", 20);
    files = createFile("file3.txt", 30);

    // List all files
    listFiles(files);

    // Search for files
    searchFiles(files, "file2");

    return 0;
}