//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Robot struct
typedef struct {
    int x;
    int y;
    int orientation; // 0: north, 1: east, 2: south, 3: west
} Robot;

// Map struct
typedef struct {
    int width;
    int height;
    int** cells; // 0: empty, 1: obstacle
} Map;

// Initialize robot
Robot* robot_init(int x, int y, int orientation) {
    Robot* robot = malloc(sizeof(Robot));
    robot->x = x;
    robot->y = y;
    robot->orientation = orientation;
    return robot;
}

// Free robot
void robot_free(Robot* robot) {
    free(robot);
}

// Initialize map
Map* map_init(int width, int height) {
    Map* map = malloc(sizeof(Map));
    map->width = width;
    map->height = height;
    map->cells = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        map->cells[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            map->cells[i][j] = 0;
        }
    }
    return map;
}

// Free map
void map_free(Map* map) {
    for (int i = 0; i < map->height; i++) {
        free(map->cells[i]);
    }
    free(map->cells);
    free(map);
}

// Print map
void map_print(Map* map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%d ", map->cells[i][j]);
        }
        printf("\n");
    }
}

// Check if robot can move in given direction
bool robot_can_move(Robot* robot, Map* map, int direction) {
    int new_x = robot->x;
    int new_y = robot->y;
    switch (direction) {
        case 0: // North
            new_y--;
            break;
        case 1: // East
            new_x++;
            break;
        case 2: // South
            new_y++;
            break;
        case 3: // West
            new_x--;
            break;
    }
    return (new_x >= 0 && new_x < map->width) && (new_y >= 0 && new_y < map->height) && (map->cells[new_y][new_x] == 0);
}

// Move robot in given direction
void robot_move(Robot* robot, Map* map, int direction) {
    if (!robot_can_move(robot, map, direction)) {
        return;
    }
    switch (direction) {
        case 0: // North
            robot->y--;
            break;
        case 1: // East
            robot->x++;
            break;
        case 2: // South
            robot->y++;
            break;
        case 3: // West
            robot->x--;
            break;
    }
}

// Rotate robot in given direction
void robot_rotate(Robot* robot, int direction) {
    robot->orientation = (robot->orientation + direction) % 4;
}

// Main function
int main() {
    // Create map
    Map* map = map_init(10, 10);

    // Create robot
    Robot* robot = robot_init(0, 0, 0);

    // Print initial map and robot position
    printf("Initial map:\n");
    map_print(map);
    printf("Robot position: (%d, %d, %d)\n", robot->x, robot->y, robot->orientation);

    // Move robot north
    robot_move(robot, map, 0);

    // Print updated map and robot position
    printf("\nMap after moving robot north:\n");
    map_print(map);
    printf("Robot position: (%d, %d, %d)\n", robot->x, robot->y, robot->orientation);

    // Rotate robot east
    robot_rotate(robot, 1);

    // Print updated map and robot position
    printf("\nMap after rotating robot east:\n");
    map_print(map);
    printf("Robot position: (%d, %d, %d)\n", robot->x, robot->y, robot->orientation);

    // Free robot and map
    robot_free(robot);
    map_free(map);

    return 0;
}