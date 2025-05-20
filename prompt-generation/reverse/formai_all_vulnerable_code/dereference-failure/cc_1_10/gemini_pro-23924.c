//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_WIDTH  10
#define MAP_HEIGHT 10

typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node *parent;
} Node;

Node *start, *goal;
Node *map[MAP_WIDTH][MAP_HEIGHT];

int heuristic(Node *a, Node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

int calculate_g(Node *node) {
    return node->parent->g + 1;
}

int calculate_f(Node *node) {
    return node->g + node->h;
}

Node *get_lowest_f(Node **open_set) {
    Node *lowest_f = open_set[0];
    for (int i = 1; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        if (open_set[i]->f < lowest_f->f) {
            lowest_f = open_set[i];
        }
    }
    return lowest_f;
}

void remove_from_open_set(Node *node, Node **open_set) {
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        if (open_set[i] == node) {
            open_set[i] = open_set[MAP_WIDTH * MAP_HEIGHT - 1];
            open_set[MAP_WIDTH * MAP_HEIGHT - 1] = NULL;
            break;
        }
    }
}

void add_to_closed_set(Node *node, Node **closed_set) {
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        if (closed_set[i] == NULL) {
            closed_set[i] = node;
            break;
        }
    }
}

Node **find_path(Node *start, Node *goal) {
    Node *open_set[MAP_WIDTH * MAP_HEIGHT];
    Node *closed_set[MAP_WIDTH * MAP_HEIGHT];

    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        open_set[i] = NULL;
        closed_set[i] = NULL;
    }

    open_set[0] = start;

    while (open_set[0] != NULL) {
        Node *current = get_lowest_f(open_set);

        if (current == goal) {
            Node **path = malloc(sizeof(Node *) * MAP_WIDTH * MAP_HEIGHT);
            int path_length = 0;

            while (current != NULL) {
                path[path_length] = current;
                path_length++;
                current = current->parent;
            }

            return path;
        }

        remove_from_open_set(current, open_set);
        add_to_closed_set(current, closed_set);

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int x = current->x + i;
                int y = current->y + j;

                if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
                    continue;
                }

                if (map[x][y] == NULL) {
                    continue;
                }

                Node *neighbour = map[x][y];

                if (neighbour->parent != NULL && neighbour->parent == current) {
                    continue;
                }

                int g = calculate_g(neighbour);
                if (neighbour->parent == NULL || g < neighbour->g) {
                    neighbour->parent = current;
                    neighbour->g = g;
                    neighbour->h = heuristic(neighbour, goal);
                    neighbour->f = calculate_f(neighbour);

                    int already_in_open_set = 0;
                    for (int k = 0; k < MAP_WIDTH * MAP_HEIGHT; k++) {
                        if (open_set[k] == neighbour) {
                            already_in_open_set = 1;
                            break;
                        }
                    }

                    if (!already_in_open_set) {
                        for (int k = 0; k < MAP_WIDTH * MAP_HEIGHT; k++) {
                            if (open_set[k] == NULL) {
                                open_set[k] = neighbour;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return NULL;
}

int main() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = malloc(sizeof(Node));
            map[i][j]->x = i;
            map[i][j]->y = j;
            map[i][j]->g = 0;
            map[i][j]->h = 0;
            map[i][j]->f = 0;
            map[i][j]->parent = NULL;
        }
    }

    start = map[0][0];
    goal = map[MAP_WIDTH - 1][MAP_HEIGHT - 1];

    Node **path = find_path(start, goal);

    if (path == NULL) {
        printf("No path found.\n");
    } else {
        for (int i = 0; path[i] != NULL; i++) {
            printf("(%d, %d)\n", path[i]->x, path[i]->y);
        }
    }

    return 0;
}