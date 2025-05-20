//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define OBSTACLE -1
#define EMPTY 0
#define VISITED 2
#define START 3
#define TARGET 4

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int size;
    int capacity;
} Path;

typedef struct {
    Point position;
    int g; // Cost from start
    int h; // Heuristic
    int f; // Total cost
    struct Node* parent;
} Node;

int grid[GRID_SIZE][GRID_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, -1, 0, -1, -1, -1, -1, 0},
    {0, -1, 0, 0, 0, 0, -1, 0, 0, 0},
    {0, -1, 0, -1, -1, -1, -1, -1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, -1, -1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, -1, -1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, -1, -1, -1, 0, 0, 0}
};

bool is_valid(Point p) {
    return (p.x >= 0 && p.x < GRID_SIZE && p.y >= 0 && p.y < GRID_SIZE && grid[p.x][p.y] != OBSTACLE);
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node* create_node(Point position, Node* parent, Point target) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->position = position;
    node->g = parent ? parent->g + 1 : 0; // g = distance from start node
    node->h = heuristic(position, target);
    node->f = node->g + node->h; // f = g + h
    node->parent = parent;
    return node;
}

Path find_path(Point start, Point target) {
    Path path;
    path.size = 0;
    path.capacity = 10;
    path.points = (Point*)malloc(sizeof(Point) * path.capacity);

    Node* open_set[GRID_SIZE * GRID_SIZE];
    int open_set_size = 0;

    Node* closed_set[GRID_SIZE * GRID_SIZE];
    int closed_set_size = 0;

    // Create start node
    Node* start_node = create_node(start, NULL, target);
    open_set[open_set_size++] = start_node;

    while (open_set_size > 0) {
        Node* current = open_set[0];
        int current_index = 0;

        // Find the node in open set with the lowest f value
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i]->f < current->f) {
                current = open_set[i];
                current_index = i;
            }
        }

        // If we reach the target, construct the path
        if (current->position.x == target.x && current->position.y == target.y) {
            Node* temp = current;
            while (temp != NULL) {
                if (path.size >= path.capacity) {
                    path.capacity *= 2;
                    path.points = (Point*)realloc(path.points, sizeof(Point) * path.capacity);
                }
                path.points[path.size++] = temp->position;
                temp = temp->parent;
            }

            // Reverse the path
            for (int i = 0; i < path.size / 2; i++) {
                Point temp = path.points[i];
                path.points[i] = path.points[path.size - i - 1];
                path.points[path.size - i - 1] = temp;
            }

            // Clean up
            for (int i = 0; i < open_set_size; i++) {
                free(open_set[i]);
            }
            for (int i = 0; i < closed_set_size; i++) {
                free(closed_set[i]);
            }
            return path;
        }

        // Move current node from open to closed set
        closed_set[closed_set_size++] = current;
        open_set[current_index] = open_set[--open_set_size];

        // Explore neighbors
        Point neighbors[4] = {
            {current->position.x - 1, current->position.y}, // Up
            {current->position.x + 1, current->position.y}, // Down
            {current->position.x, current->position.y - 1}, // Left
            {current->position.x, current->position.y + 1}  // Right
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (!is_valid(neighbor)) continue;

            bool in_closed_set = false;
            for (int j = 0; j < closed_set_size; j++) {
                if (closed_set[j]->position.x == neighbor.x && closed_set[j]->position.y == neighbor.y) {
                    in_closed_set = true;
                    break;
                }
            }

            if (in_closed_set) continue;

            // Check if neighbor is already in open set
            bool in_open_set = false;
            Node* neighbor_node = NULL;
            for (int j = 0; j < open_set_size; j++) {
                if (open_set[j]->position.x == neighbor.x && open_set[j]->position.y == neighbor.y) {
                    in_open_set = true;
                    neighbor_node = open_set[j];
                    break;
                }
            }

            if (!in_open_set) {
                // Create a new node for the neighbor
                neighbor_node = create_node(neighbor, current, target);
                open_set[open_set_size++] = neighbor_node;
            } else if (current->g + 1 < neighbor_node->g) {
                neighbor_node->g = current->g + 1;
                neighbor_node->f = neighbor_node->g + neighbor_node->h;
                neighbor_node->parent = current; // Update parent
            }
        }
    }

    // If we exit the loop without finding a path
    free(path.points);
    for (int i = 0; i < open_set_size; i++) {
        free(open_set[i]);
    }
    for (int i = 0; i < closed_set_size; i++) {
        free(closed_set[i]);
    }
    path.size = 0; // Indicate no path found
    return path;
}

void print_path(Path path) {
    if (path.size == 0) {
        printf("No path found!\n");
        return;
    }
    printf("Path found:\n");
    for (int i = 0; i < path.size; i++) {
        printf("(%d, %d) ", path.points[i].x, path.points[i].y);
    }
    printf("\n");
}

int main() {
    Point start = {0, 0}; // Starting point
    Point target = {9, 9}; // Target point
    Path path = find_path(start, target);
    
    print_path(path);

    free(path.points); // Clean up memory
    return 0;
}