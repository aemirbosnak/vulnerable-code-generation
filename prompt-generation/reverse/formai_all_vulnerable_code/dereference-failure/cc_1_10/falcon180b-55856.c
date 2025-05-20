//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    char *data;
    size_t size;
} file_t;

void recover_data(file_t *file) {
    FILE *fp = fopen(file->filename, "wb");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file->filename);
        exit(1);
    }

    if (fwrite(file->data, file->size, 1, fp)!= 1) {
        printf("Error: Could not write to file %s\n", file->filename);
        exit(1);
    }

    fclose(fp);
    printf("Successfully recovered data from file %s\n", file->filename);
}

void read_file(char *filename, void *buffer, size_t size) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    if (fread(buffer, size, 1, fp)!= 1) {
        printf("Error: Could not read from file %s\n", filename);
        exit(1);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <output_filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *output_filename = argv[2];

    file_t file;

    read_file(filename, &file.data, MAX_FILE_SIZE);
    file.filename = strdup(filename);
    file.size = strlen(file.data);

    recover_data(&file);

    free(file.data);
    free(file.filename);

    return 0;
}