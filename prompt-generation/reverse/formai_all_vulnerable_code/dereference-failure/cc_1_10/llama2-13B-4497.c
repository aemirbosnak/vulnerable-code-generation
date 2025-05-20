//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 256
#define MAX_DIR_LEN 1024

// Structure to represent a file or directory
struct file_info {
    char name[MAX_NAME_LEN];  // File or directory name
    char parent_dir[MAX_NAME_LEN];  // Parent directory name
    struct file_info *child;  // Pointer to child directory or file
    int size;  // File size
};

// Function to create a new directory or file
void create_file(struct file_info *parent, char *name, int size) {
    struct file_info *new_file = (struct file_info *)malloc(sizeof(struct file_info));
    strcpy(new_file->name, name);
    new_file->parent_dir[0] = '\0';
    new_file->child = NULL;
    new_file->size = size;
    if (parent != NULL) {
        parent->child = new_file;
    }
}

// Function to delete a file or directory
void delete_file(struct file_info *file) {
    if (file->child != NULL) {
        delete_file(file->child);
    }
    free(file);
}

// Function to list all files and directories in a directory
void list_files(struct file_info *dir) {
    if (dir == NULL) {
        printf("No files or directories found.\n");
        return;
    }
    printf("Files and directories in %s:\n", dir->name);
    list_files(dir->child);
    printf("  %s\n", dir->name);
}

// Function to traverse the file system
void traverse(struct file_info *root) {
    list_files(root);
    if (root->child != NULL) {
        traverse(root->child);
    }
}

int main() {
    struct file_info *root = NULL;
    create_file(&root, "root", 0);
    create_file(&root, "file1", 1024);
    create_file(&root, "file2", 2048);
    create_file(&root, "dir1", 0);
    create_file(&root->child->child, "file3", 3072);
    create_file(&root->child->child, "file4", 4096);
    traverse(root);
    return 0;
}