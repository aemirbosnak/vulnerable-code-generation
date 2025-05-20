//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

typedef struct {
    unsigned char *buf;
    size_t size;
    size_t capacity;
} Buffer;

void buf_init(Buffer *buf) {
    buf->buf = malloc(MAX_BUF);
    buf->size = 0;
    buf->capacity = MAX_BUF;
}

void buf_free(Buffer *buf) {
    free(buf->buf);
}

void buf_append(Buffer *buf, unsigned char *data, size_t size) {
    if (buf->size + size > buf->capacity) {
        buf->capacity *= 2;
        buf->buf = realloc(buf->buf, buf->capacity);
    }

    memcpy(buf->buf + buf->size, data, size);
    buf->size += size;
}

void compress(Buffer *in, Buffer *out) {
    unsigned char *p = in->buf;
    unsigned char *q = out->buf;

    while (p < in->buf + in->size) {
        size_t count = 1;

        while (p + count < in->buf + in->size && p[count] == p[count - 1])
            count++;

        if (count >= 3) {
            *q++ = p[count - 1];
            *q++ = (count >> 8) & 0xff;
            *q++ = count & 0xff;
            p += count;
        } else {
            *q++ = *p++;
        }
    }

    *q++ = 0;
}

void decompress(Buffer *in, Buffer *out) {
    unsigned char *p = in->buf;
    unsigned char *q = out->buf;

    while (*p != 0) {
        if (*p & 0x80) {
            unsigned int count = (*p++ << 8) | *p++;
            while (count--)
                *q++ = *p;
        } else {
            *q++ = *p++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s compress|decompress input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    Buffer in, out;
    buf_init(&in);
    buf_init(&out);

    FILE *fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (!feof(fp)) {
        unsigned char buf[MAX_BUF];
        size_t size = fread(buf, 1, MAX_BUF, fp);
        buf_append(&in, buf, size);
    }

    fclose(fp);

    if (strcmp(argv[1], "compress") == 0)
        compress(&in, &out);
    else if (strcmp(argv[1], "decompress") == 0)
        decompress(&in, &out);
    else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fwrite(out.buf, 1, out.size, fp);
    fclose(fp);

    buf_free(&in);
    buf_free(&out);

    return EXIT_SUCCESS;
}