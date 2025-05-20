//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    struct FileEntry* next;
} FileEntry;

void insert_file(FileEntry** head, char* file_name, int file_size) {
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->file_name, file_name);
    new_entry->file_size = file_size;
    new_entry->next = NULL;

    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }
}

int search_file(FileEntry* head, char* file_name) {
    while (head) {
        if (strcmp(head->file_name, file_name) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    FileEntry* file_head = NULL;

    insert_file(&file_head, "my_file.txt", 100);
    insert_file(&file_head, "another_file.doc", 200);

    if (search_file(file_head, "my_file.txt") == 1) {
        printf("File found!\n");
    } else {
        printf("File not found.\n");
    }

    return 0;
}