//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct directory {
    char name[100];
    struct directory* next;
};

struct file {
    char name[100];
    struct file* next;
};

struct directory* current_dir;

void create_file(char* name) {
    struct file* new_file = (struct file*)malloc(sizeof(struct file));
    strcpy(new_file->name, name);
    new_file->next = current_dir->next;
    current_dir->next = new_file;
}

void create_directory(char* name) {
    struct directory* new_dir = (struct directory*)malloc(sizeof(struct directory));
    strcpy(new_dir->name, name);
    new_dir->next = current_dir->next;
    current_dir->next = new_dir;
}

void list_files() {
    struct file* file = current_dir->next;
    while (file!= NULL) {
        printf("%s\n", file->name);
        file = file->next;
    }
}

void delete_file(char* name) {
    struct file* file = current_dir->next;
    while (file!= NULL) {
        if (strcmp(file->name, name) == 0) {
            if (file->next == NULL) {
                current_dir->next = NULL;
            } else {
                struct file* temp = file->next;
                while (temp->next!= NULL) {
                    temp = temp->next;
                }
                temp->next = file->next;
            }
            free(file);
            return;
        }
        file = file->next;
    }
    printf("File not found\n");
}

void delete_directory(char* name) {
    struct directory* dir = current_dir->next;
    while (dir!= NULL) {
        if (strcmp(dir->name, name) == 0) {
            if (dir->next == NULL) {
                current_dir->next = NULL;
            } else {
                struct directory* temp = dir->next;
                while (temp->next!= NULL) {
                    temp = temp->next;
                }
                temp->next = dir->next;
            }
            free(dir);
            return;
        }
        dir = dir->next;
    }
    printf("Directory not found\n");
}

int main() {
    current_dir = NULL;

    create_file("file1.txt");
    create_file("file2.txt");
    create_directory("dir1");
    create_directory("dir2");
    list_files();

    delete_file("file1.txt");
    list_files();

    delete_directory("dir1");
    list_files();

    return 0;
}