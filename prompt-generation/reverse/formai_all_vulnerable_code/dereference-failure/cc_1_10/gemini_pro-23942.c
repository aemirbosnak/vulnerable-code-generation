//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// Data types
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position* positions;
    int size;
} Route;

// Function prototypes
bool is_valid_move(Position position, int maze[MAZE_HEIGHT][MAZE_WIDTH]);
void add_position_to_route(Route* route, Position position);
void print_route(Route route);

// Main function
int main() {
    // Create the maze
    int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Initialize the starting position
    Position start_position = {1, 1};

    // Create a route to store the positions
    Route route;
    route.positions = malloc(sizeof(Position) * MAZE_HEIGHT * MAZE_WIDTH);
    route.size = 0;
    add_position_to_route(&route, start_position);

    // Find the exit
    while (route.positions[route.size - 1].x != MAZE_WIDTH - 2 || route.positions[route.size - 1].y != MAZE_HEIGHT - 2) {
        // Get the current position
        Position current_position = route.positions[route.size - 1];

        // Check if there is a valid move in any of the four directions
        bool valid_move_found = false;
        for (int i = 0; i < 4; i++) {
            Position new_position;
            switch (i) {
                case 0:
                    new_position.x = current_position.x - 1;
                    new_position.y = current_position.y;
                    break;
                case 1:
                    new_position.x = current_position.x + 1;
                    new_position.y = current_position.y;
                    break;
                case 2:
                    new_position.x = current_position.x;
                    new_position.y = current_position.y - 1;
                    break;
                case 3:
                    new_position.x = current_position.x;
                    new_position.y = current_position.y + 1;
                    break;
            }

            if (is_valid_move(new_position, maze)) {
                add_position_to_route(&route, new_position);
                valid_move_found = true;
                break;
            }
        }

        // If no valid move was found, backtrack
        if (!valid_move_found) {
            route.size--;
        }
    }

    // Print the route
    print_route(route);

    // Free the allocated memory
    free(route.positions);

    return 0;
}

// Checks if a position is valid (i.e. not a wall or already visited)
bool is_valid_move(Position position, int maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    return position.x >= 0 && position.x < MAZE_WIDTH && position.y >= 0 && position.y < MAZE_HEIGHT && maze[position.y][position.x] == 0;
}

// Adds a position to the route
void add_position_to_route(Route* route, Position position) {
    route->positions[route->size] = position;
    route->size++;
}

// Prints the route
void print_route(Route route) {
    for (int i = 0; i < route.size; i++) {
        printf("(%d, %d)\n", route.positions[i].x, route.positions[i].y);
    }
}