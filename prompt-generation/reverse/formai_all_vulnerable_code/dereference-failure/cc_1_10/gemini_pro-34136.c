//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} buffer;

buffer *buffer_create() {
    buffer *buf = malloc(sizeof(buffer));
    buf->data = NULL;
    buf->size = 0;
    return buf;
}

void buffer_destroy(buffer *buf) {
    free(buf->data);
    free(buf);
}

void buffer_append(buffer *buf, const char *data, size_t size) {
    buf->data = realloc(buf->data, buf->size + size);
    memcpy(buf->data + buf->size, data, size);
    buf->size += size;
}

void buffer_clear(buffer *buf) {
    free(buf->data);
    buf->data = NULL;
    buf->size = 0;
}

void rle_compress(buffer *buf) {
    char *in = buf->data;
    char *out = buf->data;
    char prev = *in++;
    int count = 1;

    while (*in) {
        if (*in == prev) {
            count++;
        } else {
            *out++ = prev;
            *out++ = count;
            prev = *in;
            count = 1;
        }
        in++;
    }

    *out++ = prev;
    *out++ = count;
    buf->size = out - buf->data;
}

void rle_decompress(buffer *buf) {
    char *in = buf->data;
    char *out = buf->data;

    while (*in) {
        char c = *in++;
        int count = *in++;
        while (count--) {
            *out++ = c;
        }
    }

    buf->size = out - buf->data;
}

int main() {
    buffer *buf = buffer_create();

    char *test_data = "AAAABBBCCDEEEE";
    buffer_append(buf, test_data, strlen(test_data));

    printf("Original data: %s\n", test_data);

    rle_compress(buf);
    printf("Compressed data: %s\n", buf->data);

    rle_decompress(buf);
    printf("Decompressed data: %s\n", buf->data);

    buffer_destroy(buf);

    return 0;
}