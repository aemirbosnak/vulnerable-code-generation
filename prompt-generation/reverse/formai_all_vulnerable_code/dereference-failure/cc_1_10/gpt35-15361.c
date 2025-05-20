//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[20];
    char content[50];
};

struct directory {
    char name[20];
    struct directory *parent;
    struct file *files[5];
    int num_files;
};

void create_file(struct directory *dir, char *name) {
    if (dir->num_files >= 5) {
        printf("Cannot create file, maximum number of files reached.\n");
        return;
    }
    struct file *new_file = malloc(sizeof(struct file));
    strcpy(new_file->name, name);
    strcpy(new_file->content, "");
    dir->files[dir->num_files] = new_file;
    dir->num_files++;
}

void delete_file(struct directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            free(dir->files[i]);
            dir->num_files--;
            int j;
            for (j = i; j < dir->num_files; j++) {
                dir->files[j] = dir->files[j+1];
            }
            printf("File %s deleted.\n", name);
            return;
        }
    }
    printf("File %s not found.\n", name);
}

void display_files(struct directory *dir) {
    printf("Files in directory %s:\n", dir->name);
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("%s\n", dir->files[i]->name);
    }
}

void create_directory(struct directory *parent, char *name) {
    struct directory *new_dir = malloc(sizeof(struct directory));
    strcpy(new_dir->name, name);
    new_dir->parent = parent;
    new_dir->num_files = 0;
    int i;
    for (i = 0; i < 5; i++) {
        new_dir->files[i] = NULL;
    }
    printf("Directory %s created in %s.\n", name, parent->name);
}

void change_directory(struct directory **cur_dir, char *name) {
    if (strcmp(name, "..") == 0) {
        if ((*cur_dir)->parent == NULL) {
            printf("Cannot change to parent directory, already in root directory.\n");
            return;
        }
        *cur_dir = (*cur_dir)->parent;
        printf("Changed to directory %s.\n", (*cur_dir)->name);
    } else {
        int i;
        for (i = 0; i < (*cur_dir)->num_files; i++) {
            if (strcmp((*cur_dir)->files[i]->name, name) == 0) {
                printf("%s is a file, not a directory.\n", name);
                return;
            }
        }
        int found = 0;
        for (i = 0; i < (*cur_dir)->num_files; i++) {
            if (strcmp((*cur_dir)->files[i]->name, name) == 0 && (*cur_dir)->files[i] != NULL) {
                *cur_dir = (struct directory *) (*cur_dir)->files[i];
                found = 1;
                break;
            }
        }
        if (found) {
            printf("Changed to directory %s.\n", (*cur_dir)->name);
        } else {
            printf("Directory %s not found.\n", name);
        }
    }
}

int main() {
    struct directory *root = malloc(sizeof(struct directory));
    strcpy(root->name, "/");
    root->parent = NULL;
    root->num_files = 0;
    int i;
    for (i = 0; i < 5; i++) {
        root->files[i] = NULL;
    }
    struct directory *cur_dir = root;
    create_directory(cur_dir, "dir1");
    create_file(cur_dir, "file1");
    display_files(cur_dir);
    change_directory(&cur_dir, "dir1");
    create_file(cur_dir, "file2");
    delete_file(cur_dir, "file1");
    display_files(cur_dir);
    change_directory(&cur_dir, "..");
    delete_file(cur_dir, "file1");
    change_directory(&cur_dir, "dir2");
    return 0;
}