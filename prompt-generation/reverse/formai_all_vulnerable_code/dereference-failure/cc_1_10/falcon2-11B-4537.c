//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

int heuristic(Point* a, Point* b) {
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

int main() {
    Point start = {0, 0};
    Point goal = {5, 5};
    Point* frontier = (Point*)malloc(10 * sizeof(Point));
    Point* explored = (Point*)malloc(10 * sizeof(Point));

    int i = 0;
    frontier[i++] = start;

    while (i > 0) {
        Point current = frontier[0];
        frontier[0] = frontier[--i];

        if (current.x == goal.x && current.y == goal.y) {
            printf("Path found!\n");
            break;
        }

        Point next = current;
        int j = 0;
        for (; j < i; j++) {
            Point* neighbor = &frontier[j];
            int cost = heuristic(&next, &goal);

            if (cost < heuristic(neighbor, &goal)) {
                next = *neighbor;
            }
        }

        frontier[i++] = next;
    }

    if (i == 0) {
        printf("No path found\n");
    }

    free(frontier);
    free(explored);
    return 0;
}