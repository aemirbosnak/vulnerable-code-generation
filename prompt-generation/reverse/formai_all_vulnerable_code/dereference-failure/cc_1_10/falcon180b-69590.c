//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
        return;
    }
    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = strlen(content);
    num_files++;
}

void delete_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].content, 0, MAX_FILE_CONTENT_LENGTH);
            strcpy(files[i].name, "");
            files[i].size = 0;
            num_files--;
            return;
        }
    }
    printf("Error: File not found.\n");
}

void rename_file(char* old_name, char* new_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void read_file(char* name, char* buffer, int buffer_size) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (files[i].size > buffer_size) {
                printf("Error: Buffer too small.\n");
                return;
            }
            strcpy(buffer, files[i].content);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void write_file(char* name, char* content) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            files[i].size = strlen(content);
            return;
        }
    }
    printf("Error: File not found.\n");
}

int main() {
    create_file("test.txt", "Hello, world!");
    read_file("test.txt", "buffer", 100);
    printf("%s\n", "buffer");
    delete_file("test.txt");
    return 0;
}