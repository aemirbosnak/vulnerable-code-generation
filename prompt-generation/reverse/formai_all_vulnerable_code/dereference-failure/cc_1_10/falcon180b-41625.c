//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_points(int n, int **points) {
    int i, j;
    for (i = 0; i < n; i++) {
        points[i] = (int *)malloc(2 * sizeof(int));
        points[i][0] = rand_int(0, 100);
        points[i][1] = rand_int(0, 100);
    }
}

void convex_hull(int n, int **points) {
    int i, j, k;
    int *hull = (int *)malloc(n * sizeof(int));
    int hull_size = 0;

    for (i = 0; i < n; i++) {
        int min_dist = 100000;
        int min_idx = -1;

        for (j = 0; j < hull_size; j++) {
            int dist = abs(points[i][0] - points[hull[j]][0]) + abs(points[i][1] - points[hull[j]][1]);

            if (dist < min_dist) {
                min_dist = dist;
                min_idx = j;
            }
        }

        if (min_idx == -1) {
            hull[hull_size++] = i;
        }
    }

    printf("Convex hull:\n");
    for (i = 0; i < hull_size; i++) {
        printf("%d ", hull[i]);
    }
    printf("\n");

    free(hull);
}

int main() {
    int n, i;
    srand(time(NULL));

    printf("Enter the number of points: ");
    scanf("%d", &n);

    int **points = (int **)malloc(n * sizeof(int *));
    generate_points(n, points);

    convex_hull(n, points);

    for (i = 0; i < n; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}