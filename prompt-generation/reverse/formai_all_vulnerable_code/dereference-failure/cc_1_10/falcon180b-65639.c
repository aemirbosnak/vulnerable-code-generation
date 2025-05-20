//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MOVE_UP 'w'
#define MOVE_DOWN's'
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'

// Define the maze structure
typedef struct {
    int x, y;
    char wall;
} Maze;

// Define the robot structure
typedef struct {
    int x, y;
    char direction;
} Robot;

// Initialize the maze
void init_maze(Maze maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].wall = rand() % 2; // Randomly generate walls
        }
    }
}

// Print the maze
void print_maze(Maze maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j].wall) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Move the robot
void move_robot(Robot *robot, Maze maze[10][10], char direction) {
    int new_x = robot->x;
    int new_y = robot->y;

    switch (direction) {
        case MOVE_UP:
            new_y--;
            break;
        case MOVE_DOWN:
            new_y++;
            break;
        case MOVE_LEFT:
            new_x--;
            break;
        case MOVE_RIGHT:
            new_x++;
            break;
    }

    if (maze[new_x][new_y].wall) {
        // Hit a wall, do nothing
        return;
    }

    robot->x = new_x;
    robot->y = new_y;
    robot->direction = direction;
}

// Main function
int main() {
    srand(time(NULL));

    Maze maze[10][10];
    init_maze(maze);

    Robot robot;
    robot.x = 0;
    robot.y = 0;
    robot.direction = MOVE_RIGHT;

    while (true) {
        system("clear");
        print_maze(maze);
        printf("Robot at (%d, %d)\n", robot.x, robot.y);

        char input;
        scanf("%c", &input);

        switch (input) {
            case MOVE_UP:
                move_robot(&robot, maze, MOVE_UP);
                break;
            case MOVE_DOWN:
                move_robot(&robot, maze, MOVE_DOWN);
                break;
            case MOVE_LEFT:
                move_robot(&robot, maze, MOVE_LEFT);
                break;
            case MOVE_RIGHT:
                move_robot(&robot, maze, MOVE_RIGHT);
                break;
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}