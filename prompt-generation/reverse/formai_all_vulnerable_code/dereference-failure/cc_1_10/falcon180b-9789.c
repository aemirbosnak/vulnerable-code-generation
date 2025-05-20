//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char *filename;
    int blocks;
    int size;
    char *data;
} File;

void read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    file->data = malloc(file->size);
    file->blocks = (file->size + MAX_FILE_SIZE - 1) / MAX_FILE_SIZE;

    int i;
    for (i = 0; i < file->blocks; i++) {
        int bytes_read = fread(file->data + i * MAX_FILE_SIZE, 1, MAX_FILE_SIZE, fp);
        if (bytes_read!= MAX_FILE_SIZE) {
            printf("Error: could not read file '%s'\n", filename);
            exit(1);
        }
    }

    fclose(fp);
}

void write_file(const char *filename, const File *file) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int i;
    for (i = 0; i < file->blocks; i++) {
        int bytes_written = fwrite(file->data + i * MAX_FILE_SIZE, 1, MAX_FILE_SIZE, fp);
        if (bytes_written!= MAX_FILE_SIZE) {
            printf("Error: could not write file '%s'\n", filename);
            exit(1);
        }
    }

    fclose(fp);
}

int main() {
    File file;

    printf("Enter the name of the file to recover: ");
    scanf("%s", file.filename);

    read_file(file.filename, &file);

    printf("Enter the name of the recovered file: ");
    scanf("%s", file.filename);

    write_file(file.filename, &file);

    printf("File recovery complete.\n");

    return 0;
}