//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Directory {
    char name[50];
    struct Directory *next;
};

struct File {
    char name[50];
    int size;
    struct File *next;
};

struct Directory* create_directory(char *name) {
    struct Directory *new_dir = (struct Directory*)malloc(sizeof(struct Directory));
    strcpy(new_dir->name, name);
    new_dir->next = NULL;

    return new_dir;
}

void delete_directory(struct Directory *dir) {
    struct Directory *curr = dir;
    struct Directory *prev = NULL;

    while (curr!= NULL) {
        struct Directory *temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void modify_directory(struct Directory *dir, char *new_name) {
    struct Directory *curr = dir;

    while (curr!= NULL) {
        if (strcmp(curr->name, new_name) == 0) {
            strcpy(curr->name, new_name);
            break;
        }
        curr = curr->next;
    }
}

struct File* create_file(char *name, int size) {
    struct File *new_file = (struct File*)malloc(sizeof(struct File));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = NULL;

    return new_file;
}

void delete_file(struct File *file) {
    struct File *curr = file;
    struct File *prev = NULL;

    while (curr!= NULL) {
        struct File *temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void modify_file(struct File *file, char *new_name, int new_size) {
    struct File *curr = file;

    while (curr!= NULL) {
        if (strcmp(curr->name, new_name) == 0) {
            strcpy(curr->name, new_name);
            curr->size = new_size;
            break;
        }
        curr = curr->next;
    }
}

int main() {
    struct Directory *root = create_directory("/");
    struct File *file1 = create_file("file1.txt", 100);
    struct File *file2 = create_file("file2.txt", 200);

    modify_directory(root, "dir1");
    create_file("dir1/file1.txt", 50);
    create_file("dir1/file2.txt", 75);

    delete_file(file1);
    delete_directory(root);

    return 0;
}