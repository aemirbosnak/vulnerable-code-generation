//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE 1024

typedef struct {
    char *name;
    int size;
    char *content;
} File;

typedef struct {
    File *files;
    int count;
} Dir;

Dir *create_dir(char *name) {
    Dir *dir = malloc(sizeof(Dir));
    dir->files = NULL;
    dir->count = 0;
    strcpy(dir->files[dir->count].name, name);
    dir->files[dir->count].size = 0;
    dir->files[dir->count].content = NULL;
    dir->count++;
    return dir;
}

int add_file(Dir *dir, char *name, char *content) {
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            free(dir->files[i].content);
            dir->files[i].content = strdup(content);
            dir->files[i].size = strlen(content);
            return 1;
        }
    }
    File *file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = strlen(content);
    file->content = strdup(content);
    dir->files = realloc(dir->files, sizeof(File) * (dir->count + 1));
    dir->files[dir->count] = *file;
    dir->count++;
    return 0;
}

int remove_file(Dir *dir, char *name) {
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            free(dir->files[i].content);
            dir->files = realloc(dir->files, sizeof(File) * (dir->count - 1));
            for (int j = i; j < dir->count - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }
            dir->count--;
            return 1;
        }
    }
    return 0;
}

int list_files(Dir *dir) {
    for (int i = 0; i < dir->count; i++) {
        printf("%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    Dir *root = create_dir("");
    add_file(root, "README", "This is a simple file system simulator.\n");
    add_file(root, "LICENSE", "Copyright (c) 2021 Linus Torvalds\n");
    list_files(root);
    remove_file(root, "README");
    list_files(root);
    return 0;
}