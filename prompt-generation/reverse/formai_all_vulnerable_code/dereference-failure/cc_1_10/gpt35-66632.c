//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int x, y;
    int g, h, f;
    struct node* parent;
} node;

node* open_list[ROWS * COLS];
node* closed_list[ROWS * COLS];

int open_list_size = 0;
int closed_list_size = 0;

int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
};

node* create_node(int x, int y, int g, int h, node* parent) {
    node* n = (node*) malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->g = g;
    n->h = h;
    n->f = g + h;
    n->parent = parent;
    return n;
}

int is_valid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && map[x][y] == 0;
}

int is_in_list(node* n, node** list, int size) {
    for(int i = 0; i < size; i++) {
        if(n->x == list[i]->x && n->y == list[i]->y) {
            return 1;
        }
    }
    return 0;
}

int get_distance(int x1, int y1, int x2, int y2) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return (int) sqrt(dx * dx + dy * dy);
}

node* get_lowest_f() {
    node* lowest = open_list[0];
    for(int i = 1; i < open_list_size; i++) {
        if(open_list[i]->f < lowest->f) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

void add_to_open_list(node* n) {
    open_list[open_list_size++] = n;
}

void remove_from_open_list(node* n) {
    for(int i = 0; i < open_list_size; i++) {
        if(n->x == open_list[i]->x && n->y == open_list[i]->y) {
            // shift all elements after i to the left by one
            for(int j = i; j < open_list_size - 1; j++) {
                open_list[j] = open_list[j + 1];
            }
            open_list_size--;
            return;
        }
    }
}

void add_to_closed_list(node* n) {
    closed_list[closed_list_size++] = n;
}

node* get_neighbour(node* current, int dx, int dy) {
    int x = current->x + dx;
    int y = current->y + dy;
    if(is_valid(x, y)) {
        int g = current->g + get_distance(current->x, current->y, x, y);
        int h = get_distance(x, y, ROWS - 1, COLS - 1);
        return create_node(x, y, g, h, current);
    }
    return NULL;
}

void reconstruct_path(node* n) {
    if(n->parent) {
        reconstruct_path(n->parent);
    }
    printf("(%d, %d) ", n->x, n->y);
}

void find_path() {
    node* start_node = create_node(0, 0, 0, 0, NULL);
    add_to_open_list(start_node);

    while(open_list_size > 0) {
        node* current_node = get_lowest_f();
        remove_from_open_list(current_node);
        add_to_closed_list(current_node);

        if(current_node->x == ROWS - 1 && current_node->y == COLS - 1) {
            reconstruct_path(current_node);
            return;
        }

        node* neighbours[8];
        neighbours[0] = get_neighbour(current_node, -1, -1);
        neighbours[1] = get_neighbour(current_node, -1, 0);
        neighbours[2] = get_neighbour(current_node, -1, 1);
        neighbours[3] = get_neighbour(current_node, 0, -1);
        neighbours[4] = get_neighbour(current_node, 0, 1);
        neighbours[5] = get_neighbour(current_node, 1, -1);
        neighbours[6] = get_neighbour(current_node, 1, 0);
        neighbours[7] = get_neighbour(current_node, 1, 1);

        for(int i = 0; i < 8; i++) {
            if(neighbours[i] && !is_in_list(neighbours[i], closed_list, closed_list_size)) {
                int in_open_list = is_in_list(neighbours[i], open_list, open_list_size);
                if(in_open_list) {
                    int new_g = current_node->g + get_distance(current_node->x, current_node->y, neighbours[i]->x, neighbours[i]->y);
                    if(new_g < neighbours[i]->g) {
                        neighbours[i]->g = new_g;
                        neighbours[i]->f = neighbours[i]->g + neighbours[i]->h;
                        neighbours[i]->parent = current_node;
                    }
                } else {
                    add_to_open_list(neighbours[i]);
                }
            }
        }
    }
}

int main() {
    find_path();
    return 0;
}