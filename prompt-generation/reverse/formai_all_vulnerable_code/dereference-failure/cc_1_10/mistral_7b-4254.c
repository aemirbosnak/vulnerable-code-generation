//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LEN 20
#define MAX_CONTENT_LEN 100

typedef struct File {
    char name[MAX_NAME_LEN];
    char content[MAX_CONTENT_LEN];
    int size;
    struct File *next;
} File;

File *file_system = NULL;

void create_file(char *name, char *content) {
    File *new_file = (File *) malloc(sizeof(File));
    strcpy(new_file->name, name);
    strcpy(new_file->content, content);
    new_file->size = strlen(content) + 1;
    new_file->next = file_system;
    file_system = new_file;
}

void print_file_system() {
    File *current = file_system;
    printf("\n---------- Happy File System -----------\n");
    printf("| Name            | Content                 |\n");
    printf("----------------------------------------\n");
    while (current != NULL) {
        printf("| %-15s | %-60s |\n", current->name, current->content);
        current = current->next;
    }
    printf("----------------------------------------\n");
}

int main() {
    create_file("File1.txt", "Hello, World! I am File1.");
    create_file("File2.txt", "I am File2. I love to simulate file systems.");
    create_file("File3.txt", "Three is a magic number. Let's create File3.");

    print_file_system();

    return 0;
}

// Happy file system simulation program in C
// Creates and stores files with names and contents in a linked list
// Prints the file system content in a happy style