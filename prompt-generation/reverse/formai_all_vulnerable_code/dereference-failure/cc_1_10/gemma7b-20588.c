//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

typedef struct FileEntry {
    char name[256];
    int size;
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* name, int size) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->name, name);
    newEntry->size = size;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void synchronize(FileEntry* head) {
    FILE* filePtr;
    char buffer[BUFFER_SIZE];
    int readSize;
    struct stat statBuf;

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        stat(currentEntry->name, &statBuf);
        currentEntry->size = statBuf.st_size;

        filePtr = fopen(currentEntry->name, "r");
        readSize = fread(buffer, 1, BUFFER_SIZE, filePtr);
        fclose(filePtr);

        currentEntry->size = readSize;
    }
}

int main() {
    FileEntry* head = NULL;

    insertFile(head, "test.txt", 10);
    insertFile(head, "hello.txt", 20);

    synchronize(head);

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        printf("%s size: %d\n", currentEntry->name, currentEntry->size);
    }

    return 0;
}