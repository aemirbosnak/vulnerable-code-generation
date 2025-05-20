//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

#define START_X 0
#define START_Y 0

#define GOAL_X 9
#define GOAL_Y 9

#define WALL '#'

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int g_score;
    int h_score;
    int f_score;
    struct Node *parent;
} Node;

typedef struct {
    Node *nodes[MAX_WIDTH][MAX_HEIGHT];
    int width;
    int height;
} Grid;

Node *create_node(Position position, int g_score, int h_score, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->position = position;
    node->g_score = g_score;
    node->h_score = h_score;
    node->f_score = g_score + h_score;
    node->parent = parent;
    return node;
}

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            grid->nodes[x][y] = NULL;
        }
    }

    return grid;
}

void destroy_grid(Grid *grid) {
    for (int x = 0; x < grid->width; x++) {
        for (int y = 0; y < grid->height; y++) {
            free(grid->nodes[x][y]);
        }
    }

    free(grid);
}

bool is_valid_position(Grid *grid, Position position) {
    return position.x >= 0 && position.x < grid->width && position.y >= 0 && position.y < grid->height && grid->nodes[position.x][position.y] == NULL;
}

int heuristic_cost_estimate(Position start, Position goal) {
    return abs(start.x - goal.x) + abs(start.y - goal.y);
}

Node *find_lowest_f_score_node(Grid *grid) {
    Node *lowest_f_score_node = NULL;

    for (int x = 0; x < grid->width; x++) {
        for (int y = 0; y < grid->height; y++) {
            Node *node = grid->nodes[x][y];

            if (node != NULL && (lowest_f_score_node == NULL || node->f_score < lowest_f_score_node->f_score)) {
                lowest_f_score_node = node;
            }
        }
    }

    return lowest_f_score_node;
}

bool is_goal_reached(Position position, Position goal) {
    return position.x == goal.x && position.y == goal.y;
}

void reconstruct_path(Grid *grid, Node *goal) {
    Node *current_node = goal;

    while (current_node != NULL) {
        grid->nodes[current_node->position.x][current_node->position.y] = current_node;
        current_node = current_node->parent;
    }
}

void print_grid(Grid *grid) {
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            Node *node = grid->nodes[x][y];

            if (node != NULL) {
                printf("%d", node->f_score);
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main() {
    Grid *grid = create_grid(MAX_WIDTH, MAX_HEIGHT);

    // Set the start and goal positions
    Position start = {START_X, START_Y};
    Position goal = {GOAL_X, GOAL_Y};

    // Set the walls
    grid->nodes[3][3] = create_node((Position){3, 3}, 0, 0, NULL);
    grid->nodes[4][3] = create_node((Position){4, 3}, 0, 0, NULL);
    grid->nodes[5][3] = create_node((Position){5, 3}, 0, 0, NULL);
    grid->nodes[6][3] = create_node((Position){6, 3}, 0, 0, NULL);

    // Initialize the start node
    Node *start_node = create_node(start, 0, heuristic_cost_estimate(start, goal), NULL);
    grid->nodes[start.x][start.y] = start_node;

    // Initialize the open set
    Node *open_set[MAX_WIDTH * MAX_HEIGHT];
    int open_set_size = 0;
    open_set[open_set_size++] = start_node;

    // Initialize the closed set
    Node *closed_set[MAX_WIDTH * MAX_HEIGHT];
    int closed_set_size = 0;

    // Main loop
    while (open_set_size > 0) {
        // Find the node with the lowest f_score
        Node *current_node = find_lowest_f_score_node(grid);

        // Remove the node from the open set
        int i;
        for (i = 0; i < open_set_size; i++) {
            if (open_set[i] == current_node) {
                break;
            }
        }

        open_set[i] = open_set[open_set_size - 1];
        open_set_size--;

        // Add the node to the closed set
        closed_set[closed_set_size++] = current_node;

        // Check if the goal has been reached
        if (is_goal_reached(current_node->position, goal)) {
            reconstruct_path(grid, current_node);
            print_grid(grid);
            break;
        }

        // Generate the successors of the current node
        Position successors[4] = {
            {current_node->position.x - 1, current_node->position.y},
            {current_node->position.x + 1, current_node->position.y},
            {current_node->position.x, current_node->position.y - 1},
            {current_node->position.x, current_node->position.y + 1}
        };

        for (i = 0; i < 4; i++) {
            Position successor = successors[i];

            if (is_valid_position(grid, successor)) {
                int tentative_g_score = current_node->g_score + 1;

                Node *successor_node = grid->nodes[successor.x][successor.y];

                if (successor_node == NULL || tentative_g_score < successor_node->g_score) {
                    successor_node = create_node(successor, tentative_g_score, heuristic_cost_estimate(successor, goal), current_node);
                    grid->nodes[successor.x][successor.y] = successor_node;

                    // Add the successor to the open set
                    open_set[open_set_size++] = successor_node;
                }
            }
        }
    }

    destroy_grid(grid);

    return 0;
}