//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LEN 255
#define MAX_FILE_LEN 1024

struct file {
    char name[MAX_NAME_LEN];
    char contents[MAX_FILE_LEN];
    struct file *next;
};

struct directory {
    char name[MAX_NAME_LEN];
    struct file *head;
};

void create_file(struct directory *dir, char *name, char *contents) {
    struct file *file = (struct file *)malloc(sizeof(struct file));
    strcpy(file->name, name);
    strcpy(file->contents, contents);
    file->next = dir->head;
    dir->head = file;
}

void read_file(struct directory *dir, char *name) {
    struct file *file = dir->head;
    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            printf("%s\n", file->contents);
            return;
        }
        file = file->next;
    }
    printf("File not found\n");
}

void delete_file(struct directory *dir, char *name) {
    struct file *file = dir->head;
    struct file *prev = NULL;

    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            if (prev == NULL) {
                dir->head = file->next;
            } else {
                prev->next = file->next;
            }
            free(file);
            return;
        }
        prev = file;
        file = file->next;
    }
    printf("File not found\n");
}

void list_files(struct directory *dir) {
    struct file *file = dir->head;
    while (file != NULL) {
        printf("%s\n", file->name);
        file = file->next;
    }
}

int main() {
    struct directory *root_dir = (struct directory *)malloc(sizeof(struct directory));
    strcpy(root_dir->name, "/");
    root_dir->head = NULL;

    create_file(root_dir, "file1.txt", "Hello World!");
    create_file(root_dir, "file2.txt", "This is a test!");
    create_file(root_dir, "file3.txt", "Hello again!");

    list_files(root_dir);

    read_file(root_dir, "file1.txt");

    delete_file(root_dir, "file2.txt");

    list_files(root_dir);

    return 0;
}