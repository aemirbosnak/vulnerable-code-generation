//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int x, y;
} Point;

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void init_points(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand_int(0, MAX_SIZE);
        points[i].y = rand_int(0, MAX_SIZE);
    }
}

void quicksort(Point* points, int left, int right) {
    int i = left, j = right;
    Point pivot = points[left];

    while (i < j) {
        while (points[j].y >= pivot.y && j > i) j--;
        if (i <= j) {
            Point temp = points[i];
            points[i] = points[j];
            points[j] = temp;
            i++;
            j--;
        }
    }

    points[i] = pivot;
    quicksort(points, left, i - 1);
    quicksort(points, i + 1, right);
}

int main() {
    srand(time(NULL));

    int n = MAX_SIZE;
    Point* points = malloc(n * sizeof(Point));

    init_points(points, n);

    quicksort(points, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }

    free(points);

    return 0;
}