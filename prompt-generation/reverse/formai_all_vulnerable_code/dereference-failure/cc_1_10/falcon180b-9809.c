//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

struct file_header {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
};

struct directory {
    struct file_header *files;
    int num_files;
};

void create_file(struct directory *dir, char *file_name, int file_size) {
    struct file_header *new_file = malloc(sizeof(struct file_header));
    strncpy(new_file->file_name, file_name, MAX_FILE_NAME_LENGTH);
    new_file->file_size = file_size;
    dir->files = realloc(dir->files, sizeof(struct file_header) * (dir->num_files + 1));
    dir->files[dir->num_files] = *new_file;
    dir->num_files++;
}

void delete_file(struct directory *dir, char *file_name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].file_name, file_name) == 0) {
            dir->files = realloc(dir->files, sizeof(struct file_header) * (dir->num_files - 1));
            dir->num_files--;
            break;
        }
    }
}

void list_files(struct directory *dir) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("File name: %s, File size: %d bytes\n", dir->files[i].file_name, dir->files[i].file_size);
    }
}

int main() {
    struct directory root_dir;
    root_dir.files = NULL;
    root_dir.num_files = 0;

    create_file(&root_dir, "test.txt", 100);
    create_file(&root_dir, "test2.txt", 200);

    list_files(&root_dir);

    delete_file(&root_dir, "test2.txt");

    list_files(&root_dir);

    return 0;
}