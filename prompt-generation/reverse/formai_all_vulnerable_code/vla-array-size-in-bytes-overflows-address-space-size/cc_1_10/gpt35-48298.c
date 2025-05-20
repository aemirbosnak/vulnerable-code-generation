//FormAI DATASET v1.0 Category: Robot movement control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 1000
#define MAX_SPEED 10
#define MIN_SPEED 1

struct Position {
    double x;
    double y;
};

struct Robot {
    int id;
    struct Position currentPosition;
    struct Position targetPosition;
    int speed;
};

void initializeRobot(struct Robot *robot, int id, double x, double y) {
    robot->id = id;
    robot->currentPosition.x = x;
    robot->currentPosition.y = y;
    robot->targetPosition.x = rand() % 500 + 1;
    robot->targetPosition.y = rand() % 500 + 1;
    robot->speed = rand() % MAX_SPEED + MIN_SPEED;
}

void updateRobotPosition(struct Robot *robot) {
    double xDistance = robot->targetPosition.x - robot->currentPosition.x;
    double yDistance = robot->targetPosition.y - robot->currentPosition.y;
    double distance = sqrt(xDistance * xDistance + yDistance * yDistance);
    if (distance < robot->speed) {
        robot->currentPosition.x = robot->targetPosition.x;
        robot->currentPosition.y = robot->targetPosition.y;
        robot->targetPosition.x = rand() % 500 + 1;
        robot->targetPosition.y = rand() % 500 + 1;
        robot->speed = rand() % MAX_SPEED + MIN_SPEED;
    }
    else {
        robot->currentPosition.x += xDistance / distance * robot->speed;
        robot->currentPosition.y += yDistance / distance * robot->speed;
    }
}

int main() {
    srand(time(NULL));
    int numRobots;
    printf("Enter the number of robots: ");
    scanf("%d", &numRobots);
    struct Robot robots[numRobots];
    for (int i = 0; i < numRobots; i++) {
        initializeRobot(&robots[i], i, rand() % 500 + 1, rand() % 500 + 1);
    }
    int steps = 0;
    while (steps < MAX_STEPS) {
        for (int i = 0; i < numRobots; i++) {
            updateRobotPosition(&robots[i]);
            printf("Robot %d: (%.2lf, %.2lf)\n", robots[i].id, 
                                                    robots[i].currentPosition.x, 
                                                    robots[i].currentPosition.y);
        }
        steps++;
    }
    return 0;
}