//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    int size;
} file_t;

int num_files = 0;
file_t files[100];

int add_file(char* name, char* data, int size) {
    if (num_files >= 100) {
        printf("Error: Too many files\n");
        return -1;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].data, data);
    files[num_files].size = size;

    num_files++;

    return 0;
}

int remove_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].data, '\0', MAX_FILE_SIZE);
            files[i] = files[num_files - 1];
            num_files--;

            return 0;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int read_file(char* name, char* buffer, int size) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(buffer, files[i].data, size);

            return 0;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int write_file(char* name, char* data, int size) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(files[i].data, data, size);

            return 0;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int main() {
    add_file("test.txt", "Hello, world!", strlen("Hello, world!"));
    read_file("test.txt", "buffer", strlen("buffer"));
    printf("%s\n", "buffer");

    return 0;
}