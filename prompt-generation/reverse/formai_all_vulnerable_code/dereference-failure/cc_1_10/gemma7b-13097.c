//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

struct File {
    char name[256];
    struct File* next;
    FILE* file_ptr;
};

struct Directory {
    char name[256];
    struct Directory* next;
    struct File** files;
};

struct FileSystem {
    struct Directory* root;
};

void create_file(struct FileSystem* fs, char* name, char* content) {
    struct File* file = malloc(sizeof(struct File));
    strcpy(file->name, name);
    file->next = NULL;
    file->file_ptr = fopen(name, "w");
    fprintf(file->file_ptr, content);
    fclose(file->file_ptr);
    if (fs->root == NULL) {
        fs->root = malloc(sizeof(struct Directory));
        strcpy(fs->root->name, "/");
        fs->root->next = NULL;
        fs->root->files = &file;
    } else {
        struct Directory* dir = fs->root;
        while (dir->next) {
            dir = dir->next;
        }
        dir->next = malloc(sizeof(struct Directory));
        strcpy(dir->next->name, name);
        dir->next->next = NULL;
        dir->next->files = &file;
    }
}

void list_files(struct FileSystem* fs) {
    struct Directory* dir = fs->root;
    while (dir) {
        struct File** files = dir->files;
        for (int i = 0; files[i] != NULL; i++) {
            printf("%s\n", files[i]->name);
        }
        dir = dir->next;
    }
}

int main() {
    struct FileSystem* fs = malloc(sizeof(struct FileSystem));
    fs->root = NULL;

    create_file(fs, "test.txt", "This is a file.");
    create_file(fs, "another.txt", "This is another file.");
    list_files(fs);

    return 0;
}