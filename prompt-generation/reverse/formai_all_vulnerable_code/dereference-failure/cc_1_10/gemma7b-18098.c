//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char file_name[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

void insert_file_entry(FileEntry** head, char* file_name) {
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->file_name, file_name);
    new_entry->next = NULL;

    if (*head == NULL) {
        *head = new_entry;
    } else {
        (*head)->next = new_entry;
    }
}

void backup_files(FileEntry* head) {
    FILE* file_ptr;
    char backup_dir[] = "/backup";

    if (head == NULL) {
        return;
    }

    for (FileEntry* current = head; current; current = current->next) {
        file_ptr = fopen(current->file_name, "r");
        if (file_ptr == NULL) {
            printf("Error opening file: %s", current->file_name);
            continue;
        }

        char backup_file_name[MAX_FILE_NAME_LENGTH];
        sprintf(backup_file_name, "%s/%s", backup_dir, current->file_name);

        FILE* backup_file = fopen(backup_file_name, "w");
        if (backup_file == NULL) {
            printf("Error creating backup file: %s", backup_file_name);
            fclose(file_ptr);
            continue;
        }

        int read_bytes;
        while ((read_bytes = fread(backup_file, 1, 1024, file_ptr)) > 0) {
            fwrite(backup_file, 1, read_bytes, file_ptr);
        }

        fclose(file_ptr);
        fclose(backup_file);
    }
}

int main() {
    FileEntry* head = NULL;
    insert_file_entry(&head, "my_file.txt");
    insert_file_entry(&head, "another_file.doc");

    backup_files(head);

    return 0;
}