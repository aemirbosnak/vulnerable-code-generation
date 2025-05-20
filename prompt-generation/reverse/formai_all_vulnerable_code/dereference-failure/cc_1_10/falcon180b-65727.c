//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Robot;

Robot *robot_create(double x, double y, double theta) {
    Robot *r = (Robot *) malloc(sizeof(Robot));
    r->x = x;
    r->y = y;
    r->theta = theta;
    return r;
}

void robot_destroy(Robot *r) {
    free(r);
}

void robot_move(Robot *r, double v, double w) {
    double dx = v * cos(r->theta);
    double dy = v * sin(r->theta);
    r->x += dx;
    r->y += dy;
    r->theta += w;
}

void robot_turn(Robot *r, double w) {
    r->theta += w;
}

double robot_distance(Robot *r1, Robot *r2) {
    double dx = r2->x - r1->x;
    double dy = r2->y - r1->y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Robot *r1 = robot_create(0, 0, 0);
    Robot *r2 = robot_create(10, 10, 0);

    robot_move(r1, 5, 0);
    robot_move(r2, 5, 0);

    printf("Distance: %f\n", robot_distance(r1, r2));

    robot_destroy(r1);
    robot_destroy(r2);

    return 0;
}