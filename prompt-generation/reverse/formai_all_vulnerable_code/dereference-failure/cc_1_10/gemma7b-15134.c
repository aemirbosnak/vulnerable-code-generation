//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct File {
    char name[MAX_FILE_SIZE];
    int size;
    struct File* next;
} File;

File* file_insert(File* head, char* name, int size) {
    File* new_file = malloc(sizeof(File));
    new_file->size = size;
    strcpy(new_file->name, name);
    new_file->next = NULL;

    if (head == NULL) {
        head = new_file;
    } else {
        File* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_file;
    }

    return head;
}

void file_backup(File* head) {
    FILE* file_ptr = fopen("backup.txt", "w");
    fprintf(file_ptr, "Files:\n");

    for (File* current = head; current; current = current->next) {
        fprintf(file_ptr, "%s (%d bytes)\n", current->name, current->size);
    }

    fclose(file_ptr);
}

int main() {
    File* head = NULL;

    // Insert files
    file_insert(head, "a.txt", 1024);
    file_insert(head, "b.txt", 2048);
    file_insert(head, "c.txt", 3072);

    // Backup files
    file_backup(head);

    return 0;
}