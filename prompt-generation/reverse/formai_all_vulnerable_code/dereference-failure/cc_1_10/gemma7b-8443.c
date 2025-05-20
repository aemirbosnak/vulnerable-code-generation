//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BUFFER_SIZE 2048

typedef struct FileRecord {
    char name[256];
    int size;
    struct FileRecord* next;
} FileRecord;

FileRecord* insertFileRecord(FileRecord* head, char* name, int size) {
    FileRecord* newRecord = malloc(sizeof(FileRecord));
    strcpy(newRecord->name, name);
    newRecord->size = size;
    newRecord->next = NULL;

    if (head == NULL) {
        return newRecord;
    }

    head->next = insertFileRecord(head->next, name, size);
    return head;
}

void backupFiles(FileRecord* head) {
    FILE* filePointer;
    char buffer[MAX_BUFFER_SIZE];
    int i;

    for (head = head; head; head = head->next) {
        filePointer = fopen(head->name, "rb");
        i = fread(buffer, 1, head->size, filePointer);
        fclose(filePointer);

        printf("Backing up file: %s\n", head->name);
        printf("Size: %d bytes\n", head->size);
        printf("Data: %s\n", buffer);
    }
}

int main() {
    FileRecord* head = NULL;

    insertFileRecord(head, "file1.txt", 1024);
    insertFileRecord(head, "file2.txt", 2048);
    insertFileRecord(head, "file3.txt", 3072);

    backupFiles(head);

    return 0;
}