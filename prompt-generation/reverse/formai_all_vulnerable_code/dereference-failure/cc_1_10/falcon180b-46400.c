//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: too many files\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            num_files--;
            memset(&files[i], 0, sizeof(File));
            break;
        }
    }
}

void read_file(char* name, char* buffer, int size) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (files[i].size > size) {
                strncpy(buffer, files[i].data, size);
                buffer[size - 1] = '\0';
            } else {
                strcpy(buffer, files[i].data);
            }
            break;
        }
    }
}

void write_file(char* name, char* buffer, int size) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (files[i].size < size) {
                strncpy(files[i].data, buffer, files[i].size);
            } else {
                strcpy(files[i].data, buffer);
            }
            break;
        }
    }
}

int main() {
    create_file("test.txt", 20);
    write_file("test.txt", "Hello, world!", 13);
    read_file("test.txt", "buffer", 20);
    printf("%s\n", "buffer");
    delete_file("test.txt");
    return 0;
}