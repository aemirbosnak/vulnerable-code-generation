//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    unsigned char *buf;
    size_t buf_size;
    size_t buf_used;
} buf_t;

static void buf_init(buf_t *buf) {
    buf->buf = malloc(MAX_BUF_SIZE);
    if (buf->buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    buf->buf_size = MAX_BUF_SIZE;
    buf->buf_used = 0;
}

static void buf_free(buf_t *buf) {
    free(buf->buf);
}

static void buf_write(buf_t *buf, void *data, size_t size) {
    if (buf->buf_used + size > buf->buf_size) {
        buf->buf_size *= 2;
        buf->buf = realloc(buf->buf, buf->buf_size);
        if (buf->buf == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
    }
    memcpy(buf->buf + buf->buf_used, data, size);
    buf->buf_used += size;
}

static void compress(buf_t *in, buf_t *out) {
    unsigned char *in_ptr = in->buf;
    unsigned char *out_ptr = out->buf;
    unsigned char prev = 0;
    unsigned char count = 0;

    while (in_ptr < in->buf + in->buf_used) {
        if (*in_ptr == prev) {
            count++;
        } else {
            if (count > 0) {
                buf_write(out, &prev, 1);
                buf_write(out, &count, 1);
            }
            prev = *in_ptr;
            count = 1;
        }
        in_ptr++;
    }

    if (count > 0) {
        buf_write(out, &prev, 1);
        buf_write(out, &count, 1);
    }
}

static void decompress(buf_t *in, buf_t *out) {
    unsigned char *in_ptr = in->buf;
    unsigned char *out_ptr = out->buf;

    while (in_ptr < in->buf + in->buf_used) {
        unsigned char prev = *in_ptr++;
        unsigned char count = *in_ptr++;

        while (count--) {
            buf_write(out, &prev, 1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s compress|decompress input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *in_file = fopen(argv[2], "rb");
    if (in_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *out_file = fopen(argv[3], "wb");
    if (out_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    buf_t in_buf;
    buf_init(&in_buf);

    buf_t out_buf;
    buf_init(&out_buf);

    if (strcmp(argv[1], "compress") == 0) {
        char buf[MAX_BUF_SIZE];
        while (fread(buf, 1, MAX_BUF_SIZE, in_file) > 0) {
            buf_write(&in_buf, buf, MAX_BUF_SIZE);
        }
        compress(&in_buf, &out_buf);
        fwrite(out_buf.buf, 1, out_buf.buf_used, out_file);
    } else if (strcmp(argv[1], "decompress") == 0) {
        char buf[MAX_BUF_SIZE];
        while (fread(buf, 1, MAX_BUF_SIZE, in_file) > 0) {
            buf_write(&in_buf, buf, MAX_BUF_SIZE);
        }
        decompress(&in_buf, &out_buf);
        fwrite(out_buf.buf, 1, out_buf.buf_used, out_file);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fclose(in_file);
    fclose(out_file);

    buf_free(&in_buf);
    buf_free(&out_buf);

    return EXIT_SUCCESS;
}