//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 10

typedef struct FileEntry {
    char filename[255];
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* filename) {
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
    FILE* filePtr;
    char backupDir[255];
    sprintf(backupDir, "/home/backup/%s", head->filename);
    filePtr = fopen(backupDir, "w");

    fprintf(filePtr, "Backup of file: %s\n", head->filename);
    fprintf(filePtr, "--------------------\n");

    // Copy file contents to backup file
    FILE* fileSrc = fopen(head->filename, "r");
    char buffer[1024];
    while (fgets(buffer, 1024, fileSrc) != NULL) {
        fprintf(filePtr, "%s", buffer);
    }

    fclose(filePtr);
    fclose(fileSrc);
}

int main() {
    FileEntry* head = NULL;

    // Insert some files into the list
    insertFile(head, "file1.txt");
    insertFile(head, "file2.txt");
    insertFile(head, "file3.txt");

    // Backup the files
    backupFiles(head);

    return 0;
}