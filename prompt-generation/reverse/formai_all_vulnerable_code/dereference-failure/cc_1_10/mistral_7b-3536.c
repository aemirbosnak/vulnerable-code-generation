//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

typedef struct { int w, h; char *c; } matrix;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void pr(const char *s) {
    write(STDOUT_FILENO, s, strlen(s));
}

void pause_and_clean() {
    int i;
    for (i = 0; i < 1000000; i++) {
        usleep(1);
    }
    for (i = 0; i < 32; i++) {
        write(STDOUT_FILENO, "\033[F", 3);
        write(STDOUT_FILENO, "\033[J", 1);
    }
}

matrix *alloc_matrix(int w, int h) {
    matrix *m = malloc(sizeof(matrix));
    m->w = w;
    m->h = h;
    m->c = malloc(w * h);
    return m;
}

void free_matrix(matrix *m) {
    free(m->c);
    free(m);
}

void copy_matrix(const matrix *src, matrix *dst) {
    memcpy(dst->c, src->c, src->w * src->h);
}

int alive_neighbors(const int y, const int x, const matrix *m) {
    int i, j, count = 0;

    for (i = y - 1; i <= y + 1; i++) {
        for (j = x - 1; j <= x + 1; j++) {
            if (i < 0 || i >= m->h || j < 0 || j >= m->w) continue;
            if (i == y && j == x) continue;
            count += m->c[i * m->w + j] == '#' ? 1 : 0;
        }
    }

    return count;
}

void next_generation(matrix *m) {
    int i, j, y, x;

    matrix *tmp = alloc_matrix(m->w, m->h);
    copy_matrix(m, tmp);

    for (y = 0; y < m->h; y++) {
        for (x = 0; x < m->w; x++) {
            int neighbors = alive_neighbors(y, x, m);
            if (m->c[y * m->w + x] == '#' && (neighbors < 2 || neighbors > 3)) {
                tmp->c[y * m->w + x] = ' ';
            } else if (m->c[y * m->w + x] == ' ' && neighbors == 3) {
                tmp->c[y * m->w + x] = '#';
            }
        }
    }

    free_matrix(m);
    m = tmp;
}

void print_matrix(const matrix *m) {
    int i, j;

    for (i = 0; i < m->h; i++) {
        for (j = 0; j < m->w; j++) {
            putchar(m->c[i * m->w + j]);
        }
        putchar('\n');
    }
}

int main() {
    const int w = 25, h = 25;
    int i;

    matrix *m = alloc_matrix(w, h);

    for (i = 0; i < w * h; i++) {
        m->c[i] = i % 2 == 0 ? '#' : ' ';
    }

    for (;;) {
        print_matrix(m);
        pause_and_clean();
        next_generation(m);
    }

    free_matrix(m);
    return EXIT_SUCCESS;
}