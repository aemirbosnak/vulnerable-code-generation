//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct directory {
    char* name;
    struct directory* next;
    int num_files;
    int num_subdirs;
};

struct file {
    char* name;
    struct file* next;
    int size;
    int permissions;
};

void create_directory(struct directory* root, char* name, int num_files, int num_subdirs) {
    struct directory* new_dir = (struct directory*)malloc(sizeof(struct directory));
    new_dir->name = strdup(name);
    new_dir->next = NULL;
    new_dir->num_files = num_files;
    new_dir->num_subdirs = num_subdirs;
    new_dir->next = root;
    root = new_dir;
}

void create_file(struct file* root, char* name, int size, int permissions) {
    struct file* new_file = (struct file*)malloc(sizeof(struct file));
    new_file->name = strdup(name);
    new_file->next = NULL;
    new_file->size = size;
    new_file->permissions = permissions;
    new_file->next = root;
    root = new_file;
}

void list_files(struct directory* root) {
    struct directory* current = root;
    while (current!= NULL) {
        printf("Directory: %s\n", current->name);
        current = current->next;
    }
}

int main() {
    struct directory* root = NULL;
    create_directory(root, "root", 0, 0);
    create_file(root, "file1.txt", 100, 0644);
    create_file(root, "file2.txt", 200, 0644);
    create_directory(root, "dir1", 0, 0);
    create_file(root, "file3.txt", 300, 0644);
    create_directory(root, "dir2", 0, 0);
    create_file(root, "file4.txt", 400, 0644);
    create_file(root, "file5.txt", 500, 0644);
    list_files(root);
    return 0;
}