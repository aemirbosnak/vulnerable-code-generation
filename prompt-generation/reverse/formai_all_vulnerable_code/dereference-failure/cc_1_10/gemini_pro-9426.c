//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char *name;
    char *content;
    size_t size;
} file;

typedef struct directory {
    char *name;
    struct directory **children;
    size_t num_children;
    file **files;
    size_t num_files;
} directory;

directory *root_directory;

void create_file(directory *dir, char *name, char *content, size_t size) {
    file *new_file = malloc(sizeof(file));
    new_file->name = malloc(strlen(name) + 1);
    new_file->content = malloc(strlen(content) + 1);
    strcpy(new_file->name, name);
    strcpy(new_file->content, content);
    new_file->size = size;

    dir->files = realloc(dir->files, (dir->num_files + 1) * sizeof(file *));
    dir->files[dir->num_files] = new_file;
    dir->num_files++;
}

void create_directory(directory *dir, char *name) {
    directory *new_dir = malloc(sizeof(directory));
    new_dir->name = malloc(strlen(name) + 1);
    strcpy(new_dir->name, name);
    new_dir->children = NULL;
    new_dir->num_children = 0;
    new_dir->files = NULL;
    new_dir->num_files = 0;

    dir->children = realloc(dir->children, (dir->num_children + 1) * sizeof(directory *));
    dir->children[dir->num_children] = new_dir;
    dir->num_children++;
}

void print_directory(directory *dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", dir->name);

    for (int i = 0; i < dir->num_files; i++) {
        for (int j = 0; j < depth + 1; j++) {
            printf("  ");
        }
        printf("%s\n", dir->files[i]->name);
    }

    for (int i = 0; i < dir->num_children; i++) {
        print_directory(dir->children[i], depth + 1);
    }
}

int main() {
    root_directory = malloc(sizeof(directory));
    root_directory->name = malloc(strlen("/") + 1);
    strcpy(root_directory->name, "/");
    root_directory->children = NULL;
    root_directory->num_children = 0;
    root_directory->files = NULL;
    root_directory->num_files = 0;

    create_directory(root_directory, "bin");
    create_directory(root_directory, "etc");
    create_directory(root_directory, "home");
    create_directory(root_directory, "lib");
    create_directory(root_directory, "mnt");
    create_directory(root_directory, "opt");
    create_directory(root_directory, "proc");
    create_directory(root_directory, "root");
    create_directory(root_directory, "run");
    create_directory(root_directory, "sbin");
    create_directory(root_directory, "srv");
    create_directory(root_directory, "sys");
    create_directory(root_directory, "tmp");
    create_directory(root_directory, "usr");
    create_directory(root_directory, "var");

    create_file(root_directory, "README.md", "This is a README file.", 24);
    create_file(root_directory, "LICENSE", "This is a LICENSE file.", 20);

    print_directory(root_directory, 0);

    return 0;
}