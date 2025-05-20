//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int size;
    struct file* next;
} file;

file* create_file(char* name, int size) {
    file* new_file = (file*)malloc(sizeof(file));
    new_file->name = name;
    new_file->size = size;
    new_file->next = NULL;
    return new_file;
}

file* find_file(file* files, char* name) {
    while (files!= NULL) {
        if (strcmp(files->name, name) == 0) {
            return files;
        }
        files = files->next;
    }
    return NULL;
}

void display_files(file* files) {
    while (files!= NULL) {
        printf("%s (%d) -> ", files->name, files->size);
        files = files->next;
    }
    printf("NULL\n");
}

void free_files(file* files) {
    while (files!= NULL) {
        file* temp = files;
        files = files->next;
        free(temp);
    }
}

int main() {
    file* files = NULL;

    file* new_file1 = create_file("file1", 1024);
    file* new_file2 = create_file("file2", 2048);
    file* new_file3 = create_file("file3", 3072);

    new_file1->next = new_file2;
    new_file2->next = new_file3;

    display_files(files);

    printf("File 1: %s\n", find_file(files, "file1")->name);
    printf("File 2: %s\n", find_file(files, "file2")->name);
    printf("File 3: %s\n", find_file(files, "file3")->name);

    free_files(files);

    return 0;
}