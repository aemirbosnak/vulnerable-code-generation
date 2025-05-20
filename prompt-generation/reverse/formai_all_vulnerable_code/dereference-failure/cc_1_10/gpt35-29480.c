//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define BUFSIZE 8192
#define MAXCOUNT 1000

struct wc {
    size_t bytes;
    size_t chars;
    size_t words;
    size_t lines;
};

bool is_word_char(char c) {
    return ispunct(c) || isspace(c);
}

void init_wc(struct wc *wc) {
    wc->bytes = 0;
    wc->chars = 0;
    wc->words = 0;
    wc->lines = 0;
}

char *read_file(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return NULL;
    }

    char *buf = malloc(BUFSIZE);
    char *ptr = buf;
    size_t n = 0;
    size_t len = BUFSIZE;

    while ((n = fread(ptr, 1, BUFSIZE, file))) {
        buf = realloc(buf, len + BUFSIZE);
        if (!buf) {
            fprintf(stderr, "Error reallocating buffer: %s\n", strerror(errno));
            free(ptr);
            return NULL;
        }

        ptr = buf + len;
        len += BUFSIZE;
    }

    buf[len - BUFSIZE + n] = '\0';

    if (fclose(file) == EOF) {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        free(buf);
        return NULL;
    }

    return buf;
}

struct wc *count_chars(const char *buf, struct wc *wc) {
    wc->bytes = strlen(buf);
    wc->chars = wc->bytes;

    return wc;
}

struct wc *count_words(const char *buf, struct wc *wc) {
    bool in_word = false;

    for (const char *p = buf; *p != '\0'; p++) {
        if (is_word_char(*p)) {
            if (in_word) {
                wc->words++;
                in_word = false;
            }
        } else {
            wc->chars++;
            if (!in_word) {
                in_word = true;
            }
        }
    }

    if (in_word) {
        wc->words++;
    }

    return wc;
}

struct wc *count_lines(const char *buf, struct wc *wc) {
    for (const char *p = buf; *p != '\0'; p++) {
        if (*p == '\n') {
            wc->lines++;
        }
    }

    if (wc->bytes > 0 && buf[wc->bytes - 1] != '\n') {
        wc->lines++;
    }

    return wc;
}

void print_wc(const char *path, struct wc *wc) {
    printf("%lu %lu %lu", wc->lines, wc->words, wc->chars);
    printf(" %s\n", path);
}

void process_file(const char *path) {
    char *buf = read_file(path);
    if (!buf) {
        return;
    }

    struct wc wc;
    init_wc(&wc);
    count_chars(buf, &wc);
    count_words(buf, &wc);
    count_lines(buf, &wc);
    print_wc(path, &wc);

    free(buf);
}

int main(int argc, char *argv[]) {
    int count = 0;

    if (argc < 2) {
        printf("usage: %s [files...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (access(argv[i], R_OK) == -1) {
            fprintf(stderr, "Error accessing file: %s\n", strerror(errno));
            continue;
        }

        count++;

        if (count > MAXCOUNT) {
            fprintf(stderr, "Error: too many files (maximum %d)\n", MAXCOUNT);
            break;
        }

        process_file(argv[i]);
    }

    return 0;
}