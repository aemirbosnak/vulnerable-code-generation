//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 1024
#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    char contents[MAX_FILE_SIZE];
    int size;
} file_t;

file_t files[MAX_NUM_FILES];
int num_files = 0;

void create_file(char* name) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Too many files.\n");
        return;
    }

    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = 0;
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            memset(files[i].contents, 0, MAX_FILE_SIZE);
            files[i].size = 0;
            break;
        }
    }
}

void write_to_file(char* name, char* contents) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            strcpy(files[i].contents, contents);
            files[i].size = strlen(contents);
            break;
        }
    }
}

void read_from_file(char* name, char* buffer) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(name, files[i].name) == 0) {
            strcpy(buffer, files[i].contents);
            break;
        }
    }
}

int main() {
    create_file("test.txt");
    write_to_file("test.txt", "Hello, world!");
    read_from_file("test.txt", "buffer");
    printf("%s\n", "buffer");

    delete_file("test.txt");

    return 0;
}