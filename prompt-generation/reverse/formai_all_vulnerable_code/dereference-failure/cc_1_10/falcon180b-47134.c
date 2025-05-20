//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 10
#define WATERMARK_VALUE 0xCAFEBABE

typedef struct {
    char *filename;
    unsigned char *data;
    size_t size;
} FileData;

void read_file(const char *filename, unsigned char **data, size_t *size) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    rewind(fp);

    *data = malloc(*size);
    if (!*data) {
        fprintf(stderr, "Error: could not allocate memory for file data\n");
        exit(1);
    }

    fread(*data, 1, *size, fp);
    fclose(fp);
}

void write_file(const char *filename, const unsigned char *data, size_t size) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(data, 1, size, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    FileData input_file = {
       .filename = argv[1],
       .data = NULL,
       .size = 0
    };

    read_file(input_file.filename, &input_file.data, &input_file.size);

    unsigned char watermark[WATERMARK_SIZE] = { WATERMARK_VALUE };
    unsigned char *output_data = malloc(input_file.size + WATERMARK_SIZE);
    if (!output_data) {
        fprintf(stderr, "Error: could not allocate memory for output data\n");
        exit(1);
    }

    memcpy(output_data, input_file.data, input_file.size);
    memcpy(output_data + input_file.size, watermark, WATERMARK_SIZE);

    FileData output_file = {
       .filename = argv[2],
       .data = output_data,
       .size = input_file.size + WATERMARK_SIZE
    };

    write_file(output_file.filename, output_file.data, output_file.size);

    free(input_file.data);
    free(output_data);

    return 0;
}