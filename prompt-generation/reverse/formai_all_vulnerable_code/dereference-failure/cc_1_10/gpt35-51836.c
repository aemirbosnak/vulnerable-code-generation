//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define the size of the map
#define MAP_ROWS 10
#define MAP_COLS 10

// Define the possible movement directions
#define DIRS_COUNT 8
static const int DIRS[DIRS_COUNT][2] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, -1 }, { -1, -1 }, { 1, 1 }, { -1, 1 } };

// Define a structure for each position on the map
typedef struct {
    int row, col;
} Position;

// Define a structure for each node on the open or closed list
typedef struct {
    Position pos;
    int g_score, f_score;
    struct Node* parent;
} Node;

// Define the start and goal positions
static const Position START_POS = { 0, 0 };
static const Position GOAL_POS = { MAP_ROWS - 1, MAP_COLS - 1 };

// Create the open and closed lists
static Node* open_list[MAP_ROWS * MAP_COLS];
static Node* closed_list[MAP_ROWS * MAP_COLS];
static int open_list_count = 0;
static int closed_list_count = 0;

// Create the map (1 = blocked, 0 = unblocked)
static const int MAP[MAP_ROWS][MAP_COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 1, 1, 1, 0, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

// Define a function to calculate the Manhattan distance heuristic between two positions
static int manhattan_distance(Position pos1, Position pos2) {
    return abs(pos1.row - pos2.row) + abs(pos1.col - pos2.col);
}

// Define a function to check if a position is valid (i.e. within the map and not blocked)
static bool is_valid_position(Position pos) {
    if (pos.row < 0 || pos.col < 0 || pos.row >= MAP_ROWS || pos.col >= MAP_COLS) {
        return false;
    }
    return MAP[pos.row][pos.col] == 0;
}

// Define a function to check if a position is already on the open or closed list
static bool is_position_on_list(Position pos, Node* list[], int list_count) {
    for (int i = 0; i < list_count; i++) {
        if (list[i]->pos.row == pos.row && list[i]->pos.col == pos.col) {
            return true;
        }
    }
    return false;
}

// Define a function to get the node with the lowest f score from the open list
static Node* get_lowest_f_score_node() {
    Node* lowest_node = open_list[0];
    for (int i = 1; i < open_list_count; i++) {
        if (open_list[i]->f_score < lowest_node->f_score) {
            lowest_node = open_list[i];
        }
    }
    return lowest_node;
}

// Define the A* pathfinding function
static Node* find_path() {
    // Create the start node and add it to the open list
    Node* start_node = (Node*)malloc(sizeof(Node));
    start_node->pos = START_POS;
    start_node->g_score = 0;
    start_node->f_score = manhattan_distance(START_POS, GOAL_POS);
    start_node->parent = NULL;
    open_list[0] = start_node;
    open_list_count = 1;

    // Loop until the open list is empty or the goal is found
    while (open_list_count > 0) {
        // Get the node with the lowest f score from the open list
        Node* current_node = get_lowest_f_score_node();

        // If the goal has been found, return the current node
        if (current_node->pos.row == GOAL_POS.row && current_node->pos.col == GOAL_POS.col) {
            return current_node;
        }

        // Move the current node from the open to the closed list
        open_list_count--;
        closed_list[closed_list_count] = current_node;
        closed_list_count++;

        // Loop through all possible movement directions from the current node
        for (int i = 0; i < DIRS_COUNT; i++) {
            Position next_pos = {
                current_node->pos.row + DIRS[i][0],
                current_node->pos.col + DIRS[i][1]
            };

            // Skip this direction if the next position is not valid or is already on the closed list
            if (!is_valid_position(next_pos) || is_position_on_list(next_pos, closed_list, closed_list_count)) {
                continue;
            }

            // Calculate the tentative g score for the next node
            int tentative_g_score = current_node->g_score + abs(DIRS[i][0]) + abs(DIRS[i][1]);

            // If the next node is not on the open list, add it and calculate its f score
            if (!is_position_on_list(next_pos, open_list, open_list_count)) {
                Node* next_node = (Node*)malloc(sizeof(Node));
                next_node->pos = next_pos;
                next_node->g_score = tentative_g_score;
                next_node->f_score = tentative_g_score + manhattan_distance(next_pos, GOAL_POS);
                next_node->parent = current_node;
                open_list[open_list_count] = next_node;
                open_list_count++;
            }
            // If the node is already on the open list, update its g score and f score if necessary
            else {
                Node* next_node;
                for (int j = 0; j < open_list_count; j++) {
                    if (open_list[j]->pos.row == next_pos.row && open_list[j]->pos.col == next_pos.col) {
                        next_node = open_list[j];
                        break;
                    }
                }
                
                if (tentative_g_score >= next_node->g_score) {
                    continue;
                }
                
                next_node->g_score = tentative_g_score;
                next_node->f_score = tentative_g_score + manhattan_distance(next_pos, GOAL_POS);
                next_node->parent = current_node;
            }
        }
    }

    // If the goal was not found, return NULL
    return NULL;
}

// Define a function to print the final path from start to goal
static void print_path(Node* end_node) {
    if (end_node == NULL) {
        printf("No path found.\n");
        return;
    }

    int path_length = 0;
    Node* node = end_node;
    while (node != NULL) {
        path_length++;
        node = node->parent;
    }

    Position path[path_length];
    node = end_node;
    for (int i = 0; i < path_length; i++) {
        path[path_length - i - 1] = node->pos;
        node = node->parent;
    }

    printf("Path length: %d\n", path_length);
    printf("Path: ");
    for (int i = 0; i < path_length; i++) {
        printf("(%d,%d)", path[i].row, path[i].col);
        if (i < path_length - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// The main function
int main() {
    // Find the path from start to goal
    Node* end_node = find_path();

    // Print the final path
    print_path(end_node);

    return 0;
}