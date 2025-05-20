//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileRecord {
    char name[256];
    char data[10000];
    struct FileRecord* next;
} FileRecord;

FileRecord* insertFile(FileRecord* head, char* name, char* data) {
    FileRecord* newRecord = (FileRecord*)malloc(sizeof(FileRecord));
    strcpy(newRecord->name, name);
    strcpy(newRecord->data, data);
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

void backupFiles(FileRecord* head) {
    FILE* filePtr;
    FileRecord* currentRecord = head;

    while (currentRecord) {
        filePtr = fopen(currentRecord->name, "w");
        fprintf(filePtr, "%s", currentRecord->data);
        fclose(filePtr);

        currentRecord = currentRecord->next;
    }
}

int main() {
    FileRecord* head = NULL;

    // Insert some files
    insertFile(head, "file1.txt", "This is file 1.");
    insertFile(head, "file2.txt", "This is file 2.");
    insertFile(head, "file3.txt", "This is file 3.");

    // Backup the files
    backupFiles(head);

    return 0;
}