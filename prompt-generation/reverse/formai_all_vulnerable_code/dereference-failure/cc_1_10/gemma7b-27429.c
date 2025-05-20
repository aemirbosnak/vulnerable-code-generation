//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[255];
    struct FileEntry* next;
} FileEntry;

FileEntry* addFile(FileEntry* head, char* filename) {
    FileEntry* newEntry = malloc(sizeof(struct FileEntry));
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

    // Add some files to the backup system
    head = addFile(head, "file1.txt");
    head = addFile(head, "file2.txt");
    head = addFile(head, "file3.txt");

    // Backup the files
    backupFiles(head);

    // Print the backup file
    FILE* backupFile = fopen("backup.txt", "r");
    char line[255];
    while (fgets(line, 255, backupFile) != NULL) {
        printf("%s\n", line);
    }
    fclose(backupFile);

    return 0;
}