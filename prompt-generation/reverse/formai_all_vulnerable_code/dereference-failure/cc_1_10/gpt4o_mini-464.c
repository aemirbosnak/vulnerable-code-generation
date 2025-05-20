//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265
#define MAX_SPEED 10.0
#define MAX_TURN_ANGLE 45.0

typedef struct {
    double x;
    double y;
    double orientation;  // in degrees
} Robot;

void init_robot(Robot *robot) {
    robot->x = 0.0;
    robot->y = 0.0;
    robot->orientation = 0.0;  // facing up (0 degrees)
}

void update_position(Robot *robot, double speed, double duration) {
    double radian_orientation = robot->orientation * (PI / 180.0);
    robot->x += speed * duration * cos(radian_orientation);
    robot->y += speed * duration * sin(radian_orientation);
}

void turn(Robot *robot, double angle) {
    robot->orientation += angle;
    if (robot->orientation >= 360.0) {
        robot->orientation -= 360.0;
    } else if (robot->orientation < 0) {
        robot->orientation += 360.0;
    }
}

void print_robot_status(Robot *robot) {
    printf("Robot Position: (%.2f, %.2f), Orientation: %.2f degrees\n", 
           robot->x, robot->y, robot->orientation);
}

double calculate_distance(Robot *a, Robot *b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

void move_in_square(Robot *robot, double side_length) {
    for (int i = 0; i < 4; i++) {
        update_position(robot, MAX_SPEED, side_length / MAX_SPEED);
        print_robot_status(robot);
        turn(robot, MAX_TURN_ANGLE);
    }
}

void move_in_circle(Robot *robot, double radius, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        update_position(robot, MAX_SPEED, (2 * PI * radius) / (MAX_SPEED * num_steps));
        turn(robot, (360.0 / num_steps));
        print_robot_status(robot);
    }
}

int main() {
    Robot *myRobot = malloc(sizeof(Robot));
    init_robot(myRobot);

    printf("Initiating Robot Movement...\n");
    print_robot_status(myRobot);

    printf("Moving in a square...\n");
    move_in_square(myRobot, 20.0);

    printf("Returning to Origin...\n");
    turn(myRobot, -90.0); // Turn to face start
    printf("Turning to face the origin...\n");
    move_in_square(myRobot, 0.0);  // Move back to the original point (0,0)
    
    printf("Moving in a circle...\n");
    init_robot(myRobot);
    move_in_circle(myRobot, 10.0, 36); // Circle with a radius of 10 units

    printf("Final Robot Status:\n");
    print_robot_status(myRobot);

    free(myRobot);
    return 0;
}