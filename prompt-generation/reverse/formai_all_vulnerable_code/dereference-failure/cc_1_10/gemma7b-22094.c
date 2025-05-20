//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct FileEntry {
    char *filename;
    int size;
    struct FileEntry *next;
} FileEntry;

void insertFileEntry(FileEntry **head, char *filename, int size) {
    FileEntry *newEntry = malloc(sizeof(FileEntry));
    newEntry->filename = strdup(filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

void backupFiles(FileEntry *head) {
    FILE *fp;
    FileEntry *current = head;

    while (current) {
        fp = fopen(current->filename, "rb");
        if (fp) {
            int fileSize = current->size;
            char *buffer = malloc(fileSize);
            fread(buffer, fileSize, 1, fp);
            fclose(fp);

            printf("Backing up file: %s\n", current->filename);
            printf("File size: %d bytes\n", fileSize);
            printf("Data: \n");
            printf("%s\n", buffer);
            printf("\n");
        }
        current = current->next;
    }
}

int main() {
    FileEntry *head = NULL;

    insertFileEntry(&head, "file1.txt", 100);
    insertFileEntry(&head, "file2.txt", 200);
    insertFileEntry(&head, "file3.txt", 300);

    backupFiles(head);

    return 0;
}