//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <ctype.h>

#define INPUT_SIZE 1024
#define BUFFER_SIZE 8192

typedef struct {
    char input[INPUT_SIZE];
    char buffer[BUFFER_SIZE];
    size_t pos;
} sanitizer_t;

void sanitize_input(sanitizer_t *s)
{
    size_t i, j;

    for (i = 0; i < s->pos; ++i) {
        if (!isalnum(s->buffer[i])) {
            memmove(s->buffer, s->buffer + i, s->pos - i);
            s->pos -= i;
            i--;
            continue;
        }
    }

    for (i = 0, j = 0; i < s->pos && j < INPUT_SIZE - 1; ++i, ++j)
        s->input[j] = s->buffer[i];

    s->input[j] = '\0';
}

int main(int argc, char *argv[])
{
    sanitizer_t s = {0};
    int fd;
    char *buf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    buf = mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    if (read(0, buf, BUFFER_SIZE) < 0) {
        perror("read");
        munmap(buf, BUFFER_SIZE);
        exit(EXIT_FAILURE);
    }

    s.pos = strlen(buf);
    strncpy(s.buffer, buf, BUFFER_SIZE - 1);

    sanitize_input(&s);

    printf("Sanitized input: %s\n", s.input);

    munmap(buf, BUFFER_SIZE);

    return EXIT_SUCCESS;
}