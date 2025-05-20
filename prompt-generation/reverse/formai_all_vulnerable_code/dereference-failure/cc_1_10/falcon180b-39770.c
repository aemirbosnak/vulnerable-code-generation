//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOTS 10
#define MAX_POINTS 20
#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_RADIUS 50
#define MIN_RADIUS 10

typedef struct {
    int x;
    int y;
    int speed;
    int radius;
} Robot;

void init_robot(Robot *r, int x, int y, int speed, int radius) {
    r->x = x;
    r->y = y;
    r->speed = speed;
    r->radius = radius;
}

void print_robot(Robot r) {
    printf("Robot %d at (%d,%d) with speed %d and radius %d\n",
           r.x, r.y, r.speed, r.radius);
}

int main() {
    srand(time(NULL));
    int num_robots = rand() % MAX_ROBOTS + 1;
    Robot *robots = malloc(num_robots * sizeof(Robot));
    int i, j, num_points = rand() % MAX_POINTS + 1;
    int *points = malloc(num_points * sizeof(int));
    for (i = 0; i < num_points; i++) {
        points[i] = rand() % 100 + 1;
    }
    for (i = 0; i < num_robots; i++) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        int speed = rand() % MAX_SPEED + MIN_SPEED;
        int radius = rand() % MAX_RADIUS + MIN_RADIUS;
        init_robot(&robots[i], x, y, speed, radius);
        printf("Robot %d created at (%d,%d) with speed %d and radius %d\n",
               i+1, x, y, speed, radius);
    }
    for (i = 0; i < num_robots; i++) {
        for (j = 0; j < num_points; j++) {
            int dist = abs(robots[i].x - points[j]) + abs(robots[i].y - points[j]);
            if (dist <= robots[i].radius) {
                printf("Robot %d reached point %d\n", i+1, points[j]);
                break;
            }
        }
    }
    for (i = 0; i < num_robots; i++) {
        print_robot(robots[i]);
    }
    free(robots);
    free(points);
    return 0;
}