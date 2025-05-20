//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the robot's state
typedef struct {
    int x;
    int y;
    int direction; // 0 = north, 1 = east, 2 = south, 3 = west
} Robot;

// Define the world the robot is moving in
typedef struct {
    int width;
    int height;
    int** grid; // 0 = empty, 1 = obstacle
} World;

// Function to create a new robot
Robot* create_robot(int x, int y, int direction) {
    Robot* robot = malloc(sizeof(Robot));
    robot->x = x;
    robot->y = y;
    robot->direction = direction;
    return robot;
}

// Function to create a new world
World* create_world(int width, int height) {
    World* world = malloc(sizeof(World));
    world->width = width;
    world->height = height;
    world->grid = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        world->grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            world->grid[i][j] = 0;
        }
    }
    return world;
}

// Function to move the robot forward one space
void move_forward(Robot* robot, World* world) {
    switch (robot->direction) {
        case 0: // North
            if (robot->y > 0 && world->grid[robot->y - 1][robot->x] == 0) {
                robot->y--;
            }
            break;
        case 1: // East
            if (robot->x < world->width - 1 && world->grid[robot->y][robot->x + 1] == 0) {
                robot->x++;
            }
            break;
        case 2: // South
            if (robot->y < world->height - 1 && world->grid[robot->y + 1][robot->x] == 0) {
                robot->y++;
            }
            break;
        case 3: // West
            if (robot->x > 0 && world->grid[robot->y][robot->x - 1] == 0) {
                robot->x--;
            }
            break;
    }
}

// Function to turn the robot left
void turn_left(Robot* robot) {
    robot->direction = (robot->direction + 3) % 4;
}

// Function to turn the robot right
void turn_right(Robot* robot) {
    robot->direction = (robot->direction + 1) % 4;
}

// Function to simulate the robot moving around the world
void simulate_robot(Robot* robot, World* world, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        // Get a random number between 0 and 3
        int random_number = rand() % 4;

        // Move the robot forward or turn it left or right based on the random number
        switch (random_number) {
            case 0: // Move forward
                move_forward(robot, world);
                break;
            case 1: // Turn left
                turn_left(robot);
                break;
            case 2: // Turn right
                turn_right(robot);
                break;
        }
    }
}

// Function to print the world
void print_world(World* world) {
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            printf("%d ", world->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new world
    World* world = create_world(10, 10);

    // Create a new robot
    Robot* robot = create_robot(0, 0, 0);

    // Simulate the robot moving around the world
    simulate_robot(robot, world, 100);

    // Print the world
    print_world(world);

    // Free the memory allocated for the world and the robot
    free(world->grid);
    free(world);
    free(robot);

    return 0;
}