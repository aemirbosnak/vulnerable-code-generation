//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Define constants
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 0

#define MAX_MOVES 100

// Function to generate random movements
int generate_random_move() {
    return rand() % 5; // returns values from 0 to 4 inclusive
}

// Structure to represent the robot's current state
typedef struct {
    int positionX;
    int positionY;
    char *name;
} Robot;

// Function to initialize the robot
Robot* create_robot(const char *name) {
    Robot *robot = (Robot *)malloc(sizeof(Robot));
    robot->positionX = 0;
    robot->positionY = 0;
    robot->name = strdup(name);
    return robot;
}

// Function to free robot's memory
void destroy_robot(Robot *robot) {
    free(robot->name);
    free(robot);
}

// Function to display robot's current position
void display_position(Robot *robot) {
    printf("%s is currently at position (%d, %d)\n", robot->name, robot->positionX, robot->positionY);
}

// Function to move the robot
void move_robot(Robot *robot, int direction) {
    switch (direction) {
        case FORWARD:
            robot->positionY += 1;
            break;
        case BACKWARD:
            robot->positionY -= 1;
            break;
        case LEFT:
            robot->positionX -= 1;
            break;
        case RIGHT:
            robot->positionX += 1;
            break;
        case STOP:
            // Stopping does nothing.
            break;
        default:
            printf("Invalid Move!\n");
    }
    display_position(robot);
}

// Function to simulate a series of random movements
void simulate_movements(Robot *robot) {
    for (int i = 0; i < MAX_MOVES; ++i) {
        int move = generate_random_move();
        switch (move) {
            case 0:
                printf("Moving Forward\n");
                move_robot(robot, FORWARD);
                break;
            case 1:
                printf("Moving Backward\n");
                move_robot(robot, BACKWARD);
                break;
            case 2:
                printf("Turning Left\n");
                move_robot(robot, LEFT);
                break;
            case 3:
                printf("Turning Right\n");
                move_robot(robot, RIGHT);
                break;
            case 4:
                printf("Stopping\n");
                move_robot(robot, STOP);
                break;
        }
        usleep(500000); // sleep for half a second
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    Robot *myRobot = create_robot("RoboStat");

    printf("Initiating robot movement simulation...\n");
    display_position(myRobot);
    
    simulate_movements(myRobot);

    printf("Simulation complete.\n");
    destroy_robot(myRobot);
    return 0;
}