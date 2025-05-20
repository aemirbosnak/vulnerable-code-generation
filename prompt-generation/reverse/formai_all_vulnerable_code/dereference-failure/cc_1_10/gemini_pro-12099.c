//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the robot's dimensions and joint limits
#define ROBOT_LENGTH 0.5
#define ROBOT_WIDTH 0.25
#define JOINT_MIN_ANGLE -M_PI/2
#define JOINT_MAX_ANGLE M_PI/2

// Define the robot's state
struct RobotState {
    double x;
    double y;
    double theta;
    double joint1_angle;
    double joint2_angle;
};

// Create a new robot state
struct RobotState* robot_state_new() {
    struct RobotState* state = malloc(sizeof(struct RobotState));
    state->x = 0.0;
    state->y = 0.0;
    state->theta = 0.0;
    state->joint1_angle = 0.0;
    state->joint2_angle = 0.0;
    return state;
}

// Free the robot state
void robot_state_free(struct RobotState* state) {
    free(state);
}

// Update the robot's state based on the given joint angles
void robot_state_update(struct RobotState* state, double joint1_angle, double joint2_angle) {
    // Check if the joint angles are within the limits
    if (joint1_angle < JOINT_MIN_ANGLE || joint1_angle > JOINT_MAX_ANGLE) {
        fprintf(stderr, "Invalid joint1 angle: %f\n", joint1_angle);
        exit(1);
    }
    if (joint2_angle < JOINT_MIN_ANGLE || joint2_angle > JOINT_MAX_ANGLE) {
        fprintf(stderr, "Invalid joint2 angle: %f\n", joint2_angle);
        exit(1);
    }

    // Update the joint angles
    state->joint1_angle = joint1_angle;
    state->joint2_angle = joint2_angle;

    // Compute the new position and orientation of the robot
    state->x += ROBOT_LENGTH * cos(state->theta) * (joint1_angle - state->joint1_angle);
    state->y += ROBOT_LENGTH * sin(state->theta) * (joint1_angle - state->joint1_angle);
    state->theta += joint2_angle - state->joint2_angle;
}

// Print the robot's state
void robot_state_print(struct RobotState* state) {
    printf("Robot state:\n");
    printf("  x: %f\n", state->x);
    printf("  y: %f\n", state->y);
    printf("  theta: %f\n", state->theta);
    printf("  joint1_angle: %f\n", state->joint1_angle);
    printf("  joint2_angle: %f\n", state->joint2_angle);
}

// Main function
int main() {
    // Create a new robot state
    struct RobotState* state = robot_state_new();

    // Update the robot's state
    robot_state_update(state, M_PI/4, M_PI/6);

    // Print the robot's state
    robot_state_print(state);

    // Free the robot state
    robot_state_free(state);

    return 0;
}