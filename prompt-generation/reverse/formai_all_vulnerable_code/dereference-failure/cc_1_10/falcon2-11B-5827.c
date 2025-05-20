//Falcon2-11B DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTORIES 3
#define MAX_FILES 5
#define MAX_FILE_SIZE 10

struct directory {
    char name[20];
    int num_subdirectories;
    int num_files;
    struct directory *subdirectories[MAX_DIRECTORIES];
    struct file *files[MAX_FILES];
};

struct file {
    char name[20];
    int size;
    char content[MAX_FILE_SIZE];
};

void create_directory(struct directory *dir, const char *name, int num_subdirectories, int num_files) {
    strcpy(dir->name, name);
    dir->num_subdirectories = num_subdirectories;
    dir->num_files = num_files;
    dir->subdirectories[0] = NULL;
    dir->files[0] = NULL;
    for (int i = 1; i < MAX_DIRECTORIES; i++) {
        dir->subdirectories[i] = NULL;
        dir->files[i] = NULL;
    }
}

void create_file(struct file *file, const char *name, int size) {
    strcpy(file->name, name);
    file->size = size;
    memset(file->content, 'x', size);
}

void create_filesystem(struct directory *root) {
    create_directory(root, "root", 0, 0);
    create_file(root->files[0], "file1", 5);
    create_file(root->files[1], "file2", 10);
    create_file(root->files[2], "file3", 15);
    create_file(root->files[3], "file4", 20);
    create_file(root->files[4], "file5", 25);
}

void print_directory(struct directory *dir) {
    printf("Directory: %s\n", dir->name);
    printf("Number of subdirectories: %d\n", dir->num_subdirectories);
    printf("Number of files: %d\n", dir->num_files);
    printf("Subdirectories:\n");
    for (int i = 0; i < MAX_DIRECTORIES; i++) {
        if (dir->subdirectories[i]!= NULL) {
            printf(" - %s\n", dir->subdirectories[i]->name);
        }
    }
    printf("Files:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (dir->files[i]!= NULL) {
            printf(" - %s (%d characters)\n", dir->files[i]->name, dir->files[i]->size);
        }
    }
}

int main() {
    struct directory *root = malloc(sizeof(struct directory));
    create_filesystem(root);
    print_directory(root);
    free(root);
    return 0;
}