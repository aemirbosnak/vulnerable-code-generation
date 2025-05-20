//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define M 100

typedef struct {
    double a, b, c;
} point_t;

point_t generate_random_point(void) {
    point_t p;
    p.a = drand48() * 10.0 - 5.0;
    p.b = drand48() * 10.0 - 5.0;
    p.c = drand48() * 10.0 - 5.0;
    return p;
}

int main() {
    srand(time(NULL));

    point_t *points = calloc(N, sizeof(point_t));
    for (int i = 0; i < N; i++) {
        points[i] = generate_random_point();
    }

    double start = clock();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            double dot = 0;
            for (int k = 0; k < N; k++) {
                dot += points[j].a * points[k].b;
            }
            points[j].c = dot / (N * N);
        }
    }

    double end = clock();
    double elapsed = (end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < N; i++) {
        printf("%.2f ", points[i].c);
    }
    printf("\n");

    free(points);

    return 0;
}