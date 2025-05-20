//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 100

typedef struct {
    char name[MAX_PATH];
    struct file* next;
} file_t;

typedef struct {
    file_t* head;
} fs_t;

void create_file(fs_t* fs, char* name, char* content) {
    file_t* new_file = (file_t*)malloc(sizeof(file_t));
    strcpy(new_file->name, name);
    new_file->next = fs->head;
    fs->head = new_file;
    printf("Created file: %s\n", name);
}

void delete_file(fs_t* fs, char* name) {
    file_t* temp = fs->head;
    file_t* prev = NULL;

    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp!= NULL) {
        if (prev == NULL) {
            fs->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Deleted file: %s\n", name);
    } else {
        printf("File not found: %s\n", name);
    }
}

void list_files(fs_t* fs) {
    file_t* temp = fs->head;

    while (temp!= NULL) {
        printf("File: %s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    fs_t fs;
    fs.head = NULL;

    create_file(&fs, "file1.txt", "Hello, World!");
    create_file(&fs, "file2.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    list_files(&fs);
    delete_file(&fs, "file2.txt");
    list_files(&fs);

    return 0;
}