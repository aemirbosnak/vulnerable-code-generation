//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 // 10MB

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
    char backupDir[] = "backup";
    mkdir(backupDir, 0755);

    while (head) {
        fp = fopen(head->filename, "rb");
        if (fp) {
            int fileSize = head->size;
            char *buffer = malloc(fileSize);
            fread(buffer, fileSize, 1, fp);
            fclose(fp);

            char backupFilename[256];
            sprintf(backupFilename, "%s/%s", backupDir, head->filename);
            fp = fopen(backupFilename, "wb");
            fwrite(buffer, fileSize, 1, fp);
            fclose(fp);

            free(buffer);
        }
        head = head->next;
    }
}

int main() {
    FileEntry *head = NULL;
    insertFileEntry(&head, "file1.txt", 1024);
    insertFileEntry(&head, "file2.txt", 2048);
    insertFileEntry(&head, "file3.txt", 3072);

    backupFiles(head);

    return 0;
}