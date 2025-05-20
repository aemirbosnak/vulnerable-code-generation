//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_DIR_NAME_LEN 256
#define MAX_FILE_SIZE 1024

typedef struct {
    char dir_name[MAX_DIR_NAME_LEN];
    struct dirent *dir_entries;
} Directory;

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char file_contents[MAX_FILE_SIZE];
} File;

Directory *create_directory(char *name) {
    Directory *new_dir = (Directory *) malloc(sizeof(Directory));
    strcpy(new_dir->dir_name, name);
    new_dir->dir_entries = NULL;
    return new_dir;
}

void delete_directory(Directory *dir) {
    free(dir);
}

void add_file(Directory *dir, char *name, char *contents) {
    File *new_file = (File *) malloc(sizeof(File));
    strcpy(new_file->file_name, name);
    strcpy(new_file->file_contents, contents);
    dir->dir_entries = (void *) new_file;
}

void delete_file(Directory *dir, char *name) {
    DIR *d;
    struct dirent *dirp;
    char path[MAX_DIR_NAME_LEN + MAX_FILE_NAME_LEN + 2];
    strcpy(path, dir->dir_name);
    strcat(path, "/");
    strcat(path, name);
    d = opendir(path);
    while ((dirp = readdir(d))!= NULL) {
        if (strcmp(dirp->d_name, name) == 0) {
            rmdir(path);
            closedir(d);
            return;
        }
    }
    closedir(d);
}

void list_files(Directory *dir) {
    DIR *d;
    struct dirent *dirp;
    d = opendir(dir->dir_name);
    if (d!= NULL) {
        while ((dirp = readdir(d))!= NULL) {
            printf("%s\n", dirp->d_name);
        }
        closedir(d);
    }
}

int main() {
    Directory *root = create_directory("");
    add_file(root, "test.txt", "Hello, world!");
    list_files(root);
    delete_file(root, "test.txt");
    list_files(root);
    delete_directory(root);
    return 0;
}