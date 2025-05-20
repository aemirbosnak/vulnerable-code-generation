//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LEN 1024

typedef struct {
    int fd;
    char *buf;
    size_t buflen;
    size_t bufpos;
} ebook;

ebook *ebook_open(const char *filename) {
    ebook *eb = malloc(sizeof(ebook));
    if (!eb) return NULL;

    eb->fd = open(filename, O_RDONLY);
    if (eb->fd < 0) {
        free(eb);
        return NULL;
    }

    eb->buf = NULL;
    eb->buflen = 0;
    eb->bufpos = 0;

    return eb;
}

void ebook_close(ebook *eb) {
    if (!eb) return;

    if (eb->fd >= 0) close(eb->fd);
    if (eb->buf) free(eb->buf);
    free(eb);
}

int ebook_getline(ebook *eb, char *buf, size_t buflen) {
    if (!eb || !buf || buflen <= 0) return -1;

    while (eb->bufpos >= eb->buflen) {
        eb->buflen = read(eb->fd, eb->buf, MAX_LINE_LEN);
        if (eb->buflen <= 0) return -1;
        eb->bufpos = 0;
    }

    size_t i;
    for (i = 0; i < buflen - 1; i++) {
        buf[i] = eb->buf[eb->bufpos++];
        if (buf[i] == '\n') break;
    }
    buf[i] = '\0';

    return i;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    ebook *eb = ebook_open(argv[1]);
    if (!eb) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char buf[MAX_LINE_LEN + 1];
    while (ebook_getline(eb, buf, MAX_LINE_LEN + 1) > 0) {
        printf("%s", buf);
    }

    ebook_close(eb);

    return 0;
}