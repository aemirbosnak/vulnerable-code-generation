//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Robot movement control
enum robot_movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
};

// Robot position
struct robot_position {
    int x;
    int y;
    int angle;
};

// Robot object
struct robot {
    struct robot_position position;
    enum robot_movement movement;
};

// Create a new robot
struct robot *robot_create() {
    struct robot *robot = malloc(sizeof(struct robot));
    robot->position.x = 0;
    robot->position.y = 0;
    robot->position.angle = 0;
    robot->movement = STOP;
    return robot;
}

// Destroy a robot
void robot_destroy(struct robot *robot) {
    free(robot);
}

// Move the robot forward
void robot_move_forward(struct robot *robot) {
    robot->position.x += 1;
}

// Move the robot backward
void robot_move_backward(struct robot *robot) {
    robot->position.x -= 1;
}

// Turn the robot left
void robot_turn_left(struct robot *robot) {
    robot->position.angle -= 90;
}

// Turn the robot right
void robot_turn_right(struct robot *robot) {
    robot->position.angle += 90;
}

// Stop the robot
void robot_stop(struct robot *robot) {
    robot->movement = STOP;
}

// Print the robot's position
void robot_print_position(struct robot *robot) {
    printf("Robot position: (%d, %d, %d)\n", robot->position.x, robot->position.y, robot->position.angle);
}

// Main function
int main() {
    // Create a new robot
    struct robot *robot = robot_create();

    // Randomly move the robot around for 100 steps
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int movement = rand() % 5;
        switch (movement) {
            case FORWARD:
                robot_move_forward(robot);
                break;
            case BACKWARD:
                robot_move_backward(robot);
                break;
            case LEFT:
                robot_turn_left(robot);
                break;
            case RIGHT:
                robot_turn_right(robot);
                break;
            case STOP:
                robot_stop(robot);
                break;
        }

        // Print the robot's position
        robot_print_position(robot);
    }

    // Destroy the robot
    robot_destroy(robot);

    return 0;
}