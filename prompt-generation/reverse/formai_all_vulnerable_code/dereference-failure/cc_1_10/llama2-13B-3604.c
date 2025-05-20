//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

#define N 10000
#define M 1000

typedef struct {
    uint64_t a, b, c;
} vec3_t;

void init_vec3(vec3_t *v) {
    for (size_t i = 0; i < N; i++) {
        v[i].a = i % 3;
        v[i].b = i % 3 == 0 ? 1 : 0;
        v[i].c = i % 3 == 1 ? 1 : 0;
    }
}

void add(vec3_t *v1, vec3_t *v2, vec3_t *res) {
    for (size_t i = 0; i < N; i++) {
        res[i].a = v1[i].a + v2[i].a;
        res[i].b = v1[i].b + v2[i].b;
        res[i].c = v1[i].c + v2[i].c;
    }
}

void mul(vec3_t *v1, vec3_t *v2, vec3_t *res) {
    for (size_t i = 0; i < N; i++) {
        res[i].a = v1[i].a * v2[i].a;
        res[i].b = v1[i].b * v2[i].b;
        res[i].c = v1[i].c * v2[i].c;
    }
}

int main() {
    srand(time(NULL));

    vec3_t *v1 = malloc(N * sizeof(vec3_t));
    vec3_t *v2 = malloc(M * sizeof(vec3_t));
    vec3_t *res = malloc(N * sizeof(vec3_t));

    init_vec3(v1);
    init_vec3(v2);

    for (size_t i = 0; i < M; i++) {
        add(v1, v2 + i, res + i);
    }

    for (size_t i = 0; i < N; i++) {
        printf("%" PRIu64 " + %" PRIu64 " = %" PRIu64 "\n",
               res[i].a, res[i].b, res[i].c);
    }

    free(v1);
    free(v2);
    free(res);

    return 0;
}