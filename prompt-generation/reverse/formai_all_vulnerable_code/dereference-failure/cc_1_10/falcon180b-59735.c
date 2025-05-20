//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265
#define MAX_SPEED 100
#define MIN_SPEED 1
#define MAX_TURN_RATE 100
#define MIN_TURN_RATE 1

typedef struct {
    double x, y;
    double speed;
    double turn_rate;
    int direction;
} Robot;

Robot* create_robot(double x, double y, double speed, double turn_rate, int direction) {
    Robot* robot = (Robot*)malloc(sizeof(Robot));
    robot->x = x;
    robot->y = y;
    robot->speed = speed;
    robot->turn_rate = turn_rate;
    robot->direction = direction;
    return robot;
}

void destroy_robot(Robot* robot) {
    free(robot);
}

void move_robot(Robot* robot) {
    double dx = robot->speed * cos(robot->direction * PI / 180);
    double dy = robot->speed * sin(robot->direction * PI / 180);
    robot->x += dx;
    robot->y += dy;
}

void turn_robot(Robot* robot, double turn_angle) {
    robot->direction += turn_angle;
    if (robot->direction > 360) {
        robot->direction -= 360;
    } else if (robot->direction < 0) {
        robot->direction += 360;
    }
}

int main() {
    srand(time(NULL));
    Robot* robot = create_robot(0, 0, rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED, rand() % (MAX_TURN_RATE - MIN_TURN_RATE + 1) + MIN_TURN_RATE, rand() % 360);
    int running = 1;
    while (running) {
        system("clear");
        printf("Robot position: (%lf, %lf)\n", robot->x, robot->y);
        printf("Robot speed: %lf\n", robot->speed);
        printf("Robot turn rate: %lf\n", robot->turn_rate);
        printf("Robot direction: %d degrees\n", robot->direction);
        printf("Press 'q' to quit\n");
        char input = getchar();
        if (input == 'q' || input == 'Q') {
            running = 0;
        } else {
            double turn_angle = rand() % 360;
            turn_robot(robot, turn_angle);
            move_robot(robot);
        }
    }
    destroy_robot(robot);
    return 0;
}