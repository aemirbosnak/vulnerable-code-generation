//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int x;
    int y;
    struct node* next;
} node;

node* create_node(int x, int y) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    return new_node;
}

void add_edge(node* start_node, node* end_node) {
    node* current_node = start_node;
    while (current_node->next!= NULL) {
        current_node = current_node->next;
    }
    current_node->next = end_node;
}

void generate_maze(node* start_node) {
    srand(time(NULL));
    int width = 20;
    int height = 20;
    int num_walls = rand() % (width * height) + 1;
    int num_empty_spaces = width * height - num_walls;
    int num_visited_spaces = 0;
    node* current_node = start_node;
    while (num_visited_spaces < num_empty_spaces) {
        int x = rand() % width;
        int y = rand() % height;
        if (is_wall(current_node, x, y)) {
            int dx = rand() % 4 - 2;
            int dy = rand() % 4 - 2;
            add_edge(current_node, create_node(current_node->x + dx, current_node->y + dy));
            add_edge(current_node->next, create_node(current_node->next->x + dx, current_node->next->y + dy));
        } else {
            add_edge(current_node, create_node(x, y));
            add_edge(current_node->next, create_node(current_node->next->x, current_node->next->y));
        }
        current_node = current_node->next;
        num_visited_spaces++;
    }
}

int is_wall(node* start_node, int x, int y) {
    node* current_node = start_node;
    while (current_node!= NULL) {
        if (current_node->x == x && current_node->y == y) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

int main() {
    node* start_node = create_node(0, 0);
    generate_maze(start_node);
    node* current_node = start_node;
    printf("Maze generated!\n");
    while (current_node!= NULL) {
        printf("%d %d\n", current_node->x, current_node->y);
        current_node = current_node->next;
    }
    return 0;
}