//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100

#define START_X 0
#define START_Y 0
#define GOAL_X 99
#define GOAL_Y 99

typedef struct {
    int x;
    int y;
    int g_score;
    int h_score;
    int f_score;
    struct Node* parent;
} Node;

Node* map[MAP_WIDTH][MAP_HEIGHT];
Node* open_set[MAP_WIDTH * MAP_HEIGHT];
Node* closed_set[MAP_WIDTH * MAP_HEIGHT];

int open_set_size = 0;
int closed_set_size = 0;

pthread_mutex_t open_set_lock;
pthread_mutex_t closed_set_lock;

int heuristic(Node* node) {
    return abs(node->x - GOAL_X) + abs(node->y - GOAL_Y);
}

void add_to_open_set(Node* node) {
    pthread_mutex_lock(&open_set_lock);
    open_set[open_set_size++] = node;
    pthread_mutex_unlock(&open_set_lock);
}

void remove_from_open_set(Node* node) {
    pthread_mutex_lock(&open_set_lock);
    for (int i = 0; i < open_set_size; i++) {
        if (open_set[i] == node) {
            open_set[i] = open_set[open_set_size - 1];
            open_set_size--;
            break;
        }
    }
    pthread_mutex_unlock(&open_set_lock);
}

void add_to_closed_set(Node* node) {
    pthread_mutex_lock(&closed_set_lock);
    closed_set[closed_set_size++] = node;
    pthread_mutex_unlock(&closed_set_lock);
}

Node* get_lowest_f_score_node() {
    Node* lowest_f_score_node = NULL;
    int lowest_f_score = INT32_MAX;

    pthread_mutex_lock(&open_set_lock);
    for (int i = 0; i < open_set_size; i++) {
        Node* node = open_set[i];
        if (node->f_score < lowest_f_score) {
            lowest_f_score = node->f_score;
            lowest_f_score_node = node;
        }
    }
    pthread_mutex_unlock(&open_set_lock);

    return lowest_f_score_node;
}

Node* reconstruct_path(Node* goal_node) {
    Node* path = goal_node;

    while (path->parent != NULL) {
        path = path->parent;
    }

    return path;
}

void print_path(Node* path) {
    while (path != NULL) {
        printf("(%d, %d)\n", path->x, path->y);
        path = path->parent;
    }
}

int main() {
    pthread_mutex_init(&open_set_lock, NULL);
    pthread_mutex_init(&closed_set_lock, NULL);

    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = (Node*)malloc(sizeof(Node));
            map[i][j]->x = i;
            map[i][j]->y = j;
            map[i][j]->g_score = INT32_MAX;
            map[i][j]->h_score = heuristic(map[i][j]);
            map[i][j]->f_score = map[i][j]->g_score + map[i][j]->h_score;
            map[i][j]->parent = NULL;
        }
    }

    map[START_X][START_Y]->g_score = 0;
    map[START_X][START_Y]->f_score = map[START_X][START_Y]->h_score;

    add_to_open_set(map[START_X][START_Y]);

    while (open_set_size > 0) {
        Node* current_node = get_lowest_f_score_node();
        remove_from_open_set(current_node);
        add_to_closed_set(current_node);

        if (current_node == map[GOAL_X][GOAL_Y]) {
            Node* path = reconstruct_path(current_node);
            print_path(path);
            break;
        }

        int neighbors[8][2] = {
            {0, -1}, {1, -1}, {1, 0}, {1, 1},
            {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
        };

        for (int i = 0; i < 8; i++) {
            int neighbor_x = current_node->x + neighbors[i][0];
            int neighbor_y = current_node->y + neighbors[i][1];

            if (neighbor_x < 0 || neighbor_x >= MAP_WIDTH || neighbor_y < 0 || neighbor_y >= MAP_HEIGHT) {
                continue;
            }

            Node* neighbor = map[neighbor_x][neighbor_y];

            if (neighbor->g_score == INT32_MAX) {
                neighbor->g_score = current_node->g_score + 1;
                neighbor->h_score = heuristic(neighbor);
                neighbor->f_score = neighbor->g_score + neighbor->h_score;
                neighbor->parent = current_node;

                add_to_open_set(neighbor);
            } else if (neighbor->g_score > current_node->g_score + 1) {
                neighbor->g_score = current_node->g_score + 1;
                neighbor->f_score = neighbor->g_score + neighbor->h_score;
                neighbor->parent = current_node;
            }
        }
    }

    pthread_mutex_destroy(&open_set_lock);
    pthread_mutex_destroy(&closed_set_lock);

    return 0;
}