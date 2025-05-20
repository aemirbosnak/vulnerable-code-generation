//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    FILE* file_ptr;
} File;

File* head = NULL;

void create_file(char* name) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->next = head;
    head = new_file;
    new_file->file_ptr = fopen(name, "w");
}

void write_file(char* name, char* data) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            fprintf(file->file_ptr, data);
            break;
        }
        file = file->next;
    }

    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

void read_file(char* name) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            FILE* file_ptr = file->file_ptr;
            char data[1024];
            fscanf(file_ptr, "%s", data);
            printf("%s", data);
            break;
        }
        file = file->next;
    }

    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

void delete_file(char* name) {
    File* file = head;
    File* prev = NULL;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            if (prev) {
                prev->next = file->next;
            } else {
                head = file->next;
            }
            fclose(file->file_ptr);
            free(file);
            break;
        }
        prev = file;
        file = file->next;
    }

    if (file == NULL) {
        printf("Error: File not found.\n");
    }
}

int main() {
    create_file("test.txt");
    write_file("test.txt", "Hello, world!");
    read_file("test.txt");
    delete_file("test.txt");
    read_file("test.txt");

    return 0;
}