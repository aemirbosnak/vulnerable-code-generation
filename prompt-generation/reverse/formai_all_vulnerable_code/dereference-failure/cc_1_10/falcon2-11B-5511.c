//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_COORDINATES 1000
#define MAX_STEPS 1000

struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void dijkstra(int startX, int startY, int goalX, int goalY, struct Node *node, int *closed) {
    int i, j;
    int x, y, g, h, f;
    int *open = (int *)malloc(MAX_COORDINATES * sizeof(int));
    int *neighbors = (int *)malloc(MAX_COORDINATES * sizeof(int));
    int steps = 0;

    for (i = 0; i < MAX_COORDINATES; i++) {
        node[i].g = INT_MAX;
        node[i].h = heuristic(startX, startY, goalX, goalY);
        node[i].f = node[i].g + node[i].h;
        open[i] = node[i].f;
    }

    open[0] = 0;
    closed[0] = 1;

    for (i = 0; i < MAX_COORDINATES; i++) {
        g = INT_MAX;
        f = INT_MAX;
        for (j = 0; j < MAX_COORDINATES; j++) {
            if (closed[j] == 0 && open[j] < f && node[j].g < g) {
                g = node[j].g;
                f = node[j].f;
                x = node[j].x;
                y = node[j].y;
            }
        }

        if (x == goalX && y == goalY) {
            printf("Found path of length %d:\n", steps);
            steps = 0;

            while (x!= startX || y!= startY) {
                printf("%d %d\n", x, y);
                steps++;
                node[i].x = x;
                node[i].y = y;
                g = node[i].g;
                h = node[i].h;
                f = g + h;
                open[i] = f;
                closed[i] = 1;
                if (i > 0) {
                    for (j = 0; j < MAX_COORDINATES; j++) {
                        if (closed[j] == 0 && open[j] < f && node[j].g < g) {
                            g = node[j].g;
                            h = node[j].h;
                            f = g + h;
                            open[j] = f;
                            closed[j] = 1;
                        }
                    }
                }
                i++;
            }
        }
    }
}

int main() {
    int startX, startY, goalX, goalY;
    int *closed = (int *)malloc(MAX_COORDINATES * sizeof(int));
    struct Node *node = (struct Node *)malloc(MAX_COORDINATES * sizeof(struct Node));

    printf("Enter start coordinates (x,y): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter goal coordinates (x,y): ");
    scanf("%d %d", &goalX, &goalY);

    dijkstra(startX, startY, goalX, goalY, node, closed);

    return 0;
}