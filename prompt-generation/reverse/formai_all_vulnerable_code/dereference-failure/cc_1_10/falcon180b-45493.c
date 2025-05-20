//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define VIRUS_SIGNATURE "I am a virus"
#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *filename;
    char *data;
    size_t size;
} FileData;

void read_file(const char *filename, char **data, size_t *size) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    *data = malloc(*size);
    if (*data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for file data\n");
        exit(1);
    }

    size_t bytes_read = fread(*data, 1, *size, fp);
    if (bytes_read!= *size) {
        fprintf(stderr, "Error: could not read entire file\n");
        exit(1);
    }

    fclose(fp);
}

int is_virus(const char *data, size_t size) {
    for (size_t i = 0; i < size - strlen(VIRUS_SIGNATURE); i++) {
        if (memcmp(data + i, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FileData file_data;

    read_file(filename, &file_data.data, &file_data.size);

    if (file_data.size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: file is too large (%zu bytes)\n", file_data.size);
        exit(1);
    }

    if (is_virus(file_data.data, file_data.size)) {
        fprintf(stderr, "Error: file contains a virus\n");
        exit(1);
    }

    fprintf(stdout, "File is clean\n");
    return 0;
}