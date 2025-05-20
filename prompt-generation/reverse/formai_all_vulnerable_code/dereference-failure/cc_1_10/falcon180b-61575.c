//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000
#define BLOCK_SIZE 64

typedef struct {
    char *filename;
    char *data;
    size_t size;
} File;

void init_file(File *file, char *filename) {
    file->filename = filename;
    file->data = malloc(MAX_SIZE);
    file->size = 0;
}

void write_file(File *file, char *data, size_t size) {
    if (file->size + size > MAX_SIZE) {
        printf("Error: File is too large.\n");
        exit(1);
    }
    strncat(file->data, data, size);
    file->size += size;
}

void read_file(File *file) {
    printf("File: %s\n", file->filename);
    printf("Size: %zu bytes\n", file->size);
    printf("Data:\n%s\n", file->data);
}

void free_file(File *file) {
    free(file->data);
}

int main() {
    srand(time(NULL));
    char filename[32];
    sprintf(filename, "file_%d.txt", rand());
    File file;
    init_file(&file, filename);
    for (int i = 0; i < 10; i++) {
        char data[64];
        sprintf(data, "Line %d: Lorem ipsum dolor sit amet, consectetur adipiscing elit. ", i + 1);
        write_file(&file, data, strlen(data));
    }
    read_file(&file);
    free_file(&file);
    return 0;
}