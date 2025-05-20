//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

struct file_system {
    char **files;
    int free_files;
    int current_dir;
    char **current_dir_path;
    struct file_system **children;
};

struct file_system *create_file_system() {
    struct file_system *fs = malloc(sizeof(struct file_system));
    fs->files = malloc(MAX_FILES * sizeof(char *));
    fs->free_files = MAX_FILES;
    fs->current_dir = 0;
    fs->current_dir_path = NULL;
    fs->children = NULL;

    return fs;
}

void add_file(struct file_system *fs, char *filename) {
    if (fs->free_files == 0) {
        return;
    }

    fs->files[fs->current_dir] = filename;
    fs->free_files--;
}

void cd(struct file_system *fs, char *directory) {
    int i;

    for (i = 0; i < fs->current_dir; i++) {
        if (strcmp(fs->files[i], directory) == 0) {
            fs->current_dir = i;
            return;
        }
    }

    return;
}

int main() {
    struct file_system *fs = create_file_system();

    add_file(fs, "a.txt");
    add_file(fs, "b.txt");
    add_file(fs, "c.txt");

    cd(fs, "a.txt");

    printf("Current directory: %s\n", fs->files[fs->current_dir]);

    return 0;
}