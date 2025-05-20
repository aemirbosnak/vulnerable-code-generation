//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WHEEL_RADIUS 0.05
#define WHEEL_BASE 0.2
#define TICKS_PER_REV 1000

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x, y;
} Vector;

typedef struct {
    double speed;
    Point position;
    Point velocity;
    Point acceleration;
} Robot;

Robot* create_robot() {
    Robot* robot = (Robot*)malloc(sizeof(Robot));
    robot->position.x = 0;
    robot->position.y = 0;
    robot->velocity.x = 0;
    robot->velocity.y = 0;
    robot->acceleration.x = 0;
    robot->acceleration.y = 0;
    robot->speed = 0;
    return robot;
}

void move_forward(Robot* robot, double distance) {
    double delta_x = distance / WHEEL_BASE / cos(robot->velocity.x);
    double delta_y = distance / WHEEL_BASE / sin(robot->velocity.x);
    robot->position.x += delta_x;
    robot->position.y += delta_y;
    robot->velocity.x += delta_x / distance;
    robot->velocity.y += delta_y / distance;
}

void turn_left(Robot* robot, double angle) {
    double delta_x = angle * sin(robot->velocity.x) / cos(robot->velocity.x);
    double delta_y = angle * cos(robot->velocity.x) / cos(robot->velocity.x);
    robot->velocity.x -= delta_x;
    robot->velocity.y -= delta_y;
}

void turn_right(Robot* robot, double angle) {
    double delta_x = angle * sin(robot->velocity.x) / cos(robot->velocity.x);
    double delta_y = angle * cos(robot->velocity.x) / cos(robot->velocity.x);
    robot->velocity.x += delta_x;
    robot->velocity.y += delta_y;
}

void update_robot(Robot* robot) {
    robot->position.x += robot->velocity.x;
    robot->position.y += robot->velocity.y;
    robot->velocity.x += robot->acceleration.x;
    robot->velocity.y += robot->acceleration.y;
    robot->speed = sqrt(robot->velocity.x * robot->velocity.x + robot->velocity.y * robot->velocity.y);
}

void print_robot(Robot* robot) {
    printf("Position: (%f, %f)\n", robot->position.x, robot->position.y);
    printf("Velocity: (%f, %f)\n", robot->velocity.x, robot->velocity.y);
    printf("Acceleration: (%f, %f)\n", robot->acceleration.x, robot->acceleration.y);
    printf("Speed: %f\n", robot->speed);
}

int main() {
    Robot* robot = create_robot();

    srand(time(NULL));

    int turns = 0;
    int distance = 0;

    while (distance < 10) {
        if (rand() % 2) {
            turn_right(robot, rand() % 360);
        } else {
            turn_left(robot, rand() % 360);
        }

        distance += rand() % 5;
        printf("Moving %d units forward\n", distance);
        move_forward(robot, distance);

        update_robot(robot);
        printf("Robot at (%f, %f)\n", robot->position.x, robot->position.y);
        turns++;
    }

    print_robot(robot);

    return 0;
}