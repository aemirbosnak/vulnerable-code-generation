//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    struct File* parent;
    int size;
    int data[1024];
} File;

File* file_create(char* name, int size) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    file->next = NULL;
    file->parent = NULL;
    file->size = size;
    return file;
}

void file_add_data(File* file, int data) {
    file->data[file->size++] = data;
}

void file_print(File* file) {
    printf("Name: %s\n", file->name);
    printf("Size: %d\n", file->size);
    printf("Data: ");
    for (int i = 0; i < file->size; i++) {
        printf("%d ", file->data[i]);
    }
    printf("\n");
}

int main() {
    File* root = NULL;

    // Create a few files
    File* file1 = file_create("file1.txt", 10);
    file_add_data(file1, 10);
    file_add_data(file1, 20);
    File* file2 = file_create("file2.txt", 5);
    file_add_data(file2, 30);
    file_add_data(file2, 40);

    // Print the files
    file_print(file1);
    file_print(file2);

    return 0;
}