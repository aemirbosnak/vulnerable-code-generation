//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    char *buf;
    size_t buf_size;
    size_t buf_pos;
} buffer_t;

void buffer_init(buffer_t *buf, size_t size) {
    buf->buf = malloc(size);
    buf->buf_size = size;
    buf->buf_pos = 0;
}

void buffer_free(buffer_t *buf) {
    free(buf->buf);
}

int buffer_write(buffer_t *buf, const void *data, size_t size) {
    if (buf->buf_pos + size > buf->buf_size) {
        return -1;
    }
    memcpy(buf->buf + buf->buf_pos, data, size);
    buf->buf_pos += size;
    return 0;
}

int buffer_read(buffer_t *buf, void *data, size_t size) {
    if (buf->buf_pos + size > buf->buf_size) {
        return -1;
    }
    memcpy(data, buf->buf + buf->buf_pos, size);
    buf->buf_pos += size;
    return 0;
}

int compress(const char *input, char *output) {
    buffer_t buf;
    size_t i, j, k;

    buffer_init(&buf, MAX_BUF_SIZE);

    for (i = 0, j = 0, k = 0; input[i] != '\0'; i++) {
        if (input[i] == input[j]) {
            k++;
        } else {
            buffer_write(&buf, &j, sizeof(j));
            buffer_write(&buf, &k, sizeof(k));
            j = i;
            k = 1;
        }
    }
    buffer_write(&buf, &j, sizeof(j));
    buffer_write(&buf, &k, sizeof(k));

    memcpy(output, buf.buf, buf.buf_pos);

    buffer_free(&buf);

    return buf.buf_pos;
}

int decompress(const char *input, char *output) {
    buffer_t buf;
    size_t i, j, k;

    buffer_init(&buf, MAX_BUF_SIZE);

    for (i = 0; i < strlen(input); i += sizeof(j) + sizeof(k)) {
        buffer_read(&buf, &j, sizeof(j));
        buffer_read(&buf, &k, sizeof(k));
        for (; k > 0; k--) {
            output[i++] = input[j];
        }
    }

    buffer_free(&buf);

    return i;
}

int main() {
    char input[] = "AAABBBCCCDDEEEFFF";
    char compressed[MAX_BUF_SIZE];
    char decompressed[MAX_BUF_SIZE];
    int compressed_size, decompressed_size;

    compressed_size = compress(input, compressed);
    printf("Compressed size: %d\n", compressed_size);

    decompressed_size = decompress(compressed, decompressed);
    printf("Decompressed size: %d\n", decompressed_size);

    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", compressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}