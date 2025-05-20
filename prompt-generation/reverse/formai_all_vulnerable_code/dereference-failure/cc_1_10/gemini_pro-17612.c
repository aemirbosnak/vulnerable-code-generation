//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 4096

char *my_gets(char *buf, int size)
{
    if (fgets(buf, size, stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Remove newline character
    buf[strlen(buf) - 1] = '\0';

    return buf;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source-file> <destination-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE];
    while (fread(buf, BUF_SIZE, 1, src)) {
        fwrite(buf, BUF_SIZE, 1, dst);
    }

    fclose(src);
    fclose(dst);

    printf("Backup complete.\n");

    return 0;
}