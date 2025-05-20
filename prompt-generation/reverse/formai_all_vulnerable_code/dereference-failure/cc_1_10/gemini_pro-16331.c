//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the robot's state
typedef enum {
    STOPPED,
    MOVING_FORWARD,
    MOVING_BACKWARD,
    TURNING_LEFT,
    TURNING_RIGHT
} RobotState;

// Define the robot's movement
typedef struct {
    int x;
    int y;
    RobotState state;
} Robot;

// Create a new robot
Robot* robot_new() {
    Robot* robot = malloc(sizeof(Robot));
    if (robot == NULL) {
        return NULL;
    }

    robot->x = 0;
    robot->y = 0;
    robot->state = STOPPED;

    return robot;
}

// Free the robot
void robot_free(Robot* robot) {
    if (robot != NULL) {
        free(robot);
    }
}

// Move the robot forward
void robot_move_forward(Robot* robot) {
    robot->y++;
}

// Move the robot backward
void robot_move_backward(Robot* robot) {
    robot->y--;
}

// Turn the robot left
void robot_turn_left(Robot* robot) {
    robot->x--;
}

// Turn the robot right
void robot_turn_right(Robot* robot) {
    robot->x++;
}

// Print the robot's state
void robot_print_state(Robot* robot) {
    printf("Robot state: ");
    switch (robot->state) {
        case STOPPED:
            printf("STOPPED\n");
            break;
        case MOVING_FORWARD:
            printf("MOVING_FORWARD\n");
            break;
        case MOVING_BACKWARD:
            printf("MOVING_BACKWARD\n");
            break;
        case TURNING_LEFT:
            printf("TURNING_LEFT\n");
            break;
        case TURNING_RIGHT:
            printf("TURNING_RIGHT\n");
            break;
    }
}

// Get the robot's position
void robot_get_position(Robot* robot, int* x, int* y) {
    *x = robot->x;
    *y = robot->y;
}

// Set the robot's position
void robot_set_position(Robot* robot, int x, int y) {
    robot->x = x;
    robot->y = y;
}

// Main function
int main() {
    // Create a new robot
    Robot* robot = robot_new();

    // Move the robot forward
    robot_move_forward(robot);

    // Turn the robot right
    robot_turn_right(robot);

    // Move the robot backward
    robot_move_backward(robot);

    // Turn the robot left
    robot_turn_left(robot);

    // Print the robot's state
    robot_print_state(robot);

    // Get the robot's position
    int x, y;
    robot_get_position(robot, &x, &y);

    // Print the robot's position
    printf("Robot position: (%d, %d)\n", x, y);

    // Free the robot
    robot_free(robot);

    return 0;
}