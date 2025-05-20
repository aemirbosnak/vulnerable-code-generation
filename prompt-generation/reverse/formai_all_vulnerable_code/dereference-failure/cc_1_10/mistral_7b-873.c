//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 25
#define MAX_CONTENT_LENGTH 1000

typedef struct file_t {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    int size;
    bool is_hidden;
    struct file_t *next;
} file_t;

file_t *root = NULL;
file_t *current = NULL;

void create_file(char *name, char *content, bool is_hidden) {
    file_t *new_file = (file_t *) malloc(sizeof(file_t));
    strcpy(new_file->name, name);
    int len = strlen(content);
    strncpy(new_file->content, content, len + 1);
    new_file->size = len + 1;
    new_file->is_hidden = is_hidden;
    new_file->next = NULL;

    if (root == NULL) {
        root = new_file;
        current = root;
    } else {
        current->next = new_file;
        current = new_file;
    }
}

void change_directory() {
    if (current == NULL || current == root) {
        printf("Error: Cannot go up from root directory!\n");
        return;
    }
    current = current->next;
}

void list_files() {
    file_t *temp = root;
    printf("Files in current directory:\n");
    while (temp != NULL) {
        printf("%s%s\n", temp->name, temp->is_hidden ? " (hidden)" : "");
        temp = temp->next;
    }
}

void open_file(char *name) {
    file_t *temp = root;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Opening file: %s\nContent:\n%s\n", name, temp->content);
            return;
        }
        temp = temp->next;
    }
    printf("Error: File not found!\n");
}

int main() {
    printf("\n***** Welcome to the Super Duper File System Simulator *****\n");

    create_file("example.txt", "Hello World!", false);
    create_file("hidden.txt", "Secret stuff!", true);

    list_files();
    printf("\nCurrent directory: %s\n", current->name);

    change_directory();
    list_files();
    printf("\nCurrent directory: %s\n", current->name);

    open_file("example.txt");

    return 0;
}