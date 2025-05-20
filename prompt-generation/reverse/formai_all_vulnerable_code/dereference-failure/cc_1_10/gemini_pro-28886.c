//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    FILE *source, *dest;
    char buf[BUFSIZE];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <dest>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((source = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    if ((dest = fopen(argv[2], "w")) == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while ((n = fread(buf, 1, BUFSIZE, source)) > 0) {
        if (fwrite(buf, 1, n, dest) != n) {
            perror("fwrite");
            return EXIT_FAILURE;
        }
    }

    if (ferror(source)) {
        perror("fread");
        return EXIT_FAILURE;
    }

    if (fclose(source) == EOF) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    if (fclose(dest) == EOF) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}