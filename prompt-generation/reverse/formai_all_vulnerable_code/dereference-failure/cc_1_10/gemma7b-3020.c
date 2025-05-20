//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct file_entry {
    char filename[256];
    int size;
    struct file_entry* next;
} file_entry;

file_entry* add_file(file_entry* head, char* filename, int size) {
    file_entry* new_entry = malloc(sizeof(file_entry));
    strcpy(new_entry->filename, filename);
    new_entry->size = size;
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        head->next = new_entry;
    }

    return head;
}

void backup(file_entry* head) {
    FILE* backup_file = fopen("backup.dat", "w");

    fprintf(backup_file, "Number of files: %d\n", head->size);

    for (file_entry* current = head; current; current = current->next) {
        fprintf(backup_file, "Filename: %s\n", current->filename);
        fprintf(backup_file, "Size: %d\n", current->size);
    }

    fclose(backup_file);
}

int main() {
    file_entry* head = NULL;

    // Add some files to the list
    add_file(head, "file1.txt", 1024);
    add_file(head, "file2.txt", 2048);
    add_file(head, "file3.txt", 3072);

    // Backup the files
    backup(head);

    // Print the backup file contents
    FILE* backup_file = fopen("backup.dat", "r");

    fprintf(stdout, "Number of files: %d\n", fscanf(backup_file, "Number of files: %d\n"));

    for (int i = 0; i < fscanf(backup_file, "Number of files: %d\n"); i++) {
        fprintf(stdout, "Filename: %s\n", fscanf(backup_file, "Filename: %s\n"));
        fprintf(stdout, "Size: %d\n", fscanf(backup_file, "Size: %d\n"));
    }

    fclose(backup_file);

    return 0;
}