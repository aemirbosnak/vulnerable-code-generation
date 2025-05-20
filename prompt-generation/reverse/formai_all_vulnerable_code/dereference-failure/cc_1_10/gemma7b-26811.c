//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry {
    char *filename;
    struct FileEntry *next;
} FileEntry;

void addFileEntry(FileEntry **head, char *filename) {
    FileEntry *newEntry = malloc(sizeof(FileEntry));
    newEntry->filename = strdup(filename);
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

void backupFiles(FileEntry *head) {
    FILE *backupFile = fopen("backup.txt", "w");

    for (FileEntry *currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main() {
    FileEntry *head = NULL;

    // Add some file entries
    addFileEntry(&head, "test.txt");
    addFileEntry(&head, "image.jpg");
    addFileEntry(&head, "document.doc");

    // Backup the files
    backupFiles(head);

    // Print the backup file contents
    FILE *backupFile = fopen("backup.txt", "r");
    char buffer[MAX_BUFFER_SIZE];

    while (fgets(buffer, MAX_BUFFER_SIZE, backupFile) != NULL) {
        printf("%s\n", buffer);
    }

    fclose(backupFile);

    return 0;
}