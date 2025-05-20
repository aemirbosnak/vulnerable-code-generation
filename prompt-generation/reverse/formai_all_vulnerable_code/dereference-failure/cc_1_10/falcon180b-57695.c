//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of sites
#define T 10 // number of attempts

// function prototypes
void init(int *arr);
int check(int *arr);
int count(int *arr);
void percolate(int *arr);

int main() {
    int *arr;
    srand(time(NULL));
    arr = (int *)malloc(N * sizeof(int));
    init(arr);
    printf("Initial grid:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < T; i++) {
        percolate(arr);
    }
    printf("Final grid:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void init(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 2;
    }
}

int check(int *arr) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int count(int *arr) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    return count;
}

void percolate(int *arr) {
    int x = rand() % N;
    int y = rand() % N;
    if (arr[x] == 1 && arr[y] == 0) {
        arr[y] = 1;
    }
}