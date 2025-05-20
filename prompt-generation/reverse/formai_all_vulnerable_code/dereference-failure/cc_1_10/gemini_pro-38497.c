//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    char *buf;
    size_t size;
    size_t capacity;
} Buffer;

static void buf_init(Buffer *buf) {
    buf->buf = malloc(MAX_BUF_SIZE);
    buf->size = 0;
    buf->capacity = MAX_BUF_SIZE;
}

static void buf_free(Buffer *buf) {
    free(buf->buf);
}

static void buf_grow(Buffer *buf) {
    buf->capacity *= 2;
    buf->buf = realloc(buf->buf, buf->capacity);
}

static void buf_add(Buffer *buf, const char *str, size_t len) {
    if (buf->size + len >= buf->capacity) {
        buf_grow(buf);
    }
    memcpy(buf->buf + buf->size, str, len);
    buf->size += len;
}

static void buf_add_int(Buffer *buf, int n) {
    char str[12];
    snprintf(str, sizeof(str), "%d", n);
    buf_add(buf, str, strlen(str));
}

static void buf_add_char(Buffer *buf, char c) {
    buf->buf[buf->size++] = c;
}

static void compress(Buffer *input, Buffer *output) {
    char prev = 0;
    int count = 0;
    for (size_t i = 0; i < input->size; i++) {
        char c = input->buf[i];
        if (c == prev) {
            count++;
        } else {
            if (prev != 0) {
                buf_add_char(output, prev);
                buf_add_int(output, count);
            }
            prev = c;
            count = 1;
        }
    }
    if (prev != 0) {
        buf_add_char(output, prev);
        buf_add_int(output, count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        return 1;
    }

    Buffer input_buf;
    buf_init(&input_buf);

    char buf[MAX_BUF_SIZE];
    size_t len;
    while ((len = fread(buf, 1, sizeof(buf), input)) > 0) {
        buf_add(&input_buf, buf, len);
    }

    fclose(input);

    Buffer output_buf;
    buf_init(&output_buf);

    compress(&input_buf, &output_buf);

    buf_free(&input_buf);

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("fopen");
        return 1;
    }

    fwrite(output_buf.buf, 1, output_buf.size, output);

    fclose(output);

    buf_free(&output_buf);

    return 0;
}