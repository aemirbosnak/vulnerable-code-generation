//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILES 10
#define BUFFER_SIZE 256

typedef struct FileEntry {
    char filename[256];
    struct FileEntry* next;
} FileEntry;

FileEntry* insertFile(FileEntry* head, char* filename) {
    FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
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
    time_t t = time(NULL);
    char timestamp[26] = "";
    strftime(timestamp, 26, "%Y-%m-%d_%H-%M-%S", localtime(&t));

    FILE* backupFile = fopen("backup.txt", "w");
    fprintf(backupFile, "Backup Timestamp: %s\n", timestamp);

    for (FileEntry* current = head; current; current = current->next) {
        fprintf(backupFile, "Filename: %s\n", current->filename);
    }

    fclose(backupFile);
}

int main() {
    FileEntry* head = NULL;

    insertFile(head, "file1.txt");
    insertFile(head, "file2.txt");
    insertFile(head, "file3.txt");

    backupFiles(head);

    return 0;
}