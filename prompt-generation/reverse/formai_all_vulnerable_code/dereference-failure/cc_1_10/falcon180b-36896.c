//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 512

typedef struct {
    int valid;
    char data[CHUNK_SIZE];
} chunk_t;

void init_chunk(chunk_t *chunk) {
    chunk->valid = 0;
    memset(chunk->data, 0, sizeof(chunk->data));
}

FILE *open_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        exit(1);
    }
    return file;
}

void close_file(FILE *file) {
    fclose(file);
}

int read_chunk(FILE *file, chunk_t *chunk) {
    size_t bytes_read = fread(chunk->data, sizeof(char), CHUNK_SIZE, file);
    if (bytes_read!= CHUNK_SIZE) {
        if (ferror(file)) {
            printf("Error: Failed to read chunk from file\n");
        } else {
            printf("Warning: End of file reached\n");
        }
        return 0;
    }
    chunk->valid = 1;
    return 1;
}

void write_chunk(FILE *file, chunk_t *chunk) {
    fwrite(chunk->data, sizeof(char), CHUNK_SIZE, file);
}

int main() {
    char input_filename[256];
    char output_filename[256];

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    FILE *input_file = open_file(input_filename);
    FILE *output_file = open_file(output_filename);

    chunk_t chunk;
    init_chunk(&chunk);

    while (read_chunk(input_file, &chunk)) {
        write_chunk(output_file, &chunk);
    }

    close_file(input_file);
    close_file(output_file);

    printf("Data recovery completed.\n");

    return 0;
}