//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW_SIZE 10
#define COL_SIZE 10
#define MAX_NODES ROW_SIZE * COL_SIZE

typedef struct node {
    int x;
    int y;
    int f_cost;
    int g_cost;
    int h_cost;
    int is_obstacle;
    struct node *parent;
} Node;

Node *open_set[MAX_NODES];
Node *closed_set[MAX_NODES];
int open_set_count = 0;
int closed_set_count = 0;

Node *start_node;
Node *end_node;
Node *nodes[ROW_SIZE][COL_SIZE];

int euclidean_distance(Node *a, Node *b) {
    int x_distance = abs(a->x - b->x);
    int y_distance = abs(a->y - b->y);
    return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}

void mark_obstacle(Node *node) {
    node->is_obstacle = 1;
}

Node *create_node(int x, int y, int is_obstacle) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->is_obstacle = is_obstacle;
    node->parent = NULL;
    return node;
}

void initialize_nodes() {
    int i, j, k = 0;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            nodes[i][j] = create_node(i, j, 0);
        }
    }
    mark_obstacle(nodes[2][1]);
    mark_obstacle(nodes[2][2]);
    mark_obstacle(nodes[2][3]);
    mark_obstacle(nodes[2][4]);
    mark_obstacle(nodes[2][5]);
    mark_obstacle(nodes[2][6]);
    mark_obstacle(nodes[2][7]);
    mark_obstacle(nodes[4][3]);
    mark_obstacle(nodes[4][4]);
    mark_obstacle(nodes[4][5]);
    mark_obstacle(nodes[4][6]);
    mark_obstacle(nodes[6][2]);
    mark_obstacle(nodes[6][3]);
    mark_obstacle(nodes[6][4]);
    mark_obstacle(nodes[6][5]);
    mark_obstacle(nodes[6][6]);
    start_node = nodes[0][0];
    end_node = nodes[9][9];
}

void add_to_open_set(Node *node) {
    open_set[open_set_count++] = node;
}

int is_in_closed_set(Node *node) {
    int i;
    for (i = 0; i < closed_set_count; i++) {
        if (closed_set[i] == node) {
            return 1;
        }
    }
    return 0;
}

int is_in_open_set(Node *node) {
    int i;
    for (i = 0; i < open_set_count; i++) {
        if (open_set[i] == node) {
            return 1;
        }
    }
    return 0;
}

Node *get_node_with_minimum_f_cost() {
    Node *node = open_set[0];
    int i;
    for (i = 1; i < open_set_count; i++) {
        if (open_set[i]->f_cost < node->f_cost) {
            node = open_set[i];
        }
    }
    return node;
}

void remove_node_from_open_set(Node *node) {
    int i;
    for (i = 0; i < open_set_count; i++) {
        if (open_set[i] == node) {
            break;
        }
    }
    for (; i < open_set_count - 1; i++) {
        open_set[i] = open_set[i + 1];
    }
    open_set_count--;
}

void add_to_closed_set(Node *node) {
    closed_set[closed_set_count++] = node;
}

void print_path(Node *node) {
    if (node->parent != NULL) {
        print_path(node->parent);
    }
    printf("(%d, %d) ", node->x, node->y);
}

void find_path() {
    int i, tentative_g_cost, tentative_f_cost;
    Node *current_node;
    add_to_open_set(start_node);
    while (open_set_count > 0) {
        current_node = get_node_with_minimum_f_cost();
        if (current_node == end_node) {
            printf("Path found: ");
            print_path(end_node);
            printf("\n");
            return;
        }
        remove_node_from_open_set(current_node);
        add_to_closed_set(current_node);
        for (i = -1; i <= 1; i++) {
            int j;
            for (j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current_node->x + i;
                int y = current_node->y + j;
                if (x < 0 || x >= ROW_SIZE || y < 0 || y >= COL_SIZE) {
                    continue;
                }
                Node *neighbor_node = nodes[x][y];
                if (neighbor_node->is_obstacle || is_in_closed_set(neighbor_node)) {
                    continue;
                }
                tentative_g_cost = current_node->g_cost + euclidean_distance(current_node, neighbor_node);
                if (!is_in_open_set(neighbor_node)) {
                    add_to_open_set(neighbor_node);
                    tentative_f_cost = tentative_g_cost + euclidean_distance(neighbor_node, end_node);
                    neighbor_node->f_cost = tentative_f_cost;
                    neighbor_node->g_cost = tentative_g_cost;
                    neighbor_node->h_cost = euclidean_distance(neighbor_node, end_node);
                    neighbor_node->parent = current_node;
                } else {
                    if (tentative_g_cost < neighbor_node->g_cost) {
                        neighbor_node->g_cost = tentative_g_cost;
                        neighbor_node->f_cost = neighbor_node->g_cost + neighbor_node->h_cost;
                        neighbor_node->parent = current_node;
                    }
                }
            }
        }
    }
    printf("No path found\n");
}

int main() {
    initialize_nodes();
    find_path();
    return 0;
}