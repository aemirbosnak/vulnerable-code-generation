//LLAMA2-13B DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10
#define M 5
#define K 3

typedef struct {
    int x[N];
    int y[M];
    int z[K];
} point_t;

point_t *points;
int num_points;

void init_points(void) {
    points = malloc(N * sizeof(point_t));
    for (int i = 0; i < N; i++) {
        points[i].x[0] = i % M;
        points[i].x[1] = i / M;
        points[i].y[0] = i % K;
        points[i].y[1] = i / K;
        points[i].z[0] = (i % K) % 2;
        points[i].z[1] = (i / K) % 2;
    }
    num_points = N;
}

void print_points(void) {
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", points[i].x[j]);
        }
        printf("\n");
    }
}

void move_points(void) {
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < 3; j++) {
            points[i].x[j] = points[i].x[j] + 1;
        }
    }
}

int main(void) {
    srand(time(NULL));
    init_points();
    print_points();
    move_points();
    print_points();
    return 0;
}