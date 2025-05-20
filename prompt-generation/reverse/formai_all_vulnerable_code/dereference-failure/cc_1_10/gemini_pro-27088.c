//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the robot's state
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} direction_t;

struct robot {
    int x;
    int y;
    direction_t direction;
};

// Define the robot's commands
typedef enum {
    MOVE_FORWARD,
    MOVE_BACKWARD,
    TURN_LEFT,
    TURN_RIGHT
} command_t;

// Create a new robot
struct robot *create_robot(int x, int y, direction_t direction) {
    struct robot *robot = malloc(sizeof(struct robot));
    robot->x = x;
    robot->y = y;
    robot->direction = direction;
    return robot;
}

// Destroy a robot
void destroy_robot(struct robot *robot) {
    free(robot);
}

// Move the robot forward
void move_forward(struct robot *robot) {
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
void move_backward(struct robot *robot) {
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
void turn_left(struct robot *robot) {
    switch (robot->direction) {
        case FORWARD:
            robot->direction = LEFT;
            break;
        case BACKWARD:
            robot->direction = RIGHT;
            break;
        case LEFT:
            robot->direction = BACKWARD;
            break;
        case RIGHT:
            robot->direction = FORWARD;
            break;
    }
}

// Turn the robot right
void turn_right(struct robot *robot) {
    switch (robot->direction) {
        case FORWARD:
            robot->direction = RIGHT;
            break;
        case BACKWARD:
            robot->direction = LEFT;
            break;
        case LEFT:
            robot->direction = FORWARD;
            break;
        case RIGHT:
            robot->direction = BACKWARD;
            break;
    }
}

// Execute a command on the robot
void execute_command(struct robot *robot, command_t command) {
    switch (command) {
        case MOVE_FORWARD:
            move_forward(robot);
            break;
        case MOVE_BACKWARD:
            move_backward(robot);
            break;
        case TURN_LEFT:
            turn_left(robot);
            break;
        case TURN_RIGHT:
            turn_right(robot);
            break;
    }
}

// Print the robot's state
void print_robot(struct robot *robot) {
    printf("Robot is at (%d, %d) facing %s\n", robot->x, robot->y, robot->direction == FORWARD ? "forward" : robot->direction == BACKWARD ? "backward" : robot->direction == LEFT ? "left" : "right");
}

// Main function
int main(int argc, char **argv) {
    // Create a new robot
    struct robot *robot = create_robot(0, 0, FORWARD);

    // Execute some commands on the robot
    execute_command(robot, MOVE_FORWARD);
    execute_command(robot, TURN_LEFT);
    execute_command(robot, MOVE_FORWARD);
    execute_command(robot, TURN_RIGHT);
    execute_command(robot, MOVE_BACKWARD);

    // Print the robot's state
    print_robot(robot);

    // Destroy the robot
    destroy_robot(robot);

    return 0;
}