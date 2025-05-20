//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name) {
    if (num_files >= MAX_FILES) {
        printf("Error: Cannot create file. Maximum number of files reached.\n");
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
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].content, 0, MAX_FILE_SIZE);
            strcpy(files[i].name, "");
            files[i].size = 0;
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

void read_from_file(char* name, char* buffer) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(buffer, files[i].content);
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    create_file("test.txt");
    write_to_file("test.txt", "Hello, world!");
    read_from_file("test.txt", "buffer");
    printf("%s\n", "buffer");

    delete_file("test.txt");

    return 0;
}