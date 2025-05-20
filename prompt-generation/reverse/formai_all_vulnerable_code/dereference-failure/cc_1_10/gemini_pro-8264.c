//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *src, *dst;
    char buf[BUF_SIZE];
    size_t n;

    src = fopen(argv[1], "rb");
    if (!src) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    dst = fopen(argv[2], "wb");
    if (!dst) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        fclose(src);
        return EXIT_FAILURE;
    }

    while ((n = fread(buf, 1, BUF_SIZE, src))) {
        if (fwrite(buf, 1, n, dst) != n) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            fclose(src);
            fclose(dst);
            return EXIT_FAILURE;
        }
    }

    if (ferror(src)) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        fclose(src);
        fclose(dst);
        return EXIT_FAILURE;
    }

    fclose(src);
    fclose(dst);

    return EXIT_SUCCESS;
}