//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

struct file_info {
    char *filename;
    unsigned char *data;
    size_t size;
};

int is_infected(unsigned char *data, size_t size) {
    if (size < 4) {
        return 0;
    }

    unsigned int magic_number = *(unsigned int*)data;
    if (magic_number == 0x5A4D4D42) {
        return 1;
    }

    return 0;
}

void scan_file(struct file_info *file) {
    if (is_infected(file->data, file->size)) {
        printf("Infected: %s\n", file->filename);
    } else {
        printf("Clean: %s\n", file->filename);
    }
}

struct file_info read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    if (size > MAX_FILE_SIZE) {
        fprintf(stderr, "File is too large: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    unsigned char *data = malloc(size);
    if (data == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    size_t bytes_read = fread(data, 1, size, fp);
    if (bytes_read!= size) {
        fprintf(stderr, "Error reading file: %s\n", filename);
        exit(1);
    }

    struct file_info result = {
       .filename = strdup(filename),
       .data = data,
       .size = size,
    };

    fclose(fp);
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    struct file_info file = read_file(filename);

    scan_file(&file);

    free(file.filename);
    free(file.data);

    return 0;
}