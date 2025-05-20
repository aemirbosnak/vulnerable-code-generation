//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Robot struct
typedef struct {
    int x, y;  // Position
    int dx, dy;  // Velocity
    int r;  // Radius
} Robot;

// Obstacle struct
typedef struct {
    int x, y;  // Position
    int r;  // Radius
} Obstacle;

// World struct
typedef struct {
    int w, h;  // Width and height
    Robot robot;  // Robot
    Obstacle *obstacles;  // Array of obstacles
    int num_obstacles;  // Number of obstacles
} World;

// Create a new world
World *create_world(int w, int h) {
    World *world = (World *) malloc(sizeof(World));
    world->w = w;
    world->h = h;

    // Initialize the robot
    world->robot.x = w / 2;
    world->robot.y = h / 2;
    world->robot.dx = 0;
    world->robot.dy = 0;
    world->robot.r = 10;

    // Create an array of obstacles
    world->num_obstacles = 10;
    world->obstacles = (Obstacle *) malloc(sizeof(Obstacle) * world->num_obstacles);

    // Initialize the obstacles
    for (int i = 0; i < world->num_obstacles; i++) {
        world->obstacles[i].x = rand() % w;
        world->obstacles[i].y = rand() % h;
        world->obstacles[i].r = 10;
    }

    return world;
}

// Destroy a world
void destroy_world(World *world) {
    free(world->obstacles);
    free(world);
}

// Move the robot
void move_robot(World *world) {
    // Update the robot's position
    world->robot.x += world->robot.dx;
    world->robot.y += world->robot.dy;

    // Check if the robot has collided with any obstacles
    for (int i = 0; i < world->num_obstacles; i++) {
        Obstacle *obstacle = &world->obstacles[i];

        // Calculate the distance between the robot and the obstacle
        int dx = world->robot.x - obstacle->x;
        int dy = world->robot.y - obstacle->y;
        int dist = dx * dx + dy * dy;

        // Check if the robot has collided with the obstacle
        if (dist < (world->robot.r + obstacle->r) * (world->robot.r + obstacle->r)) {
            // Reverse the robot's velocity
            world->robot.dx = -world->robot.dx;
            world->robot.dy = -world->robot.dy;

            // Move the robot back to its previous position
            world->robot.x -= world->robot.dx;
            world->robot.y -= world->robot.dy;
        }
    }

    // Check if the robot has reached the edge of the world
    if (world->robot.x < 0 || world->robot.x > world->w) {
        // Reflect the robot's velocity
        world->robot.dx = -world->robot.dx;
    }

    if (world->robot.y < 0 || world->robot.y > world->h) {
        // Reflect the robot's velocity
        world->robot.dy = -world->robot.dy;
    }
}

// Draw the world
void draw_world(World *world) {
    // Clear the screen
    printf("\e[1;1H\e[2J");

    // Draw the robot
    printf("\e[31;40m");
    printf("@");

    // Draw the obstacles
    printf("\e[30;47m");
    for (int i = 0; i < world->num_obstacles; i++) {
        Obstacle *obstacle = &world->obstacles[i];
        printf("o");
    }

    // Reset the text color
    printf("\e[0m");
}

// Main function
int main() {
    // Create a world
    World *world = create_world(80, 40);

    // Start the game loop
    while (1) {
        // Move the robot
        move_robot(world);

        // Draw the world
        draw_world(world);

        // Check if the robot has won
        if (world->robot.x == world->w / 2 && world->robot.y == world->h / 2) {
            printf("You win!");
            break;
        }

        // Check if the robot has lost
        if (world->robot.x < 0 || world->robot.x > world->w ||
            world->robot.y < 0 || world->robot.y > world->h) {
            printf("You lose!");
            break;
        }

        // Sleep for a bit
        usleep(100000);
    }

    // Destroy the world
    destroy_world(world);

    return 0;
}