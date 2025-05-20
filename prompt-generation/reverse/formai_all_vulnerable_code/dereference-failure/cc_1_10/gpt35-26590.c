//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

typedef struct node {
    int x, y;
    int f, g, h;
    struct node* parent;
} Node;

// A* Pathfinding Algorithm
Node** AStar(int map[ROW][COL], Node* start, Node* goal);
int heuristic(Node* a, Node* b);
Node* get_node(int x, int y, Node* parent, Node* goal);
Node** get_neighbors(Node* node, int map[ROW][COL], Node* goal);
Node* get_min_f(Node** open_list, int size);
int get_index(Node** list, Node* node, int size);
bool node_exists(Node** list, Node* node, int size);
void print_path(Node* current);

int main() {
    // Example map
    int map[ROW][COL] = {
        {0, 0, 0, 0, 5},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 2}
    };
    Node* start = get_node(0, 0, NULL, NULL);
    Node* goal = get_node(4, 4, NULL, NULL);

    Node** path = AStar(map, start, goal);
    if (path) {
        printf("Path found!\n");
        print_path(path[0]);
    } else {
        printf("Path not found.\n");
    }

    return 0;
}

// A* Pathfinding Algorithm
Node** AStar(int map[ROW][COL], Node* start, Node* goal) {
    // First, we initialize two lists: open and closed.
    Node* open_list[ROW * COL] = {0};
    Node* closed_list[ROW * COL] = {0};
    int open_size = 0;
    int closed_size = 0;

    // Add the starting node to the open list.
    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    open_list[open_size++] = start;

    // Loop through the open list until we find the goal or run out of nodes.
    while (open_size > 0) {
        // Get the node with the lowest f score from the open list.
        Node* current = get_min_f(open_list, open_size--);
        // If we found the goal, reconstruct and return the path.
        if (current->x == goal->x && current->y == goal->y) {
            Node** path = malloc((closed_size + 1) * sizeof(Node*));
            int i = 0;
            for (Node* node = closed_list[closed_size - 1]; node; node = node->parent) {
                path[i++] = node;
            }
            return path;
        }
        // Move the current node from the open to the closed list.
        closed_list[closed_size++] = current;
        // Get the current node's neighbors.
        Node** neighbors = get_neighbors(current, map, goal);
        for (int i = 0; i < 4; i++) {
            Node* neighbor = neighbors[i];
            // Skip invalid neighbors and nodes on the closed list.
            if (!neighbor || node_exists(closed_list, neighbor, closed_size)) {
                continue;
            }
            // Calculate the g score for the neighbor.
            int new_g = current->g + 1;
            if (new_g < neighbor->g || !node_exists(open_list, neighbor, open_size)) {
                // Update the neighbor's g, h, f scores and parent node.
                neighbor->g = new_g;
                neighbor->h = heuristic(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
                if (!node_exists(open_list, neighbor, open_size)) {
                    // Add the neighbor to the open list.
                    open_list[open_size++] = neighbor;
                }
            }
        }
    }

    // If we got here, there is no path.
    return NULL;
}

// Euclidean Distance heuristic
int heuristic(Node* a, Node* b) {
    int dx = abs(a->x - b->x);
    int dy = abs(a->y - b->y);
    return (int) (10.0f * sqrtf(dx * dx + dy * dy));
}

// Returns a new Node.
Node* get_node(int x, int y, Node* parent, Node* goal) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = parent;
    return node;
}

// Returns the neighbors of a given Node.
Node** get_neighbors(Node* node, int map[ROW][COL], Node* goal) {
    Node** neighbors = malloc(4 * sizeof(Node*));
    neighbors[0] = node->x > 0 ? get_node(node->x - 1, node->y, NULL, goal) : NULL;
    neighbors[1] = node->x < ROW - 1 ? get_node(node->x + 1, node->y, NULL, goal) : NULL;
    neighbors[2] = node->y > 0 ? get_node(node->x, node->y - 1, NULL, goal) : NULL;
    neighbors[3] = node->y < COL - 1 ? get_node(node->x, node->y + 1, NULL, goal) : NULL;
    int i = 0;
    while (i < 4) {
        if (neighbors[i]) {
            if (map[neighbors[i]->x][neighbors[i]->y]) {
                free(neighbors[i]);
                neighbors[i] = NULL;
            } else {
                neighbors[i]->h = heuristic(neighbors[i], goal);
            }
        }
        i++;
    }
    return neighbors;
}

// Returns the Node with the lowest f score.
Node* get_min_f(Node** open_list, int size) {
    Node* min_f = open_list[0];
    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (open_list[i]->f < min_f->f) {
            min_f = open_list[i];
            min_index = i;
        }
    }
    // Remove the node with the lowest f score from the open list.
    open_list[min_index] = open_list[--size];
    return min_f;
}

// Returns the index of the given Node in the given list.
int get_index(Node** list, Node* node, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == node) {
            return i;
        }
    }
    return -1;
}

// Returns true if the given Node exists in the given list.
bool node_exists(Node** list, Node* node, int size) {
    return get_index(list, node, size) != -1;
}

// Prints the path from the starting to the goal node.
void print_path(Node* current) {
    if (current->parent) {
        print_path(current->parent);
    }
    printf("(%d, %d)\n", current->x, current->y);
}