//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_entry {
    char* name;
    int size;
} file_entry_t;

typedef struct file_entry_list {
    file_entry_t* entry;
    struct file_entry_list* next;
} file_entry_list_t;

int main() {
    file_entry_list_t* head = NULL;
    file_entry_list_t* curr = NULL;
    file_entry_list_t* new_file_entry = NULL;

    char* file_name = "file1.txt";
    char* file_name_new = "file2.txt";
    int file_size = 1024;

    file_entry_t* new_file_entry_1 = (file_entry_t*)malloc(sizeof(file_entry_t));
    new_file_entry_1->name = (char*)malloc(sizeof(char)*(strlen(file_name) + 1));
    strcpy(new_file_entry_1->name, file_name);
    new_file_entry_1->size = file_size;

    file_entry_t* new_file_entry_2 = (file_entry_t*)malloc(sizeof(file_entry_t));
    new_file_entry_2->name = (char*)malloc(sizeof(char)*(strlen(file_name_new) + 1));
    strcpy(new_file_entry_2->name, file_name_new);
    new_file_entry_2->size = file_size;

    new_file_entry->entry = new_file_entry_1;
    new_file_entry->next = NULL;

    curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->entry->name, file_name) == 0) {
            printf("File %s already exists in the list\n", file_name);
            return 0;
        }
        curr = curr->next;
    }

    curr->next = new_file_entry;
    new_file_entry->next = NULL;
    new_file_entry = NULL;

    printf("File %s added to the list\n", file_name);

    curr = head;
    while (curr!= NULL) {
        printf("Name: %s, Size: %d\n", curr->entry->name, curr->entry->size);
        curr = curr->next;
    }

    return 0;
}