//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_NAME_LEN];
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    memset(files[num_files].data, 0, MAX_FILE_NAME_LEN);

    num_files++;
}

void write_to_file(char *name, char *buffer, int offset, int length) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if ((offset + length) > files[i].size) {
                printf("Error: File is full.\n");
                return;
            }

            memcpy(files[i].data + offset, buffer, length);
            break;
        }
    }
}

void read_from_file(char *name, char *buffer, int offset, int length) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if ((offset + length) > files[i].size) {
                printf("Error: File is empty.\n");
                return;
            }

            memcpy(buffer, files[i].data + offset, length);
            break;
        }
    }
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LEN);
            memset(files[i].data, 0, MAX_FILE_NAME_LEN);
            num_files--;
            break;
        }
    }
}

int main() {
    create_file("test.txt", 100);
    write_to_file("test.txt", "Hello, world!", 0, 13);
    read_from_file("test.txt", "buffer", 0, 13);
    printf("%s\n", "buffer");
    delete_file("test.txt");
    return 0;
}