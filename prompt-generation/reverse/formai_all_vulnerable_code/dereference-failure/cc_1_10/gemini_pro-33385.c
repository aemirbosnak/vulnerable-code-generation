//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char *src;
    size_t src_len;
    unsigned char *dst;
    size_t dst_len;
} compression_context;

static void compress(compression_context *ctx) {
    unsigned char *src = ctx->src;
    size_t src_len = ctx->src_len;
    unsigned char *dst = ctx->dst;
    size_t dst_len = ctx->dst_len;

    unsigned char *out = dst;
    unsigned char *in = src;
    unsigned char *last = src + src_len;
    unsigned char *anchor = src;

    while (in < last) {
        if (*in == *anchor) {
            int count = 1;
            while (in + count < last && *(in + count) == *(in + count - 1))
                count++;
            if (count >= 3) {
                *(out++) = count - 1;
                *(out++) = *anchor;
                in += count;
                anchor = in;
                continue;
            }
        }
        *(out++) = 0;
        *(out++) = *in++;
        anchor = in;
    }

    ctx->dst_len = out - dst;
}

static void decompress(compression_context *ctx) {
    unsigned char *src = ctx->src;
    size_t src_len = ctx->src_len;
    unsigned char *dst = ctx->dst;
    size_t dst_len = ctx->dst_len;

    unsigned char *out = dst;
    unsigned char *in = src;
    unsigned char *last = src + src_len;

    while (in < last) {
        unsigned char count = *(in++);
        if (count == 0) {
            *(out++) = *(in++);
        } else {
            unsigned char value = *(in++);
            while (count--)
                *(out++) = value;
        }
    }

    ctx->dst_len = out - dst;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (fin == NULL) {
        fprintf(stderr, "Error opening input file '%s'\n", argv[1]);
        return 1;
    }

    fseek(fin, 0, SEEK_END);
    size_t src_len = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    unsigned char *src = malloc(src_len);
    if (src == NULL) {
        fprintf(stderr, "Error allocating memory for input buffer\n");
        fclose(fin);
        return 1;
    }

    size_t bytes_read = fread(src, 1, src_len, fin);
    if (bytes_read != src_len) {
        fprintf(stderr, "Error reading input file '%s'\n", argv[1]);
        fclose(fin);
        free(src);
        return 1;
    }

    fclose(fin);

    FILE *fout = fopen(argv[2], "wb");
    if (fout == NULL) {
        fprintf(stderr, "Error opening output file '%s'\n", argv[2]);
        free(src);
        return 1;
    }

    compression_context ctx;
    ctx.src = src;
    ctx.src_len = src_len;
    compress(&ctx);

    fwrite(ctx.dst, 1, ctx.dst_len, fout);
    fclose(fout);

    free(src);
    free(ctx.dst);

    return 0;
}