//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

struct file_sync {
    char filename[256];
    int last_write_time;
    int file_size;
    FILE *fp;
    struct file_sync *next;
};

void file_sync_init(struct file_sync **head) {
    *head = NULL;
}

void file_sync_add(struct file_sync **head, char *filename, int last_write_time, int file_size) {
    struct file_sync *new_file_sync = malloc(sizeof(struct file_sync));
    strcpy(new_file_sync->filename, filename);
    new_file_sync->last_write_time = last_write_time;
    new_file_sync->file_size = file_size;
    new_file_sync->fp = NULL;
    new_file_sync->next = NULL;

    if (*head == NULL) {
        *head = new_file_sync;
    } else {
        (*head)->next = new_file_sync;
    }
}

int main() {
    struct file_sync *head = NULL;
    file_sync_init(&head);

    file_sync_add(&head, "file1.txt", 123456, 100);
    file_sync_add(&head, "file2.txt", 654321, 200);
    file_sync_add(&head, "file3.txt", 246801, 300);

    struct file_sync *current = head;
    while (current) {
        printf("Filename: %s\n", current->filename);
        printf("Last Write Time: %d\n", current->last_write_time);
        printf("File Size: %d\n", current->file_size);
        printf("\n");
        current = current->next;
    }

    return 0;
}