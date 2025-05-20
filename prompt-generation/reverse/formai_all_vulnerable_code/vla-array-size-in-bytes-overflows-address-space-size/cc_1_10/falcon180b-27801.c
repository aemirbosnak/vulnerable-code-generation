//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int id;
    double x, y;
} Point;

int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

void kmeans(Point data[], int n, int k, int max_iterations) {
    int i, j;
    Point centers[k];
    int assignments[n];
    int changed;
    int iterations = 0;

    for (i = 0; i < k; i++) {
        centers[i] = data[rand() % n];
    }

    do {
        changed = 0;

        for (i = 0; i < n; i++) {
            int best_center = -1;
            double best_distance = INFINITY;

            for (j = 0; j < k; j++) {
                double distance = sqrt(pow(data[i].x - centers[j].x, 2.0) + pow(data[i].y - centers[j].y, 2.0));

                if (distance < best_distance) {
                    best_distance = distance;
                    best_center = j;
                }
            }

            if (assignments[i]!= best_center) {
                assignments[i] = best_center;
                changed = 1;
            }
        }

        iterations++;
    } while (changed && iterations < max_iterations);

    printf("Iterations: %d\n", iterations);

    for (i = 0; i < k; i++) {
        printf("Center %d: (%lf, %lf)\n", i, centers[i].x, centers[i].y);
    }

    for (i = 0; i < n; i++) {
        printf("Point %d assigned to center %d\n", i, assignments[i]);
    }
}

int main() {
    int n, k;
    Point data[100];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    printf("Enter the coordinates of the points:\n");

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &data[i].x, &data[i].y);
    }

    kmeans(data, n, k, 100);

    return 0;
}