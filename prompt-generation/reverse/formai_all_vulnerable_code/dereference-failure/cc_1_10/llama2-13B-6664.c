//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_NAME_LENGTH 256
#define MAX_FILES 1000

struct file {
    char name[MAX_NAME_LENGTH];
    char contents[4096];
    off_t size;
    struct file *next;
};

struct directory {
    char name[MAX_NAME_LENGTH];
    struct file *files;
};

void init_file_system(struct directory *root) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        struct file *file = malloc(sizeof(struct file));
        file->name[0] = '\0';
        file->size = 0;
        file->next = NULL;
        if (i % 2 == 0) {
            file->name[0] = 'a';
            file->name[1] = 'b';
            file->name[2] = 'c';
            file->name[3] = 'd';
        } else {
            file->name[0] = 'e';
            file->name[1] = 'f';
            file->name[2] = 'g';
            file->name[3] = 'h';
        }
        file->contents[0] = '0';
        file->contents[1] = '1';
        file->contents[2] = '2';
        file->contents[3] = '3';
        file->contents[4] = '4';
        file->contents[5] = '5';
        file->contents[6] = '6';
        file->contents[7] = '7';
        file->contents[8] = '8';
        file->contents[9] = '9';
        root->files = file;
    }
}

void add_file(struct directory *directory, char *name) {
    struct file *file = malloc(sizeof(struct file));
    file->name[0] = '\0';
    file->size = 0;
    file->next = NULL;
    strcpy(file->name, name);
    file->contents[0] = '0';
    file->contents[1] = '1';
    file->contents[2] = '2';
    file->contents[3] = '3';
    file->contents[4] = '4';
    file->contents[5] = '5';
    file->contents[6] = '6';
    file->contents[7] = '7';
    file->contents[8] = '8';
    file->contents[9] = '9';
    file->size = strlen(file->name) + 1;
    directory->files = file;
}

void delete_file(struct directory *directory, char *name) {
    struct file *file, *prev = NULL;
    for (file = directory->files; file != NULL; file = file->next) {
        if (strcmp(file->name, name) == 0) {
            if (prev == NULL) {
                directory->files = file->next;
            } else {
                prev->next = file->next;
            }
            free(file);
            return;
        }
        prev = file;
    }
}

void list_files(struct directory *directory) {
    struct file *file;
    for (file = directory->files; file != NULL; file = file->next) {
        printf("%s\n", file->name);
    }
}

int main() {
    struct directory *root = malloc(sizeof(struct directory));
    init_file_system(root);
    char name[] = "example.txt";
    add_file(root, name);
    list_files(root);
    delete_file(root, name);
    list_files(root);
    return 0;
}