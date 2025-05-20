//FormAI DATASET v1.0 Category: File system simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

File filesystem[MAX_FILES];
int num_files = 0;

File* create_file(char* name, char* data, int size) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    memcpy(new_file->data, data, size);
    new_file->size = size;
    return new_file;
}

void create_filesystem() {
    char name[MAX_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;

    // create some sample files
    strcpy(name, "file1.txt");
    strcpy(data, "This is file1.txt");
    size = strlen(data);
    filesystem[num_files++] = *create_file(name, data, size);

    strcpy(name, "file2.txt");
    strcpy(data, "This is file2.txt");
    size = strlen(data);
    filesystem[num_files++] = *create_file(name, data, size);

    strcpy(name, "file3.txt");
    strcpy(data, "This is file3.txt");
    size = strlen(data);
    filesystem[num_files++] = *create_file(name, data, size);
}

void print_filesystem() {
    printf("Num Files: %d\n", num_files);
    for (int i = 0; i < num_files; i++) {
        File current_file = filesystem[i];
        printf("File %d:\n", i);
        printf("Name: %s\n", current_file.name);
        printf("Data: %s\n", current_file.data);
        printf("Size: %d\n", current_file.size);
    }
}

int main() {
    create_filesystem();
    print_filesystem();
    return 0;
}