//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 100000
#define MAX_NUM_FILES 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    int is_deleted;
} File;

int num_files = 0;
File *files = NULL;

void init() {
    num_files = 0;
    files = (File*)malloc(MAX_NUM_FILES * sizeof(File));
    memset(files, 0, MAX_NUM_FILES * sizeof(File));
}

void create_file(char* name, int size) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    strncpy(files[num_files].name, name, MAX_FILE_NAME_LEN);
    files[num_files].size = size;
    files[num_files].is_deleted = 0;
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0 &&!files[i].is_deleted) {
            files[i].is_deleted = 1;
            break;
        }
    }
}

void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        if (!files[i].is_deleted) {
            printf("%s (%d bytes)\n", files[i].name, files[i].size);
        }
    }
}

int main() {
    init();

    create_file("test.txt", 42);
    create_file("another_file.txt", 1337);

    list_files();

    delete_file("test.txt");

    list_files();

    return 0;
}