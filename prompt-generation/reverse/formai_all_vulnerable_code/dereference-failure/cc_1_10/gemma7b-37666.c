//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct FileEntry {
    char *name;
    struct FileEntry *next;
} FileEntry;

void backup_file(FILE *file, FileEntry **head) {
    int file_size = 0;
    char *buffer = NULL;

    // Calculate file size
    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);

    // Allocate memory for buffer
    buffer = malloc(file_size);

    // Read file data
    rewind(file);
    fread(buffer, file_size, 1, file);

    // Create new file entry
    FileEntry *new_entry = malloc(sizeof(FileEntry));
    new_entry->name = strdup(buffer);
    new_entry->next = NULL;

    // Add new entry to head
    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }

    // Free memory
    free(buffer);
    free(new_entry);
}

int main() {
    FileEntry *head = NULL;

    // Backup a file
    FILE *file = fopen("my_file.txt", "r");
    backup_file(file, &head);
    fclose(file);

    // Print file list
    FileEntry *current = head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }

    return 0;
}