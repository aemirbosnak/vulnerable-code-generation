//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[256];
    struct FileEntry* next;
} FileEntry;

FileEntry* head = NULL;

void addFile(char* filename) {
    FileEntry* newEntry = malloc(sizeof(FileEntry));
    strcpy(newEntry->filename, filename);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
        head = newEntry;
    }
}

void backupFiles() {
    FILE* backupFile = fopen("backup.txt", "w");

    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        fprintf(backupFile, "%s\n", currentEntry->filename);
    }

    fclose(backupFile);
}

int main() {
    // Add some files
    addFile("file1.txt");
    addFile("file2.pdf");
    addFile("file3.jpg");

    // Backup the files
    backupFiles();

    // Print the backup file
    FILE* backupFile = fopen("backup.txt", "r");
    char line[256];
    while (fgets(line, 256, backupFile) != NULL) {
        printf("%s\n", line);
    }
    fclose(backupFile);

    return 0;
}