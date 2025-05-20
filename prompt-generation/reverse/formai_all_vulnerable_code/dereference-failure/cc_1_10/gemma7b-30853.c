//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 4096

typedef struct FileEntry {
    char *filename;
    int size;
    struct FileEntry *next;
} FileEntry;

void insert_file(FileEntry **head, char *filename, int size) {
    FileEntry *new_entry = malloc(sizeof(FileEntry));
    new_entry->filename = strdup(filename);
    new_entry->size = size;
    new_entry->next = NULL;

    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }
}

void backup_files(FileEntry *head) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];

    for (FileEntry *current = head; current; current = current->next) {
        fp = fopen(current->filename, "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

        size_t bytes_read = read(fileno(fp), buffer, MAX_BUFFER_SIZE);
        fwrite(buffer, bytes_read, 1, stdout);

        fclose(fp);
    }
}

int main() {
    FileEntry *head = NULL;

    insert_file(&head, "file1.txt", 10);
    insert_file(&head, "file2.txt", 20);
    insert_file(&head, "file3.txt", 30);

    backup_files(head);

    return 0;
}