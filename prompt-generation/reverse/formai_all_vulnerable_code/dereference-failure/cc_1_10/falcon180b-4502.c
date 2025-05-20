//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
        return;
    }

    File *new_file = &files[num_files];
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->content[0] = '\0';

    num_files++;
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(File));
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void rename_file(char *old_name, char *new_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void write_to_file(char *name, char *content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void read_from_file(char *name, char *buffer, int size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(buffer, files[i].content, size);
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    create_file("test.txt", 10);
    write_to_file("test.txt", "Hello, world!");
    read_from_file("test.txt", "buffer", 10);
    printf("%s\n", "buffer");

    delete_file("test.txt");

    rename_file("test.txt", "new_name.txt");

    return 0;
}