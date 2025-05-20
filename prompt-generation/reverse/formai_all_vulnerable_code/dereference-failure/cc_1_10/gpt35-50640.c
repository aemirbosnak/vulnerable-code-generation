//FormAI DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20

struct file {
    char name[MAX_FILENAME_LEN];
    int size;
    struct file* next;
};

// Function to create a new file
struct file* create_file(char filename[MAX_FILENAME_LEN], int filesize) {
    struct file* new_file = (struct file*)malloc(sizeof(struct file));
    strncpy(new_file->name, filename, MAX_FILENAME_LEN);
    new_file->size = filesize;
    new_file->next = NULL;
    return new_file;
}

// Recursive function to add a file to the filesystem
void add_file(struct file** curr_dir, char filename[MAX_FILENAME_LEN], int filesize) {
    if (*curr_dir == NULL) {
        *curr_dir = create_file(filename, filesize);
        printf("Created file: %s\n", filename);
    }
    else {
        if (strcmp((*curr_dir)->name, filename) == 0) {
            printf("File already exists: %s\n", filename);
        }
        else {
            add_file(&((*curr_dir)->next), filename, filesize);
        }
    }
}

// Recursive function to delete a file from the filesystem
int delete_file(struct file** curr_dir, char filename[MAX_FILENAME_LEN]) {
    if (*curr_dir == NULL) {
        return 0;
    }
    if (strcmp((*curr_dir)->name, filename) == 0) {
        struct file* temp = *curr_dir;
        *curr_dir = (*curr_dir)->next;
        free(temp);
        printf("Deleted file: %s\n", filename);
        return 1;
    }
    else {
        return delete_file(&((*curr_dir)->next), filename);
    }
}

// Recursive function to print the contents of the filesystem
void print_filesystem(struct file* curr_dir) {
    if (curr_dir == NULL) {
        return;
    }
    printf("File: %s, Size: %d\n", curr_dir->name, curr_dir->size);
    print_filesystem(curr_dir->next);
}

int main() {
    struct file* root = NULL;

    add_file(&root, "file1", 10);
    add_file(&root, "file2", 20);
    add_file(&root, "file3", 30);
    print_filesystem(root);

    delete_file(&root, "file2");
    print_filesystem(root);

    delete_file(&root, "file4");
    print_filesystem(root);

    return 0;
}