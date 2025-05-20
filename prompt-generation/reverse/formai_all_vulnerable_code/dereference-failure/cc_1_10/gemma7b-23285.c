//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 1024

typedef struct FileEntry {
    char filename[256];
    int size;
    struct FileEntry* next;
} FileEntry;

void insertFile(FileEntry** head, char* filename, int size) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        ((*head)->next) = newEntry;
    }
}

void backupFiles(FileEntry* head) {
    FILE* fp;
    char backupDir[256];
    sprintf(backupDir, "/backup/%s", head->filename);
    fp = fopen(backupDir, "w");

    for (head = head->next; head; head = head->next) {
        fprintf(fp, "%s\n", head->filename);
    }

    fclose(fp);
}

int main() {
    FileEntry* head = NULL;

    insertFile(&head, "file1.txt", 1024);
    insertFile(&head, "file2.txt", 2048);
    insertFile(&head, "file3.txt", 3072);

    backupFiles(head);

    return 0;
}