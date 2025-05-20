//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct directory {
    char name[256];
    struct directory *children[256];
};

struct file {
    char name[256];
    struct directory *directory;
};

struct directory *root = NULL;
struct file *files = NULL;

void create_directory(struct directory *directory, char *name) {
    struct directory *new_directory = malloc(sizeof(struct directory));
    strcpy(new_directory->name, name);
    new_directory->children[0] = NULL;
    if (directory == NULL) {
        root = new_directory;
    } else {
        directory->children[0] = new_directory;
    }
}

void create_file(struct file *file, char *name, struct directory *directory) {
    struct file *new_file = malloc(sizeof(struct file));
    strcpy(new_file->name, name);
    new_file->directory = directory;
    if (files == NULL) {
        files = new_file;
    } else {
        files->directory = directory;
        files->directory->children[0] = new_file;
    }
}

void display_directory(struct directory *directory) {
    printf("Directory: %s\n", directory->name);
    for (int i = 0; i < 256; i++) {
        if (directory->children[i]!= NULL) {
            display_directory(directory->children[i]);
        }
    }
}

void display_files(struct directory *directory) {
    if (directory->children[0]!= NULL) {
        display_directory(directory->children[0]);
    }
    printf("Files:\n");
    for (int i = 0; i < 256; i++) {
        if (directory->children[i]!= NULL && directory->children[i]->children[0]!= NULL) {
            display_files(directory->children[i]);
        }
        printf("  %s\n", directory->children[i]->name);
    }
}

void delete_file(struct directory *directory, char *name) {
    for (int i = 0; i < 256; i++) {
        if (strcmp(directory->children[i]->name, name) == 0) {
            if (directory->children[i]->children[0]!= NULL) {
                delete_file(directory->children[i], name);
            }
            free(directory->children[i]);
            directory->children[i] = NULL;
            return;
        }
        if (directory->children[i]->children[0]!= NULL &&
            strcmp(directory->children[i]->children[0]->name, name) == 0) {
            delete_file(directory->children[i]->children[0], name);
        }
    }
}

int main() {
    create_directory(root, "Documents");
    create_file(files, "readme.txt", root);
    create_directory(root->children[0], "Programming");
    create_file(root->children[0]->children[0], "hello.c", root->children[0]);
    display_directory(root);
    delete_file(root, "readme.txt");
    display_directory(root);
    return 0;
}