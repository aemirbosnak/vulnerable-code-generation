//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct File {
    char name[256];
    int size;
    struct File* next;
} File;

File* file_system = NULL;

void create_file(char* name, int size) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = file_system;
    file_system = new_file;
}

void list_files() {
    File* current_file = file_system;
    while (current_file) {
        printf("%s (size: %d)\n", current_file->name, current_file->size);
        current_file = current_file->next;
    }
}

void delete_file(char* name) {
    File* previous_file = NULL;
    File* current_file = file_system;
    while (current_file) {
        if (strcmp(current_file->name, name) == 0) {
            if (previous_file) {
                previous_file->next = current_file->next;
            } else {
                file_system = current_file->next;
            }
            free(current_file);
            return;
        }
        previous_file = current_file;
        current_file = current_file->next;
    }
    printf("File not found: %s\n", name);
}

int main() {
    create_file("test.txt", 1024);
    create_file("image.jpg", 512);
    list_files();
    delete_file("test.txt");
    list_files();
    return 0;
}