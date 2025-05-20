//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char content[MAX_FILE_SIZE];
} File;

File files[MAX_FILES] = {{"", 0, ""}};
int num_files = 0;

void create_file(char* name) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = 0;
    strcpy(files[num_files].content, "");
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, sizeof(files[i].name));
            memset(files[i].content, 0, sizeof(files[i].content));
            num_files--;
            return;
        }
    }
    printf("Error: File not found.\n");
}

void rename_file(char* old_name, char* new_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void write_to_file(char* name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            files[i].size = strlen(content);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void read_from_file(char* name, char* buffer, int max_size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(buffer, files[i].content, max_size);
            return;
        }
    }
    printf("Error: File not found.\n");
}

int main() {
    create_file("test.txt");
    write_to_file("test.txt", "Hello, world!");
    read_from_file("test.txt", "buffer", 100);
    printf("%s\n", "buffer");
    delete_file("test.txt");
    return 0;
}