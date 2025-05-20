//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

typedef struct {
    char *buf;
    size_t size;
} buffer_t;

buffer_t read_file(const char *filename) {
    buffer_t buf = { 0 };
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while (!feof(fp)) {
        buf.buf = realloc(buf.buf, buf.size + BUF_SIZE);
        if (buf.buf == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        size_t read = fread(buf.buf + buf.size, 1, BUF_SIZE, fp);
        buf.size += read;
    }

    fclose(fp);
    return buf;
}

void write_file(const char *filename, buffer_t buf) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fwrite(buf.buf, 1, buf.size, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    buffer_t buf = read_file(argv[1]);
    // ... compress buf here ...
    write_file(argv[2], buf);

    free(buf.buf);
    return 0;
}