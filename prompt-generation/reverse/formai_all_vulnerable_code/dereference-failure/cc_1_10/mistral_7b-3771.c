//MISTRAL-7B DATASET v1.0 Category: Fractal Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define WIDTH 512
#define HEIGHT 512
typedef struct {
    double x, y;
} point;
point randomPoint() {
    point p;
    p.x = (double) rand() / RAND_MAX * WIDTH;
    p.y = (double) rand() / RAND_MAX * HEIGHT;
    return p;
}
void iterate(point *p, double depth) {
    point q, r;
    if (depth == 0) return;
    q.x = p->x / 3.0;
    q.y = p->y / 3.0;
    r.x = q.x + (2.0 / 3.0) * (q.x - p->x);
    r.y = q.y + (2.0 / 3.0) * (q.y - p->y);
    iterate(&q, depth - 1);
    iterate(&r, depth - 1);
}
int main() {
    srand(time(NULL));
    point p;
    double depth = 6;
    int i;
    unsigned char *image = calloc(WIDTH * HEIGHT, sizeof(unsigned char));
    p.x = WIDTH / 2.0;
    p.y = HEIGHT / 2.0;
    iterate(&p, depth);
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        if ((p.x > 0 && p.x < WIDTH && p.y > 0 && p.y < HEIGHT)) {
            image[i] = 255;
        } else {
            image[i] = 0;
        }
        p.x += 1;
        p.y += 1;
    }
    for (i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            putchar(image[i + j * WIDTH] + 48);
        }
        putchar('\n');
    }
    free(image);
    return 0;
}