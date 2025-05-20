//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <math.h>

typedef struct Node {
    int x, y;
    int f, g, h;
    struct Node* parent;
} Node;

// calculate the manhattan distance between two nodes
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// check if a node is a valid path position
int is_valid(int x, int y, int map[][10], int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return 0;
    }
    return map[y][x] != 1;
}

// get the best node from the open list
Node* get_best_node(Node* open_list[], int list_size) {
    Node* best_node = NULL;
    int best_f = 0x7fffffff;
    for (int i = 0; i < list_size; i++) {
        Node* node = open_list[i];
        if (node->f < best_f) {
            best_f = node->f;
            best_node = node;
        }
    }
    return best_node;
}

// find a path using the A* algorithm
Node* find_path(int start_x, int start_y, int end_x, int end_y, int map[][10], int width, int height) {
    // initialize the start node
    Node* start_node = (Node*)malloc(sizeof(Node));
    start_node->x = start_x;
    start_node->y = start_y;
    start_node->g = 0;
    start_node->h = manhattan_distance(start_x, start_y, end_x, end_y);
    start_node->f = start_node->g + start_node->h;
    start_node->parent = NULL;
    
    // create the open and closed lists
    Node* open_list[width * height];
    int open_size = 0;
    Node* closed_list[width * height];
    int closed_size = 0;
    
    // add the start node to the open list
    open_list[open_size++] = start_node;
    
    // find the path
    while (open_size > 0) {
        Node* current_node = get_best_node(open_list, open_size);
        if (current_node->x == end_x && current_node->y == end_y) {
            return current_node;
        }
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) {
                    continue;
                }
                int new_x = current_node->x + x;
                int new_y = current_node->y + y;
                if (!is_valid(new_x, new_y, map, width, height)) {
                    continue;
                }
                Node* neighbor = (Node*)malloc(sizeof(Node));
                neighbor->x = new_x;
                neighbor->y = new_y;
                neighbor->g = current_node->g + 1;
                neighbor->h = manhattan_distance(new_x, new_y, end_x, end_y);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current_node;
                int found_in_open = 0, found_in_closed = 0;
                for (int i = 0; i < open_size; i++) {
                    if (open_list[i]->x == neighbor->x && open_list[i]->y == neighbor->y) {
                        found_in_open = 1;
                        break;
                    }
                }
                for (int i = 0; i < closed_size; i++) {
                    if (closed_list[i]->x == neighbor->x && closed_list[i]->y == neighbor->y) {
                        found_in_closed = 1;
                        break;
                    }
                }
                if (!found_in_open && !found_in_closed) {
                    open_list[open_size++] = neighbor;
                } else if (found_in_open && neighbor->f < current_node->f) {
                    for (int i = 0; i < open_size; i++) {
                        if (open_list[i]->x == neighbor->x && open_list[i]->y == neighbor->y) {
                            open_list[i]->f = neighbor->f;
                            open_list[i]->g = neighbor->g;
                            open_list[i]->h = neighbor->h;
                            open_list[i]->parent = current_node;
                            break;
                        }
                    }
                } else if (found_in_closed && neighbor->f < current_node->f) {
                    for (int i = 0; i < closed_size; i++) {
                        if (closed_list[i]->x == neighbor->x && closed_list[i]->y == neighbor->y) {
                            closed_list[i]->f = neighbor->f;
                            closed_list[i]->g = neighbor->g;
                            closed_list[i]->h = neighbor->h;
                            closed_list[i]->parent = current_node;
                            open_list[open_size++] = closed_list[i];
                            for (int j = i; j < closed_size - 1; j++) {
                                closed_list[j] = closed_list[j + 1];
                            }
                            closed_size--;
                            break;
                        }
                    }
                }
            }
        }
        open_size--;
        closed_list[closed_size++] = current_node;
    }
    return NULL;
}

int main() {
    int map[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Node* path = find_path(0, 0, 9, 9, map, 10, 10);
    while (path != NULL) {
        printf("(%d, %d)\n", path->x, path->y);
        path = path->parent;
    }
    return 0;
}