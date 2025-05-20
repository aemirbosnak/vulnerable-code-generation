//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF 9999

typedef struct {
    int x, y;
    int distance;
} Point;

void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(Point arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}

int euclideanDistance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void kMeans(Point arr[], int n, int k) {
    int i, j, count = 0;
    Point centroid[k];
    for (i = 0; i < k; i++) {
        centroid[i].x = arr[rand() % n].x;
        centroid[i].y = arr[rand() % n].y;
    }

    while (count < 10) {
        count++;
        for (i = 0; i < n; i++) {
            int minIndex = 0;
            int minDistance = INF;
            for (j = 0; j < k; j++) {
                int distance = euclideanDistance(arr[i], centroid[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = j;
                }
            }
            if (arr[i].distance!= minIndex) {
                swap(&arr[arr[i].distance], &arr[minIndex]);
            }
        }
        for (i = 0; i < k; i++) {
            int sumX = 0, sumY = 0;
            int count = 0;
            for (j = 0; j < n; j++) {
                if (arr[j].distance == i) {
                    sumX += arr[j].x;
                    sumY += arr[j].y;
                    count++;
                }
            }
            centroid[i].x = sumX / count;
            centroid[i].y = sumY / count;
        }
    }
    printf("Centroids: ");
    for (i = 0; i < k; i++) {
        printf("(%d, %d) ", centroid[i].x, centroid[i].y);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Point arr[MAX];
    int n, k;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        arr[i].distance = -1;
    }

    kMeans(arr, n, k);

    return 0;
}