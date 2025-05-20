//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct file {
    char name[255];
    char *data;
    size_t size;
    struct file *next;
} file;

typedef struct directory {
    char name[255];
    struct file *files;
    struct directory *parent;
    struct directory *next;
} directory;

typedef struct filesystem {
    directory *root;
} filesystem;

file *file_create(char *name, char *data, size_t size) {
    file *f = malloc(sizeof(file));
    strcpy(f->name, name);
    f->data = malloc(size);
    memcpy(f->data, data, size);
    f->size = size;
    f->next = NULL;
    return f;
}

directory *directory_create(char *name, directory *parent) {
    directory *d = malloc(sizeof(directory));
    strcpy(d->name, name);
    d->files = NULL;
    d->parent = parent;
    d->next = NULL;
    return d;
}

filesystem *filesystem_create() {
    filesystem *fs = malloc(sizeof(filesystem));
    fs->root = directory_create("/", NULL);
    return fs;
}

void file_add_to_directory(directory *d, file *f) {
    f->next = d->files;
    d->files = f;
}

directory *directory_add_to_directory(directory *d, directory *child) {
    child->next = d->files;
    d->files = child;
    return child;
}

file *file_find_in_directory(directory *d, char *name) {
    file *f = d->files;
    while (f != NULL) {
        if (strcmp(f->name, name) == 0) {
            return f;
        }
        f = f->next;
    }
    return NULL;
}

directory *directory_find_in_directory(directory *d, char *name) {
    directory *child = d->files;
    while (child != NULL) {
        if (strcmp(child->name, name) == 0) {
            return child;
        }
        child = child->next;
    }
    return NULL;
}

void file_print(file *f) {
    printf("%s (%ld bytes)\n", f->name, f->size);
}

void directory_print(directory *d) {
    printf("%s\n", d->name);
    file *f = d->files;
    while (f != NULL) {
        file_print(f);
        f = f->next;
    }
    directory *child = d->files;
    while (child != NULL) {
        directory_print(child);
        child = child->next;
    }
}

void filesystem_print(filesystem *fs) {
    directory_print(fs->root);
}

int main() {
    filesystem *fs = filesystem_create();

    file *f1 = file_create("file1.txt", "Hello, world!", 13);
    file_add_to_directory(fs->root, f1);

    file *f2 = file_create("file2.txt", "This is a test file.", 19);
    file_add_to_directory(fs->root, f2);

    directory *d1 = directory_create("dir1", fs->root);
    directory_add_to_directory(fs->root, d1);

    file *f3 = file_create("file3.txt", "This is a file in dir1.", 23);
    file_add_to_directory(d1, f3);

    directory *d2 = directory_create("dir2", d1);
    directory_add_to_directory(d1, d2);

    file *f4 = file_create("file4.txt", "This is a file in dir2.", 23);
    file_add_to_directory(d2, f4);

    filesystem_print(fs);

    return 0;
}