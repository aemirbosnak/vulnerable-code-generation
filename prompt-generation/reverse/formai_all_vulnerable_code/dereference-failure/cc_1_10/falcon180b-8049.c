//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
} file_t;

file_t* create_file(const char* name) {
    file_t* file = malloc(sizeof(file_t));
    strcpy(file->name, name);
    file->size = 0;
    memset(file->content, 0, MAX_FILE_SIZE);
    return file;
}

void delete_file(file_t* file) {
    free(file);
}

void write_to_file(file_t* file, const char* content) {
    strcat(file->content, content);
    file->size += strlen(content);
}

void read_from_file(file_t* file) {
    printf("File name: %s\n", file->name);
    printf("File size: %d\n", file->size);
    printf("File content:\n%s\n", file->content);
}

int main() {
    file_t* file1 = create_file("file1.txt");
    write_to_file(file1, "Hello, world!");
    read_from_file(file1);

    file_t* file2 = create_file("file2.txt");
    write_to_file(file2, "Another file.");
    read_from_file(file2);

    delete_file(file1);
    delete_file(file2);

    return 0;
}