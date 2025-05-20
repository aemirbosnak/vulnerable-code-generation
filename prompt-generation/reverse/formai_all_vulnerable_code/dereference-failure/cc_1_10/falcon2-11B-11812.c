//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int num_files = 0;
char **file_names;
int **file_sizes;
char **file_contents;

void initialize_file_system() {
    num_files = 0;
    file_names = (char **)malloc(num_files * sizeof(char *));
    file_sizes = (int **)malloc(num_files * sizeof(int *));
    file_contents = (char **)malloc(num_files * sizeof(char *));
    for (int i = 0; i < num_files; i++) {
        file_names[i] = NULL;
        file_sizes[i] = NULL;
        file_contents[i] = NULL;
    }
}

void add_file(char *file_name, int file_size, char *file_content) {
    num_files++;
    file_names[num_files-1] = (char *)malloc(strlen(file_name) + 1);
    file_sizes[num_files-1] = (int)malloc(sizeof(int));
    *file_sizes[num_files-1] = file_size;
    file_contents[num_files-1] = (char *)malloc(file_size + 1);
    strcpy(file_names[num_files-1], file_name);
    strcpy(file_contents[num_files-1], file_content);
}

void display_file_system() {
    printf("File System:\n");
    for (int i = 0; i < num_files; i++) {
        printf("File Name: %s\n", file_names[i]);
        printf("File Size: %d bytes\n", *file_sizes[i]);
        printf("File Content:\n");
        for (int j = 0; j < *file_sizes[i]; j++) {
            printf("%c", file_contents[i][j]);
        }
        printf("\n");
    }
}

void remove_file(int file_index) {
    free(file_names[file_index]);
    free(file_sizes[file_index]);
    free(file_contents[file_index]);
    file_names[file_index] = NULL;
    file_sizes[file_index] = NULL;
    file_contents[file_index] = NULL;
    num_files--;
}

int main() {
    initialize_file_system();
    add_file("file1.txt", 100, "Hello, World!");
    add_file("file2.txt", 200, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    display_file_system();
    remove_file(1);
    display_file_system();
    return 0;
}