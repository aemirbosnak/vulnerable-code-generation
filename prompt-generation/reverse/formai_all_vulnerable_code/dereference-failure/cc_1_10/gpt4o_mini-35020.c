//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node *parent;
} Node;

Node *open_list[MAX_NODES];
Node *closed_list[MAX_NODES];
int open_list_count = 0;
int closed_list_count = 0;

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node *create_node(Point position, Node *parent, int g_cost) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->position = position;
    node->g_cost = g_cost;
    node->h_cost = heuristic(position, (Point){WIDTH - 1, HEIGHT - 1});
    node->f_cost = node->g_cost + node->h_cost;
    node->parent = parent;
    return node;
}

bool contains(Point point, Node **list, int count) {
    for (int i = 0; i < count; i++) {
        if (list[i]->position.x == point.x && list[i]->position.y == point.y) {
            return true;
        }
    }
    return false;
}

void add_to_open_list(Node *node) {
    open_list[open_list_count++] = node;
}

void add_to_closed_list(Node *node) {
    closed_list[closed_list_count++] = node;
}

Node *get_lowest_f_cost_node() {
    Node *lowest = open_list[0];
    for (int i = 1; i < open_list_count; i++) {
        if (open_list[i]->f_cost < lowest->f_cost) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

bool is_valid(Point point) {
    return point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT;
}

Point directions[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

void a_star() {
    Point start = {0, 0};
    Node *start_node = create_node(start, NULL, 0);
    add_to_open_list(start_node);

    while (open_list_count > 0) {
        Node *current_node = get_lowest_f_cost_node();

        if (current_node->position.x == WIDTH - 1 && current_node->position.y == HEIGHT - 1) {
            printf("Path found:\n");
            Node *temp = current_node;
            while (temp) {
                printf("(%d, %d) ", temp->position.x, temp->position.y);
                temp = temp->parent;
            }
            printf("\n");
            return;
        }

        for (int i = 0; i < 4; i++) {
            Point neighbor_pos = {current_node->position.x + directions[i].x, current_node->position.y + directions[i].y};

            if (is_valid(neighbor_pos) && !contains(neighbor_pos, closed_list, closed_list_count)) {
                int new_g_cost = current_node->g_cost + 1;
                Node *neighbor_node = create_node(neighbor_pos, current_node, new_g_cost);

                if (!contains(neighbor_pos, open_list, open_list_count)) {
                    add_to_open_list(neighbor_node);
                } else {
                    for (int j = 0; j < open_list_count; j++) {
                        if (open_list[j]->position.x == neighbor_node->position.x && open_list[j]->position.y == neighbor_node->position.y) {
                            if (open_list[j]->g_cost > new_g_cost) {
                                open_list[j]->g_cost = new_g_cost;
                                open_list[j]->parent = current_node;
                                open_list[j]->f_cost = new_g_cost + open_list[j]->h_cost;
                            }
                            free(neighbor_node);
                            break;
                        }
                    }
                }
            } 
        }

        add_to_closed_list(current_node);
        for (int i = 0; i < open_list_count; i++) {
            if (open_list[i] == current_node) {
                // Shift remaining elements down
                for (int j = i; j < open_list_count - 1; j++) {
                    open_list[j] = open_list[j + 1];
                }
                open_list_count--;
                break;
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    printf("A* Pathfinding Algorithm Example:\n");
    a_star();
    return 0;
}