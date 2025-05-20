//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_LIST_SIZE 100

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position position;
    float g; // Cost from start to current node
    float h; // Heuristic cost from current to end node
    float f; // Total cost
    struct Node* parent;
} Node;

Node* astar(Node start, Node end, int grid[WIDTH][HEIGHT]);
float heuristic(Position a, Position b);
void reconstruct_path(Node* current);

int main() {
    int grid[WIDTH][HEIGHT] = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Node start = {{0, 0}, 0.0, 0.0, 0.0, NULL};
    Node end = {{9, 9}, 0.0, 0.0, 0.0, NULL};

    astar(start, end, grid);

    return 0;
}

Node* create_node(Position pos, float g, float h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->position = pos;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

float heuristic(Position a, Position b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

void reconstruct_path(Node* current) {
    while (current != NULL) {
        printf("(%d, %d) ", current->position.x, current->position.y);
        current = current->parent;
    }
    printf("\n");
}

bool is_valid(int grid[WIDTH][HEIGHT], Position pos) {
    return (pos.x >= 0 && pos.x < WIDTH && pos.y >= 0 && pos.y < HEIGHT && grid[pos.x][pos.y] == 0);
}

Node* astar(Node start, Node end, int grid[WIDTH][HEIGHT]) {
    Node* open_list[MAX_LIST_SIZE];
    Node* closed_list[MAX_LIST_SIZE];
    int open_count = 0, closed_count = 0;

    open_list[open_count++] = create_node(start.position, 0.0, heuristic(start.position, end.position), NULL);

    while (open_count > 0) {
        Node* current = open_list[0];
        int current_index = 0;

        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f < current->f) {
                current = open_list[i];
                current_index = i;
            }
        }

        if (current->position.x == end.position.x && current->position.y == end.position.y) {
            reconstruct_path(current);
            return current;
        }

        open_count--;
        closed_list[closed_count++] = current;
        open_list[current_index] = open_list[open_count];

        Position directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < 4; ++i) {
            Position new_pos = {current->position.x + directions[i].x, current->position.y + directions[i].y};

            if (is_valid(grid, new_pos)) {
                float g_new = current->g + 1;  
                float h_new = heuristic(new_pos, end.position);
                Node* neighbor = create_node(new_pos, g_new, h_new, current);

                bool already_in_closed = false;
                for (int j = 0; j < closed_count; ++j) {
                    if (closed_list[j]->position.x == neighbor->position.x && closed_list[j]->position.y == neighbor->position.y) {
                        already_in_closed = true;
                        break;
                    }
                }

                if (already_in_closed) {
                    free(neighbor);
                    continue;
                }

                bool in_open_list = false;
                for (int j = 0; j < open_count; ++j) {
                    if (open_list[j]->position.x == neighbor->position.x && open_list[j]->position.y == neighbor->position.y) {
                        in_open_list = true;
                        if (neighbor->g < open_list[j]->g) {
                            open_list[j]->g = neighbor->g;
                            open_list[j]->parent = current;
                        }
                        free(neighbor);
                        break;
                    }
                }

                if (!in_open_list) {
                    open_list[open_count++] = neighbor;
                }
            }
        }
    }

    return NULL;
}