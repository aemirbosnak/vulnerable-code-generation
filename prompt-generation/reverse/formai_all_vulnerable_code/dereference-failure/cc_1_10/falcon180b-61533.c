//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

void init(int **matrix, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **matrix, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int calculate_distance(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    srand(time(NULL));
    int **matrix = (int **)malloc(sizeof(int *) * SIZE);
    for(int i=0; i<SIZE; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * SIZE);
    }
    init(matrix, SIZE);
    print_matrix(matrix, SIZE);

    Point start, end;
    start.x = rand() % SIZE;
    start.y = rand() % SIZE;
    end.x = rand() % SIZE;
    end.y = rand() % SIZE;

    int distance = calculate_distance(start, end);
    printf("Distance between (%d, %d) and (%d, %d): %d\n", start.x, start.y, end.x, end.y, distance);

    free(matrix[0]);
    free(matrix);
    return 0;
}