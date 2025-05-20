//FormAI DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define Robot Struct
typedef struct Robot {
    int id;
    int x;
    int y;
} Robot;

// Initialize Robot with id, x, y coordinates
Robot *new_robot(int id, int x, int y) {
    Robot *robot = (Robot *) malloc(sizeof(Robot));
    robot->id = id;
    robot->x = x;
    robot->y = y;
    return robot;
}

// Move Robot Up
void move_up(Robot *robot) {
    robot->y += 1;
}

// Move Robot Down
void move_down(Robot *robot) {
    robot->y -= 1;
}

// Move Robot Left
void move_left(Robot *robot) {
    robot->x -= 1;
}

// Move Robot Right
void move_right(Robot *robot) {
    robot->x += 1;
}

int main() {
    // Create new Robot at (0, 0)
    Robot *robot1 = new_robot(1, 0, 0);

    // Move robot up, left, right
    move_up(robot1);
    move_left(robot1);
    move_right(robot1);

    // Display final position
    printf("Robot %d is at (%d, %d)\n", robot1->id, robot1->x, robot1->y);

    // Create new Robot at (5, 5)
    Robot *robot2 = new_robot(2, 5, 5);

    // Move robot down, left, right
    move_down(robot2);
    move_left(robot2);
    move_right(robot2);

    // Display final position
    printf("Robot %d is at (%d, %d)\n", robot2->id, robot2->x, robot2->y);

    // Free memory
    free(robot1);
    free(robot2);

    return 0;
}