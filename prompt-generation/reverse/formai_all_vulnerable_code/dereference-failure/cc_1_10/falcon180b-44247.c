//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int num_files = 0;
File files[MAX_NUM_FILES];

void create_file(char *name, int size, char *data) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    memcpy(files[num_files].data, data, size);

    num_files++;
}

void list_files() {
    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void read_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File contents:\n");
            printf("%s", files[i].data);
            break;
        }
    }
}

void write_file(char *name, int size, char *data) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memcpy(files[i].data, data, size);
            printf("File updated.\n");
            break;
        }
    }
}

void delete_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].data, 0, MAX_FILE_SIZE);
            num_files--;
            printf("File deleted.\n");
            break;
        }
    }
}

int main() {
    create_file("test.txt", 23, "Hello, world!");
    create_file("example.bin", 512, "This is an example binary file.");

    list_files();

    read_file("test.txt");

    write_file("test.txt", 30, "Hello, C programming language!");

    list_files();

    delete_file("example.bin");

    list_files();

    return 0;
}