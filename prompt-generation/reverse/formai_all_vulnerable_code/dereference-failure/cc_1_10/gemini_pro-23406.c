//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

typedef struct {
    unsigned char *buf;
    size_t buf_size;
    size_t buf_len;
} buffer_t;

static buffer_t *
buffer_new(size_t size)
{
    buffer_t *buf = malloc(sizeof(buffer_t));
    if (!buf)
        return NULL;

    buf->buf = malloc(size);
    if (!buf->buf) {
        free(buf);
        return NULL;
    }

    buf->buf_size = size;
    buf->buf_len = 0;

    return buf;
}

static void
buffer_free(buffer_t *buf)
{
    if (!buf)
        return;

    if (buf->buf)
        free(buf->buf);

    free(buf);
}

static int
buffer_append(buffer_t *buf, const void *data, size_t len)
{
    if (!buf || !data)
        return -1;

    if (buf->buf_len + len > buf->buf_size) {
        size_t new_size = buf->buf_size * 2;
        while (new_size < buf->buf_len + len)
            new_size *= 2;

        unsigned char *new_buf = realloc(buf->buf, new_size);
        if (!new_buf)
            return -1;

        buf->buf = new_buf;
        buf->buf_size = new_size;
    }

    memcpy(buf->buf + buf->buf_len, data, len);
    buf->buf_len += len;

    return 0;
}

static int
buffer_write_file(buffer_t *buf, const char *path)
{
    if (!buf || !path)
        return -1;

    FILE *fp = fopen(path, "wb");
    if (!fp)
        return -1;

    fwrite(buf->buf, 1, buf->buf_len, fp);
    fclose(fp);

    return 0;
}

static int
rle_compress(const unsigned char *data, size_t len, buffer_t *out)
{
    if (!data || !len || !out)
        return -1;

    unsigned char prev = *data++;
    size_t count = 1;

    while (len--) {
        if (*data == prev) {
            count++;
        } else {
            if (buffer_append(out, &prev, 1) < 0)
                return -1;

            if (buffer_append(out, &count, 1) < 0)
                return -1;

            prev = *data;
            count = 1;
        }

        data++;
    }

    if (buffer_append(out, &prev, 1) < 0)
        return -1;

    if (buffer_append(out, &count, 1) < 0)
        return -1;

    return 0;
}

int
main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    size_t len = ftell(fp);
    rewind(fp);

    unsigned char *data = malloc(len);
    if (!data) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }

    fread(data, 1, len, fp);
    fclose(fp);

    buffer_t *out = buffer_new(len);
    if (!out) {
        perror("buffer_new");
        free(data);
        return EXIT_FAILURE;
    }

    if (rle_compress(data, len, out) < 0) {
        perror("rle_compress");
        buffer_free(out);
        free(data);
        return EXIT_FAILURE;
    }

    if (buffer_write_file(out, argv[2]) < 0) {
        perror("buffer_write_file");
        buffer_free(out);
        free(data);
        return EXIT_FAILURE;
    }

    buffer_free(out);
    free(data);

    return EXIT_SUCCESS;
}