//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct FileNode {
    char name[256];
    struct FileNode* next;
    FILE* file;
} FileNode;

FileNode* file_system = NULL;

void add_file(char* name) {
    FileNode* new_node = (FileNode*)malloc(sizeof(FileNode));
    strcpy(new_node->name, name);
    new_node->next = file_system;
    file_system = new_node;
    new_node->file = fopen(name, "w");
}

void rm_file(char* name) {
    FileNode* previous = NULL;
    FileNode* current = file_system;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                file_system = current->next;
            }
            fclose(current->file);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: File not found.\n");
}

void list_files() {
    FileNode* current = file_system;

    printf("Files:\n");
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    add_file("my_file.txt");
    add_file("another_file.txt");
    rm_file("my_file.txt");
    list_files();

    return 0;
}