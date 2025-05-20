//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: innovative
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
    FileInfo* newNode = (FileInfo*)malloc(sizeof(FileInfo));
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
    FILE* file;
    char backupPath[256];

    printf("Backing up files...\n");

    while (head) {
        sprintf(backupPath, "/home/user/backup/%s", head->filename);
        file = fopen(backupPath, "w");
        fwrite(head->filename, 1, head->size, file);
        fclose(file);

        printf("%s backed up.\n", head->filename);

        head = head->next;
    }

    printf("Backup complete.\n");
}

int main() {
    FileInfo* head = NULL;

    insertFile(&head, "file1.txt", 1024);
    insertFile(&head, "file2.pdf", 2048);
    insertFile(&head, "file3.doc", 512);

    backupFiles(head);

    return 0;
}