//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    int size;
    FILE* file_ptr;
} File;

File* head = NULL;

void create_file(char* name, int size) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->next = NULL;
    new_file->size = size;
    new_file->file_ptr = fopen(name, "w");
    if (head == NULL) {
        head = new_file;
    } else {
        head->next = new_file;
        head = new_file;
    }
}

void list_files() {
    File* current = head;
    while (current) {
        printf("%s (size: %d)\n", current->name, current->size);
        current = current->next;
    }
}

void delete_file(char* name) {
    File* previous = NULL;
    File* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            fclose(current->file_ptr);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("File not found.\n");
}

int main() {
    create_file("test.txt", 10);
    create_file("another.txt", 20);
    list_files();
    delete_file("test.txt");
    list_files();
    return 0;
}