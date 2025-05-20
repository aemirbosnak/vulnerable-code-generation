//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_NAME_LENGTH];
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, int size, char* content) {
    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    strcpy(files[num_files].content, content);
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(File));
            num_files--;
            break;
        }
    }
}

void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void read_file(char* name, char* buffer, int max_size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(buffer, files[i].content, max_size);
            break;
        }
    }
}

void write_file(char* name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            break;
        }
    }
}

int main() {
    create_file("test.txt", 10, "Hello World!");
    list_files();
    read_file("test.txt", "buffer", 50);
    printf("%s\n", "buffer");
    write_file("test.txt", "New Content");
    list_files();
    delete_file("test.txt");
    list_files();
    return 0;
}