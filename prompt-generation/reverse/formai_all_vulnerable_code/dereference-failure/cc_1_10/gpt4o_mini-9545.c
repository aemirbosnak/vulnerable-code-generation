//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define MAX_PATH_LENGTH 256

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    int size; // Size in KB
} File;

typedef struct Directory {
    char name[MAX_FILENAME_LENGTH];
    struct Directory *parent;
    struct Directory *subdirs[MAX_FILES];
    File *files[MAX_FILES];
    int subdir_count;
    int file_count;
} Directory;

Directory *create_directory(const char *name, Directory *parent) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    strncpy(dir->name, name, MAX_FILENAME_LENGTH);
    dir->parent = parent;
    dir->subdir_count = 0;
    dir->file_count = 0;
    return dir;
}

File *create_file(const char *name, int size) {
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME_LENGTH);
    file->size = size;
    return file;
}

void add_file(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = file;
        printf("File '%s' added to '%s'.\n", file->name, dir->name);
    } else {
        printf("Cannot add file '%s': directory '%s' is full.\n", file->name, dir->name);
    }
}

void add_subdirectory(Directory *parent, Directory *subdir) {
    if (parent->subdir_count < MAX_FILES) {
        parent->subdirs[parent->subdir_count++] = subdir;
        printf("Directory '%s' created in '%s'.\n", subdir->name, parent->name);
    } else {
        printf("Cannot add directory '%s': directory '%s' is full.\n", subdir->name, parent->name);
    }
}

void list_directory(Directory *dir) {
    printf("Contents of directory '%s':\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("  File: %s (%d KB)\n", dir->files[i]->name, dir->files[i]->size);
    }
    for (int i = 0; i < dir->subdir_count; i++) {
        printf("  Directory: %s\n", dir->subdirs[i]->name);
    }
}

void free_file(File *file) {
    free(file);
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free_file(dir->files[i]);
    }
    for (int i = 0; i < dir->subdir_count; i++) {
        free_directory(dir->subdirs[i]);
    }
    free(dir);
}

int main() {
    Directory *root = create_directory("root", NULL);
    Directory *photos = create_directory("photos", root);
    Directory *docs = create_directory("documents", root);
    
    add_subdirectory(root, photos);
    add_subdirectory(root, docs);
    
    File *photo1 = create_file("photo1.jpg", 200);
    File *doc1 = create_file("doc1.txt", 150);
    File *doc2 = create_file("doc2.pdf", 350);
    
    add_file(photos, photo1);
    add_file(docs, doc1);
    add_file(docs, doc2);
    
    list_directory(root);
    list_directory(photos);
    list_directory(docs);
    
    // Clean up
    free_directory(root);
    
    return 0;
}