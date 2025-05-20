//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 1000000

typedef struct {
    uint8_t *data;
    size_t size;
} File;

File *read_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    File *file = malloc(sizeof(File));
    file->data = malloc(size);
    file->size = size;

    if (!file->data) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(file->data, 1, size, fp);
    fclose(fp);

    return file;
}

void write_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite(file->data, 1, file->size, fp);
    fclose(fp);
}

void embed_watermark(File *file, const char *watermark) {
    size_t watermark_len = strlen(watermark);
    if (watermark_len > file->size) {
        fprintf(stderr, "Watermark too long\n");
        return;
    }

    for (size_t i = 0; i < watermark_len; i++) {
        file->data[i] ^= watermark[i];
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    File *file = read_file(argv[1]);
    if (!file) {
        return EXIT_FAILURE;
    }

    embed_watermark(file, argv[3]);

    write_file(argv[2], file);

    free(file->data);
    free(file);

    return EXIT_SUCCESS;
}