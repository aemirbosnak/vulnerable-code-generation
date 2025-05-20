//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

int start_x = 0;
int start_y = 0;
int end_x = MAP_WIDTH - 1;
int end_y = MAP_HEIGHT - 1;

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point position;
    int g_score;
    int h_score;
    int f_score;
    struct Node* parent;
} Node;

int manhattan_distance(Point a, Point b) {
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

bool is_valid_location(int x, int y) {
    if(x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        return true;
    }
    return false;
}

bool is_occupied(int x, int y) {
    //...check if location is occupied on map
    return false;
}

bool is_valid_node(Node* node) {
    if(is_valid_location(node->position.x, node->position.y) && !is_occupied(node->position.x, node->position.y)) {
        return true;
    }
    return false;
}

Node* create_node(Point position, int g, int h, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->position = position;
    node->g_score = g;
    node->h_score = h;
    node->f_score = g + h;
    node->parent = parent;
    return node;
}

void expand_fringe(Node* current, Node** fringe, int* fringe_size, bool** closed_list) {
    // Expand node in four directions (left, right, up, down)
    int x = current->position.x;
    int y = current->position.y;
    Point new_position;

    new_position.x = x - 1;
    new_position.y = y;
    if(is_valid_location(new_position.x, new_position.y) && !closed_list[new_position.y][new_position.x]) {
        Node* node = create_node(new_position, current->g_score + 1, manhattan_distance(new_position, (Point){end_x, end_y}), current);
        fringe[*fringe_size] = node;
        (*fringe_size)++;
    }

    new_position.x = x + 1;
    new_position.y = y;
    if(is_valid_location(new_position.x, new_position.y) && !closed_list[new_position.y][new_position.x]) {
        Node* node = create_node(new_position, current->g_score + 1, manhattan_distance(new_position, (Point){end_x, end_y}), current);
        fringe[*fringe_size] = node;
        (*fringe_size)++;
    }

    new_position.x = x;
    new_position.y = y - 1;
    if(is_valid_location(new_position.x, new_position.y) && !closed_list[new_position.y][new_position.x]) {
        Node* node = create_node(new_position, current->g_score + 1, manhattan_distance(new_position, (Point){end_x, end_y}), current);
        fringe[*fringe_size] = node;
        (*fringe_size)++;
    }

    new_position.x = x;
    new_position.y = y + 1;
    if(is_valid_location(new_position.x, new_position.y) && !closed_list[new_position.y][new_position.x]) {
        Node* node = create_node(new_position, current->g_score + 1, manhattan_distance(new_position, (Point){end_x, end_y}), current);
        fringe[*fringe_size] = node;
        (*fringe_size)++;
    }
}

bool traverse_path(Node* end_node) {
    if(end_node == NULL) {
        return false;
    }
    printf("Path found! ");
    int step_count = 0;
    Node* node = end_node;
    while(node != NULL) {
        step_count++;
        printf("(%d, %d) ", node->position.x, node->position.y);
        node = node->parent;
    }
    printf("\nTotal steps: %d\n", step_count);
    return true;
}

bool a_star_search(Point start_position) {
    // Initialize data structures
    Node** fringe = malloc(sizeof(Node*) * 100);
    int fringe_size = 0;
    bool** closed_list = malloc(sizeof(bool*) * MAP_HEIGHT);
    for(int i = 0; i < MAP_HEIGHT; i++) {
        closed_list[i] = malloc(sizeof(bool) * MAP_WIDTH);
        for(int j = 0; j < MAP_WIDTH; j++) {
            closed_list[i][j] = false;
        }
    }

    // Create start node and put on fringe
    Node* start_node = create_node(start_position, 0, manhattan_distance(start_position, (Point){end_x, end_y}), NULL);
    fringe[fringe_size] = start_node;
    fringe_size++;

    while(fringe_size > 0) {

        // Find node on fringe with lowest f_score
        int lowest_f_score_index = 0;
        for(int i = 1; i < fringe_size; i++) {
            if(fringe[i]->f_score < fringe[lowest_f_score_index]->f_score) {
                lowest_f_score_index = i;
            }
        }
        Node* current = fringe[lowest_f_score_index];

        // If goal found, return true
        if(current->position.x == end_x && current->position.y == end_y) {
            return traverse_path(current);
        }

        // Remove current node from fringe and add to closed list
        for(int i = lowest_f_score_index; i < fringe_size - 1; i++) {
            fringe[i] = fringe[i + 1];
        }
        fringe_size--;
        closed_list[current->position.y][current->position.x] = true;

        // Expand fringe
        expand_fringe(current, fringe, &fringe_size, closed_list);
    }

    // Goal not found, return false
    return false;
}

int main() {
    Point start_position = {start_x, start_y};
    if(a_star_search(start_position)) {
        printf("Path found.\n");
    }
    else {
        printf("Path not found.\n");
    }
    return 0;
}