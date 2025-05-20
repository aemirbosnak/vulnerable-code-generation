//FormAI DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
} File;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int capacity;
    int num_files;
    File files[MAX_NUM_FILES];
} Directory;

Directory* create_directory(char* name, int capacity) {
    Directory* dir = (Directory*) malloc(sizeof(Directory));
    strcpy(dir->name, name);
    dir->capacity = capacity;
    dir->num_files = 0;
    return dir;
}

void add_file(Directory* dir, char* name, int size) {
    if (dir->num_files == MAX_NUM_FILES) {
        printf("Error: directory is full\n");
        return;
    }
    if (dir->capacity - dir->num_files < size) {
        printf("Error: not enough space in directory\n");
        return;
    }
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    dir->files[dir->num_files++] = new_file;
    dir->capacity -= size;
    printf("%s added to directory %s\n", name, dir->name);
}

void print_directory(Directory* dir) {
    printf("Directory %s:\n", dir->name);
    printf("Capacity: %d\n", dir->capacity);
    printf("Files:\n");
    for (int i = 0; i < dir->num_files; i++) {
        printf("\t%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    Directory* my_directory = create_directory("My Files", 1000);
    add_file(my_directory, "file1.txt", 200);
    add_file(my_directory, "file2.txt", 500);
    add_file(my_directory, "bigfile.dat", 800);
    print_directory(my_directory);

    return 0;
}