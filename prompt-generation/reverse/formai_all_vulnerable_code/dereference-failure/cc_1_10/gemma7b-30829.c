//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_NUMBER_OF_FILES 1000

typedef struct FileRecord {
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileRecord* next;
} FileRecord;

FileRecord* CreateFileRecord(char* filename) {
    FileRecord* newRecord = malloc(sizeof(FileRecord));
    strcpy(newRecord->filename, filename);
    newRecord->next = NULL;
    return newRecord;
}

void AppendFileRecord(FileRecord* head, char* filename) {
    FileRecord* newRecord = CreateFileRecord(filename);
    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }
}

int SearchFileRecord(FileRecord* head, char* filename) {
    while (head) {
        if (strcmp(head->filename, filename) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    FileRecord* fileRecords = NULL;
    AppendFileRecord(fileRecords, "test.txt");
    AppendFileRecord(fileRecords, "myphoto.jpg");
    AppendFileRecord(fileRecords, "documents.doc");

    if (SearchFileRecord(fileRecords, "test.txt") == 1) {
        printf("File found: test.txt\n");
    }

    return 0;
}