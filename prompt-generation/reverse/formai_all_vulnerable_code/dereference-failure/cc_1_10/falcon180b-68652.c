//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Ken Thompson
// File system simulation in C by Ken Thompson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 128
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int num_files = 0;
File* files = NULL;

void init() {
    num_files = 0;
    files = NULL;
}

int create_file(char* name, int size) {
    if (num_files >= MAX_FILE_SIZE) {
        return -1;
    }
    File* new_file = (File*) malloc(sizeof(File));
    if (new_file == NULL) {
        return -1;
    }
    strcpy(new_file->name, name);
    new_file->size = size;
    files = (File*) realloc(files, (num_files + 1) * sizeof(File));
    files[num_files] = *new_file;
    num_files++;
    return 0;
}

int delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            free(files[i].data);
            files = (File*) realloc(files, (num_files - 1) * sizeof(File));
            memmove(&files[i], &files[i + 1], (num_files - i - 1) * sizeof(File));
            num_files--;
            return 0;
        }
    }
    return -1;
}

int open_file(char* name, int mode) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int close_file(int fd) {
    return 0;
}

int read_file(int fd, char* buffer, int count) {
    if (fd < 0 || fd >= num_files) {
        return -1;
    }
    if (files[fd].size <= 0) {
        return 0;
    }
    int bytes_to_read = (count > files[fd].size)? files[fd].size : count;
    memcpy(buffer, files[fd].data, bytes_to_read);
    return bytes_to_read;
}

int write_file(int fd, char* buffer, int count) {
    if (fd < 0 || fd >= num_files) {
        return -1;
    }
    if (files[fd].size <= 0) {
        return 0;
    }
    int bytes_to_write = (count > files[fd].size - files[fd].size)? files[fd].size - files[fd].size : count;
    memcpy(files[fd].data, buffer, bytes_to_write);
    return bytes_to_write;
}

int main() {
    init();
    create_file("test.txt", 10);
    int fd = open_file("test.txt", 0);
    write_file(fd, "Hello, world!", 13);
    close_file(fd);
    fd = open_file("test.txt", 0);
    char buffer[13];
    read_file(fd, buffer, 13);
    printf("%s\n", buffer);
    close_file(fd);
    delete_file("test.txt");
    return 0;
}