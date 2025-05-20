//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char name[256];
    struct FileEntry* next;
} FileEntry;

void insertFile(FileEntry** head, char* name) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

void backupFiles(FileEntry* head) {
    FILE* backupFile = fopen("backup.txt", "w");
    fprintf(backupFile, "Files:\n");
    for (FileEntry* current = head; current; current = current->next) {
        fprintf(backupFile, "%s\n", current->name);
    }
    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    // Insert some files
    insertFile(&head, "file1.txt");
    insertFile(&head, "file2.txt");
    insertFile(&head, "file3.txt");

    // Backup the files
    backupFiles(head);

    // Check the backup file
    FILE* backupFile = fopen("backup.txt", "r");
    char line[256];
    while (fgets(line, 256, backupFile) != NULL) {
        printf("%s\n", line);
    }
    fclose(backupFile);

    return 0;
}