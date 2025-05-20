//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    unsigned char *buf;
    size_t size;
} buffer_t;

buffer_t* buffer_new(size_t size) {
    buffer_t *buf = malloc(sizeof(buffer_t));
    if (buf == NULL) {
        return NULL;
    }

    buf->buf = malloc(size);
    if (buf->buf == NULL) {
        free(buf);
        return NULL;
    }

    buf->size = size;

    return buf;
}

void buffer_free(buffer_t *buf) {
    if (buf == NULL) {
        return;
    }

    if (buf->buf != NULL) {
        free(buf->buf);
    }

    free(buf);
}

int buffer_write(buffer_t *buf, const void *data, size_t size) {
    if (buf == NULL || data == NULL) {
        return -1;
    }

    if (buf->size < size) {
        return -1;
    }

    memcpy(buf->buf, data, size);

    return 0;
}

int buffer_read(buffer_t *buf, void *data, size_t size) {
    if (buf == NULL || data == NULL) {
        return -1;
    }

    if (buf->size < size) {
        return -1;
    }

    memcpy(data, buf->buf, size);

    return 0;
}

int compress(buffer_t *src, buffer_t *dst) {
    unsigned char *src_ptr = src->buf;
    unsigned char *dst_ptr = dst->buf;

    unsigned char prev = *src_ptr++;

    while (*src_ptr != '\0') {
        unsigned char curr = *src_ptr++;

        if (curr == prev) {
            *dst_ptr++ = prev;
            *dst_ptr++ = curr;
        } else {
            *dst_ptr++ = prev;
        }

        prev = curr;
    }

    *dst_ptr++ = prev;

    return dst_ptr - dst->buf;
}

int decompress(buffer_t *src, buffer_t *dst) {
    unsigned char *src_ptr = src->buf;
    unsigned char *dst_ptr = dst->buf;

    while (*src_ptr != '\0') {
        unsigned char prev = *src_ptr++;

        if (*src_ptr == prev) {
            *dst_ptr++ = prev;
            src_ptr++;
        } else {
            *dst_ptr++ = prev;
        }
    }

    return dst_ptr - dst->buf;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (fin == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fin, 0, SEEK_END);
    size_t file_size = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    buffer_t *src = buffer_new(file_size);
    if (src == NULL) {
        fclose(fin);
        perror("buffer_new");
        return 1;
    }

    if (fread(src->buf, 1, file_size, fin) != file_size) {
        fclose(fin);
        buffer_free(src);
        perror("fread");
        return 1;
    }

    fclose(fin);

    buffer_t *dst = buffer_new(file_size + 1);
    if (dst == NULL) {
        buffer_free(src);
        perror("buffer_new");
        return 1;
    }

    int compressed_size = compress(src, dst);
    if (compressed_size < 0) {
        buffer_free(src);
        buffer_free(dst);
        perror("compress");
        return 1;
    }

    FILE *fout = fopen(argv[2], "wb");
    if (fout == NULL) {
        buffer_free(src);
        buffer_free(dst);
        perror("fopen");
        return 1;
    }

    if (fwrite(dst->buf, 1, compressed_size, fout) != compressed_size) {
        buffer_free(src);
        buffer_free(dst);
        fclose(fout);
        perror("fwrite");
        return 1;
    }

    fclose(fout);

    buffer_free(src);
    buffer_free(dst);

    return 0;
}