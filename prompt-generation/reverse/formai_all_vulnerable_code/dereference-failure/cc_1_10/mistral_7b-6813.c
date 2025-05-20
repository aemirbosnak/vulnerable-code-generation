//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 20
#define MAX_DIR_SIZE 10

typedef struct File {
    char name[MAX_FILE_NAME];
    int size;
    struct File *next;
} File;

File *dir = NULL;
int num_files = 0;

void create_file(char *name, int size) {
    File *new_file = (File *)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = dir;
    dir = new_file;
    num_files++;
}

void delete_file(char *name) {
    File *current = dir;
    File *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                dir = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            num_files--;
            break;
        }
        prev = current;
        current = current->next;
    }
}

void read_file(char *name, int *buffer, int *size) {
    File *current = dir;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            *size = current->size;
            *buffer = malloc(*size);
            memcpy(*buffer, current->name, *size);
            break;
        }
        current = current->next;
    }
}

void write_file(char *name, int size, int *buffer) {
    File *new_file = (File *)malloc(sizeof(File));

    if (num_files >= MAX_DIR_SIZE) {
        printf("Directory is full.\n");
        free(new_file);
        return;
    }

    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = dir;
    dir = new_file;
    num_files++;

    if (size > 0) {
        memcpy(new_file->name, buffer, size);
    }
}

int main() {
    create_file("file1.txt", 20);
    create_file("file2.txt", 30);
    create_file("file3.txt", 10);

    int size;
    char *buffer;
    read_file("file1.txt", &size, &buffer);
    printf("Content of file1.txt:\n");
    printf("%s\n", buffer);
    free(buffer);

    write_file("file4.txt", 5, "Hello World!");

    delete_file("file3.txt");

    return 0;
}