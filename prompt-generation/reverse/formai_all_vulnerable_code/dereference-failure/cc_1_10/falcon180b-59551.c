//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SYSTEM_SIZE 1000000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char contents[MAX_FILE_SYSTEM_SIZE];
    int size;
} File;

File* create_file(char* name) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = 0;
    return file;
}

void delete_file(File* file) {
    free(file);
}

void write_to_file(File* file, char* contents) {
    int new_size = strlen(contents);
    if (new_size > MAX_FILE_SYSTEM_SIZE - file->size) {
        printf("Error: File is too large.\n");
        return;
    }
    strcat(file->contents, contents);
    file->size += new_size;
}

void print_file_contents(File* file) {
    printf("%s:\n%s\n", file->name, file->contents);
}

int main() {
    File* file1 = create_file("file1.txt");
    write_to_file(file1, "Hello, world!\n");
    print_file_contents(file1);

    File* file2 = create_file("file2.txt");
    write_to_file(file2, "This is a test.\n");
    print_file_contents(file2);

    delete_file(file1);
    delete_file(file2);

    return 0;
}