//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct file {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char *data;
} File;

File *files[MAX_FILES];
int num_files;

void init() {
    num_files = 0;
}

void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: too many files\n");
        return;
    }

    File *file = (File *)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    file->data = (char *)malloc(size);

    files[num_files++] = file;
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            free(files[i]->data);
            free(files[i]);
            files[i] = NULL;
            num_files--;
            return;
        }
    }

    printf("Error: file not found\n");
}

void rename_file(char *old_name, char *new_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, old_name) == 0) {
            strcpy(files[i]->name, new_name);
            return;
        }
    }

    printf("Error: file not found\n");
}

void read_file(char *name, char *buffer, int size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            memcpy(buffer, files[i]->data, size);
            return;
        }
    }

    printf("Error: file not found\n");
}

void write_file(char *name, char *buffer, int size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            memcpy(files[i]->data, buffer, size);
            return;
        }
    }

    printf("Error: file not found\n");
}

int main() {
    init();

    create_file("test.txt", 10);
    write_file("test.txt", "Hello world", 11);
    read_file("test.txt", "buffer", 11);
    printf("buffer = %s\n", "buffer");

    rename_file("test.txt", "test2.txt");
    read_file("test2.txt", "buffer", 11);
    printf("buffer = %s\n", "buffer");

    delete_file("test2.txt");

    return 0;
}