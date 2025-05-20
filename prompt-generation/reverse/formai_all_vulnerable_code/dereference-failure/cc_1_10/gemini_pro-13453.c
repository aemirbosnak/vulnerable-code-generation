//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

static bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static size_t count_words(const char *buf, size_t len) {
    size_t count = 0;
    bool in_word = false;
    for (size_t i = 0; i < len; i++) {
        if (is_whitespace(buf[i])) {
            in_word = false;
        } else if (!in_word) {
            count++;
            in_word = true;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "fopen: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char buf[BUF_SIZE];
    size_t total_words = 0;
    while (fgets(buf, BUF_SIZE, fp) != NULL) {
        size_t len = strlen(buf);
        if (len == BUF_SIZE - 1) {
            // the buffer is full, but there might be more data in the file
            fprintf(stderr, "warning: buffer is full, some data might have been lost\n");
        }
        total_words += count_words(buf, len);
    }

    if (ferror(fp)) {
        fprintf(stderr, "ferror: %s\n", strerror(errno));
        fclose(fp);
        return EXIT_FAILURE;
    }

    fclose(fp);

    printf("%zu words\n", total_words);
    return EXIT_SUCCESS;
}