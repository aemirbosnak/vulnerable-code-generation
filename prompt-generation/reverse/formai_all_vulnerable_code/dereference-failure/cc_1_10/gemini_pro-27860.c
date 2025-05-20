//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int facing;
} Robot;

Robot* create_robot() {
    Robot* robot = malloc(sizeof(Robot));
    robot->x = 0;
    robot->y = 0;
    robot->facing = 0;
    return robot;
}

void destroy_robot(Robot* robot) {
    free(robot);
}

void move_robot(Robot* robot, char command) {
    switch (command) {
        case 'F':
            if (robot->facing == 0) {
                robot->y++;
            } else if (robot->facing == 1) {
                robot->x++;
            } else if (robot->facing == 2) {
                robot->y--;
            } else if (robot->facing == 3) {
                robot->x--;
            }
            break;
        case 'B':
            if (robot->facing == 0) {
                robot->y--;
            } else if (robot->facing == 1) {
                robot->x--;
            } else if (robot->facing == 2) {
                robot->y++;
            } else if (robot->facing == 3) {
                robot->x++;
            }
            break;
        case 'L':
            robot->facing--;
            if (robot->facing < 0) {
                robot->facing = 3;
            }
            break;
        case 'R':
            robot->facing++;
            if (robot->facing > 3) {
                robot->facing = 0;
            }
            break;
    }
}

int main() {
    Robot* robot = create_robot();
    char command;

    while ((command = getchar()) != 'Q') {
        move_robot(robot, command);
    }

    destroy_robot(robot);

    return 0;
}