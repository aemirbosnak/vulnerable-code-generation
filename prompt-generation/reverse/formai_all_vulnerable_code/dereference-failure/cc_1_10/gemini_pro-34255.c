//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    char *data;
    size_t size;
    time_t created;
    time_t modified;
} File;

typedef struct {
    char *cwd;
    File *files[1024];
    int num_files;
} Directory;

Directory *root_dir;

void init_fs() {
    root_dir = malloc(sizeof(Directory));
    root_dir->cwd = malloc(1);
    strcpy(root_dir->cwd, "/");
    root_dir->num_files = 0;
}

void create_file(char *name, char *data, size_t size) {
    if (root_dir->num_files >= 1024) {
        fprintf(stderr, "Error: Too many files in root directory.\n");
        return;
    }

    File *file = malloc(sizeof(File));
    file->name = malloc(strlen(name) + 1);
    strcpy(file->name, name);
    file->data = malloc(size + 1);
    strcpy(file->data, data);
    file->size = size;
    file->created = time(NULL);
    file->modified = file->created;

    root_dir->files[root_dir->num_files] = file;
    root_dir->num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < root_dir->num_files; i++) {
        if (strcmp(root_dir->files[i]->name, name) == 0) {
            free(root_dir->files[i]->name);
            free(root_dir->files[i]->data);
            free(root_dir->files[i]);

            root_dir->files[i] = root_dir->files[root_dir->num_files - 1];
            root_dir->num_files--;

            return;
        }
    }

    fprintf(stderr, "Error: File not found.\n");
}

void print_files() {
    int i;

    printf("Files in root directory:\n");

    for (i = 0; i < root_dir->num_files; i++) {
        printf("%s\t%lu bytes\t%s\t%s\n", root_dir->files[i]->name, root_dir->files[i]->size, ctime(&root_dir->files[i]->created), ctime(&root_dir->files[i]->modified));
    }
}

int main(int argc, char **argv) {
    init_fs();

    create_file("hello.txt", "Hello, world!\n", 13);
    create_file("test.txt", "This is a test file.\n", 20);

    print_files();

    delete_file("test.txt");

    print_files();

    return 0;
}