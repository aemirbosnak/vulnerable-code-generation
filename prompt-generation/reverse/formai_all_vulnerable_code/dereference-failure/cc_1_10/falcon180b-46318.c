//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointList;

void initPoint(Point *p, int x, int y) {
    p->x = x;
    p->y = y;
}

void initPointList(PointList *pl) {
    pl->points = (Point *)malloc(MAX_SIZE * sizeof(Point));
    pl->size = 0;
}

void addPoint(PointList *pl, int x, int y) {
    if (pl->size >= MAX_SIZE) {
        printf("Error: Point list is full.\n");
        return;
    }
    initPoint(&pl->points[pl->size], x, y);
    pl->size++;
}

void sortPointList(PointList *pl) {
    for (int i = 0; i < pl->size - 1; i++) {
        for (int j = i + 1; j < pl->size; j++) {
            if (pl->points[i].y > pl->points[j].y) {
                Point temp = pl->points[i];
                pl->points[i] = pl->points[j];
                pl->points[j] = temp;
            }
        }
    }
}

void printPointList(PointList *pl) {
    for (int i = 0; i < pl->size; i++) {
        printf("(%d, %d)\n", pl->points[i].x, pl->points[i].y);
    }
}

int main() {
    PointList pl;
    initPointList(&pl);
    addPoint(&pl, 2, 3);
    addPoint(&pl, 1, 4);
    addPoint(&pl, 5, 1);
    addPoint(&pl, 3, 2);
    sortPointList(&pl);
    printPointList(&pl);
    free(pl.points);
    return 0;
}