//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileInfo {
    char filename[256];
    int size;
    struct FileInfo* next;
} FileInfo;

void insertFile(FileInfo** head, char* filename, int size) {
    FileInfo* newNode = malloc(sizeof(FileInfo));
    strcpy(newNode->filename, filename);
    newNode->size = size;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void backupFiles(FileInfo* head) {
    FILE* filePtr;
    char backupDir[256];
    strcpy(backupDir, "/home/backup");

    while (head) {
        filePtr = fopen(head->filename, "r");
        if (filePtr) {
            int fileSize = head->size;
            char* buffer = malloc(fileSize);

            fread(buffer, fileSize, 1, filePtr);

            fclose(filePtr);

            FILE* backupFile = fopen(backupDir, "a");
            fprintf(backupFile, "%s\n", buffer);

            free(buffer);
            free(backupFile);
        }
        head = head->next;
    }
}

int main() {
    FileInfo* head = NULL;

    insertFile(&head, "file1.txt", 100);
    insertFile(&head, "file2.pdf", 200);
    insertFile(&head, "file3.doc", 300);

    backupFiles(head);

    return 0;
}