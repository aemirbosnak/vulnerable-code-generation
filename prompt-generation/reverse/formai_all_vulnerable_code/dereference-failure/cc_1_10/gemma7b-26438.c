//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <math.h>

// Define the file backup system (FBS) structure
typedef struct FBS {
    char filename[256];
    int size;
    struct FBS *next;
} FBS;

// Function to insert a file into the FBS
void insert_file(FBS **head, char *filename, int size) {
    FBS *new_node = malloc(sizeof(FBS));
    strcpy(new_node->filename, filename);
    new_node->size = size;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a file in the FBS
FBS *search_file(FBS *head, char *filename) {
    while (head) {
        if (strcmp(head->filename, filename) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to backup a file
void backup_file(FBS **head, char *filename, int size) {
    insert_file(head, filename, size);
}

// Function to restore a file
void restore_file(FBS *head, char *filename) {
    FBS *file = search_file(head, filename);
    if (file) {
        printf("File: %s, Size: %d\n", file->filename, file->size);
    } else {
        printf("File not found: %s\n", filename);
    }
}

int main() {
    FBS *head = NULL;

    backup_file(&head, "my_file.txt", 1024);
    backup_file(&head, "another_file.doc", 2048);

    restore_file(head, "my_file.txt");
    restore_file(head, "another_file.doc");

    return 0;
}