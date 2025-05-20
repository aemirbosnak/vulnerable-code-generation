//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Robot movement directions
enum Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Robot state
struct Robot {
    int x;
    int y;
    int direction;
};

// Create a new robot
struct Robot* create_robot(int x, int y, int direction) {
    struct Robot* robot = malloc(sizeof(struct Robot));
    robot->x = x;
    robot->y = y;
    robot->direction = direction;
    return robot;
}

// Destroy a robot
void destroy_robot(struct Robot* robot) {
    free(robot);
}

// Move the robot forward
void move_forward(struct Robot* robot) {
    switch (robot->direction) {
    case FORWARD:
        robot->y++;
        break;
    case BACKWARD:
        robot->y--;
        break;
    case LEFT:
        robot->x--;
        break;
    case RIGHT:
        robot->x++;
        break;
    }
}

// Move the robot backward
void move_backward(struct Robot* robot) {
    switch (robot->direction) {
    case FORWARD:
        robot->y--;
        break;
    case BACKWARD:
        robot->y++;
        break;
    case LEFT:
        robot->x++;
        break;
    case RIGHT:
        robot->x--;
        break;
    }
}

// Turn the robot left
void turn_left(struct Robot* robot) {
    robot->direction = (robot->direction + 1) % 4;
}

// Turn the robot right
void turn_right(struct Robot* robot) {
    robot->direction = (robot->direction - 1) % 4;
}

// Get the robot's current position
void get_position(struct Robot* robot, int* x, int* y) {
    *x = robot->x;
    *y = robot->y;
}

// Set the robot's current position
void set_position(struct Robot* robot, int x, int y) {
    robot->x = x;
    robot->y = y;
}

// Get the robot's current direction
int get_direction(struct Robot* robot) {
    return robot->direction;
}

// Set the robot's current direction
void set_direction(struct Robot* robot, int direction) {
    robot->direction = direction;
}

// Print the robot's current state
void print_robot(struct Robot* robot) {
    printf("Robot is at (%d, %d) facing %d\n", robot->x, robot->y, robot->direction);
}

// Main function
int main() {
    // Create a new robot
    struct Robot* robot = create_robot(0, 0, FORWARD);

    // Move the robot around randomly
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int direction = rand() % 4;
        switch (direction) {
        case FORWARD:
            move_forward(robot);
            break;
        case BACKWARD:
            move_backward(robot);
            break;
        case LEFT:
            turn_left(robot);
            break;
        case RIGHT:
            turn_right(robot);
            break;
        }
    }

    // Print the robot's final state
    print_robot(robot);

    // Destroy the robot
    destroy_robot(robot);

    return 0;
}