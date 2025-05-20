//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_FILES 10

struct file_backup_record {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    int file_size;
    struct file_backup_record* next;
};

void insert_file_backup_record(struct file_backup_record** head, char* file_name, int file_size) {
    struct file_backup_record* new_record = malloc(sizeof(struct file_backup_record));
    strcpy(new_record->file_name, file_name);
    new_record->timestamp = time(NULL);
    new_record->file_size = file_size;
    new_record->next = NULL;

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void print_file_backup_records(struct file_backup_record* head) {
    struct file_backup_record* current = head;
    while (current) {
        printf("File name: %s\n", current->file_name);
        printf("Timestamp: %ld\n", current->timestamp);
        printf("File size: %d\n", current->file_size);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct file_backup_record* head = NULL;

    insert_file_backup_record(&head, "test.txt", 100);
    insert_file_backup_record(&head, "image.jpg", 500);
    insert_file_backup_record(&head, "document.doc", 200);

    print_file_backup_records(head);

    return 0;
}