//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileSystem {
    char* name;
    int size;
    char* content;
};

struct Directory {
    char* name;
    struct Directory* next;
};

struct FileSystem* create_file_system() {
    struct FileSystem* fs = (struct FileSystem*) malloc(sizeof(struct FileSystem));
    fs->name = (char*) malloc(sizeof(char) * 100);
    fs->size = 0;
    fs->content = NULL;
    return fs;
}

struct Directory* create_directory(struct FileSystem* fs, char* name) {
    struct Directory* dir = (struct Directory*) malloc(sizeof(struct Directory));
    dir->name = name;
    dir->next = NULL;
    return dir;
}

void add_file(struct FileSystem* fs, char* name, int size, char* content) {
    struct Directory* dir = create_directory(fs, name);
    fs->size += size;
    fs->content = realloc(fs->content, fs->size + 1);
    strcat(fs->content, content);
}

void print_file_system(struct FileSystem* fs) {
    printf("File System:\n");
    printf("Name: %s\n", fs->name);
    printf("Size: %d\n", fs->size);
    printf("Content:\n");
    printf("%s\n", fs->content);
}

int main() {
    struct FileSystem* fs = create_file_system();
    add_file(fs, "file1.txt", 100, "This is file 1");
    add_file(fs, "file2.txt", 200, "This is file 2");
    print_file_system(fs);
    return 0;
}