//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// The map
char map[ROWS][COLS] = {
    {'S', '.', '.', '.', '.', '.', '.', '.', '.', 'G'},
    {'.', '#', '.', '.', '#', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '#', '.', '#', '.', '.', '.'},
    {'.', '#', '#', '.', '#', '.', '.', '.', '#', '.'},
    {'.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '#', '.', '#', '.', '.', '.', '.', '.'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.'},
    {'.', '.', '#', '.', '.', '.', '#', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '#', '.'},
};

// A node in the map
typedef struct Node {
    int row;
    int col;
    int f_cost;
    int g_cost;
    int h_cost;
    bool is_obstacle;
    struct Node* parent;
} Node;

// Get the node at the specified position on the map
Node* get_node(int row, int col) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->is_obstacle = (map[row][col] == '#');
    node->parent = NULL;
    return node;
}

// Calculate the h cost of a node
int calc_h_cost(Node* node, Node* goal) {
    return abs(node->row - goal->row) + abs(node->col - goal->col);
}

// Calculate the f cost of a node
void calc_f_cost(Node* node, Node* goal) {
    node->h_cost = calc_h_cost(node, goal);
    node->f_cost = node->g_cost + node->h_cost;
}

// Check if a node is valid
bool is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// Check if a node is an obstacle
bool is_obstacle(int row, int col) {
    return map[row][col] == '#';
}

// Check if a node is on the closed list
bool is_closed(Node* node, Node** closed_list, int closed_size) {
    for (int i = 0; i < closed_size; i++) {
        if (node->row == closed_list[i]->row && node->col == closed_list[i]->col) {
            return true;
        }
    }
    return false;
}

// Check if a node is on the open list
bool is_open(Node* node, Node** open_list, int open_size) {
    for (int i = 0; i < open_size; i++) {
        if (node->row == open_list[i]->row && node->col == open_list[i]->col) {
            return true;
        }
    }
    return false;
}

// Add a node to the open list
void add_to_open(Node* node, Node** open_list, int* open_size) {
    open_list[*open_size] = node;
    (*open_size)++;
}

// Remove a node from the open list
void remove_from_open(Node* node, Node** open_list, int* open_size) {
    for (int i = 0; i < *open_size; i++) {
        if (node->row == open_list[i]->row && node->col == open_list[i]->col) {
            open_list[i] = open_list[*open_size - 1];
            (*open_size)--;
            return;
        }
    }
}

// Add a node to the closed list
void add_to_closed(Node* node, Node** closed_list, int* closed_size) {
    closed_list[*closed_size] = node;
    (*closed_size)++;
}

// Find the path from the start node to the goal node
Node** find_path(Node* start, Node* goal) {
    Node** path = malloc(sizeof(Node*) * ROWS * COLS);
    int path_size = 0;

    Node* open_list[ROWS * COLS] = {NULL};
    int open_size = 0;

    Node* closed_list[ROWS * COLS] = {NULL};
    int closed_size = 0;

    add_to_open(start, open_list, &open_size);

    while (open_size > 0) {
        int min_f_index = 0;
        for (int i = 0; i < open_size; i++) {
            if (open_list[i]->f_cost < open_list[min_f_index]->f_cost) {
                min_f_index = i;
            }
        }

        Node* current = open_list[min_f_index];

        if (current->row == goal->row && current->col == goal->col) {
            Node* node = current;
            while (node->parent != NULL) {
                path[path_size++] = node;
                node = node->parent;
            }
            return path;
        }

        remove_from_open(current, open_list, &open_size);
        add_to_closed(current, closed_list, &closed_size);

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int row = current->row + i;
                int col = current->col + j;

                if (!is_valid(row, col)) {
                    continue;
                }

                if (is_obstacle(row, col)) {
                    continue;
                }

                Node* neighbor = get_node(row, col);

                if (is_closed(neighbor, closed_list, closed_size)) {
                    continue;
                }

                int tentative_g_cost = current->g_cost + 1;

                if (!is_open(neighbor, open_list, open_size)) {
                    add_to_open(neighbor, open_list, &open_size);
                } else if (tentative_g_cost >= neighbor->g_cost) {
                    continue;
                }

                neighbor->parent = current;
                neighbor->g_cost = tentative_g_cost;
                calc_f_cost(neighbor, goal);
            }
        }
    }

    return NULL;
}

int main() {
    Node* start = get_node(0, 0);
    Node* goal = get_node(0, 9);

    Node** path = find_path(start, goal);

    if (path != NULL) {
        for (int i = 0; i < ROWS * COLS; i++) {
            if (path[i] == NULL) {
                break;
            }
            printf("(%d,%d) ", path[i]->row, path[i]->col);
        }
    } else {
        printf("No path found.\n");
    }

    return 0;
}