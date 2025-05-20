//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row;
    int col;
    int f; // f = g + h
    int g; // cost to reach this node
    int h; // heuristic estimate

    struct Node* parent;
} Node;

typedef struct NodeList {
    Node* node;
    struct NodeList* next;
} NodeList;

Node* start; // starting node
Node* end; // ending node

int grid[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

NodeList* open_list; // nodes to be evaluated
NodeList* closed_list; // nodes already evaluated

bool is_valid(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }

    return grid[row][col] == 0; // 0 means it is a valid path
}

int heuristic(int row, int col) {
    int dx = abs(end->row - row);
    int dy = abs(end->col - col);

    return dx + dy; // Manhattan distance
}

void print_path(Node* node) {
    if (node == NULL) {
        return;
    }

    print_path(node->parent);
    printf("(%d, %d) -> ", node->row, node->col);
}

void add_to_open_list(Node* node) {
    NodeList* new_node = malloc(sizeof(NodeList));
    new_node->node = node;
    new_node->next = NULL;

    if (open_list == NULL) {
        open_list = new_node;
    } else {
        NodeList* current = open_list;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

void remove_from_open_list(Node* node) {
    if (open_list == NULL) {
        return;
    }

    if (open_list->node == node) {
        NodeList* temp = open_list;
        open_list = open_list->next;
        free(temp);
    } else {
        NodeList* current = open_list;
        while (current->next != NULL && current->next->node != node) {
        current = current->next;
    }

    if (current->next != NULL) {
        NodeList* temp = current->next;
        current->next = current->next->next;
        free(temp);
        }
    }
}

void add_to_closed_list(Node* node) {
    NodeList* new_node = malloc(sizeof(NodeList));
    new_node->node = node;
    new_node->next = NULL;

    if (closed_list == NULL) {
        closed_list = new_node;
    } else {
        NodeList* current = closed_list;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

bool is_in_open_list(int row, int col) {
    NodeList* current = open_list;
    while (current != NULL) {
        if (current->node->row == row && current->node->col == col) {
        return true;
        }

        current = current->next;
    }

    return false;
}

bool is_in_closed_list(int row, int col) {
    NodeList* current = closed_list;
    while (current != NULL) {
        if (current->node->row == row && current->node->col == col) {
        return true;
        }

        current = current->next;
    }

    return false;
}

Node* lowest_f_in_open_list() {
    if (open_list == NULL) {
        return NULL;
    }

    NodeList* current = open_list;
    Node* min_node = current->node;
    int min_f = min_node->f;

    while (current != NULL) {
        if (current->node->f < min_f) {
            min_node = current->node;
            min_f = min_node->f;
        }

        current = current->next;
    }

    return min_node;
}

void process_neighbour(Node* current, int row, int col, int cost) {
    if (!is_valid(row, col) || is_in_closed_list(row, col)) {
        return;
    }

    int new_g = current->g + cost;
    Node* neighbour = malloc(sizeof(Node));
    neighbour->row = row;
    neighbour->col = col;
    neighbour->g = new_g;
    neighbour->h = heuristic(row, col);
    neighbour->f = neighbour->g + neighbour->h;
    neighbour->parent = current;

    if (!is_in_open_list(row, col)) {
        add_to_open_list(neighbour);
    } else {
        NodeList* current = open_list;
        while (current != NULL) {
            if (current->node->row == row && current->node->col == col) {
                if (new_g < current->node->g) {
                    current->node->g = new_g;
                    current->node->f = current->node->g + current->node->h;
                    current->node->parent = current;
                }
            }

            current = current->next;
        }
    }
}

void find_path() {
    // initialize starting node
    start->g = 0;
    start->h = heuristic(start->row, start->col);
    start->f = start->g + start->h;
    start->parent = NULL;

    add_to_open_list(start);

    while (open_list != NULL) {
        Node* current = lowest_f_in_open_list();
        remove_from_open_list(current);
        add_to_closed_list(current);

        if (current == end) {
            print_path(current);
            return;
        }

        process_neighbour(current, current->row - 1, current->col, 1); // up
        process_neighbour(current, current->row + 1, current->col, 1); // down
        process_neighbour(current, current->row, current->col - 1, 1); // left
        process_neighbour(current, current->row, current->col + 1, 1); // right
        process_neighbour(current, current->row - 1, current->col - 1, 2); // up-left
        process_neighbour(current, current->row - 1, current->col + 1, 2); // up-right
        process_neighbour(current, current->row + 1, current->col - 1, 2); // down-left
        process_neighbour(current, current->row + 1, current->col + 1, 2); // down-right
    }

    printf("No path found\n");
}

int main() {
    // initialize start and end node
    start = malloc(sizeof(Node));
    start->row = 1;
    start->col = 1;
    end = malloc(sizeof(Node));
    end->row = 8;
    end->col = 8;

    find_path();

    return 0;
}