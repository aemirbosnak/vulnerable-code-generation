//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTIONS 8
#define MAX_DIRECTION_LEN 10

typedef struct {
    char direction[MAX_DIRECTION_LEN];
    int distance;
} Movement;

typedef struct {
    int num_movements;
    Movement movements[MAX_DIRECTIONS];
} Robot;

Robot *create_robot() {
    Robot *robot = malloc(sizeof(Robot));
    robot->num_movements = 0;
    return robot;
}

void destroy_robot(Robot *robot) {
    free(robot);
}

void add_movement(Robot *robot, char *direction, int distance) {
    if (robot->num_movements < MAX_DIRECTIONS) {
        strcpy(robot->movements[robot->num_movements].direction, direction);
        robot->movements[robot->num_movements].distance = distance;
        robot->num_movements++;
    }
}

void print_robot_movements(Robot *robot) {
    for (int i = 0; i < robot->num_movements; i++) {
        printf("%s %d\n", robot->movements[i].direction, robot->movements[i].distance);
    }
}

int main() {
    Robot *robot = create_robot();

    add_movement(robot, "forward", 10);
    add_movement(robot, "right", 5);
    add_movement(robot, "backward", 7);
    add_movement(robot, "left", 3);
    add_movement(robot, "forward", 12);
    add_movement(robot, "right", 8);
    add_movement(robot, "backward", 10);
    add_movement(robot, "left", 5);

    print_robot_movements(robot);

    destroy_robot(robot);

    return 0;
}