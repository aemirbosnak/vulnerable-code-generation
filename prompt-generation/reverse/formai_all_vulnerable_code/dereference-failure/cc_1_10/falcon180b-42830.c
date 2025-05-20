//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

#define MAX 1000
#define INF 999999

int rand_int(int a, int b) {
    return rand() % (b - a + 1) + a;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print_tower(int n, int* tower) {
    for (int i = 0; i <= n; ++i) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_tower(int n, int from, int to, int* tower) {
    if (n == 1) {
        tower[to] = tower[from];
        tower[from] = 0;
        return;
    }

    int top = tower[from];
    move_tower(n - 1, from, to - 1, tower);
    tower[to] = top;
}

int main() {
    srand(time(NULL));

    int tower[N];
    for (int i = 0; i < N; ++i) {
        tower[i] = rand_int(1, MAX);
    }

    int start = 0;
    int end = N - 1;

    printf("Initial tower:\n");
    print_tower(N, tower);

    move_tower(N, start, end, tower);

    printf("Final tower:\n");
    print_tower(N, tower);

    return 0;
}