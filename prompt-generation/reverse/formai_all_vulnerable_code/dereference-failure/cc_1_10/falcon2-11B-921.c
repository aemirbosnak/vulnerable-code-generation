//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100

typedef struct file_entry {
    char filename[MAX_FILE_NAME];
    struct file_entry *next;
} file_entry_t;

file_entry_t *head = NULL;

void add_file(char *filename) {
    file_entry_t *new_file = (file_entry_t*)malloc(sizeof(file_entry_t));
    strcpy(new_file->filename, filename);
    new_file->next = NULL;
    if (head == NULL) {
        head = new_file;
    } else {
        file_entry_t *cur = head;
        while (cur->next!= NULL) {
            cur = cur->next;
        }
        cur->next = new_file;
    }
}

void delete_file(char *filename) {
    file_entry_t *cur = head;
    while (cur!= NULL) {
        if (strcmp(cur->filename, filename) == 0) {
            if (cur == head) {
                head = cur->next;
                free(cur);
                return;
            }
            file_entry_t *tmp = cur->next;
            free(cur);
            cur = tmp;
        } else {
            cur = cur->next;
        }
    }
}

void list_files() {
    file_entry_t *cur = head;
    while (cur!= NULL) {
        printf("%s\n", cur->filename);
        cur = cur->next;
    }
}

int main() {
    add_file("file1.txt");
    add_file("file2.txt");
    add_file("file3.txt");

    list_files();

    delete_file("file2.txt");

    list_files();

    return 0;
}