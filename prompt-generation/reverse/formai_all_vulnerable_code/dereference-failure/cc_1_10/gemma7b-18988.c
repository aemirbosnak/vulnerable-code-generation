//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFileEntry(FileEntry* head, char* filename) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void backupFiles(FileEntry* head) {
    FILE* backupFile = fopen("backup.txt", "w");
    fprintf(backupFile, "Backup of files:\n");

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    // Insert some file entries
    insertFileEntry(head, "a.txt");
    insertFileEntry(head, "b.txt");
    insertFileEntry(head, "c.txt");

    // Backup the files
    backupFiles(head);

    // Print the backup file
    FILE* backupFile = fopen("backup.txt", "r");
    char line[MAX_FILE_NAME_LENGTH];
    while (fgets(line, MAX_FILE_NAME_LENGTH, backupFile) != NULL) {
        printf("%s\n", line);
    }
    fclose(backupFile);

    return 0;
}