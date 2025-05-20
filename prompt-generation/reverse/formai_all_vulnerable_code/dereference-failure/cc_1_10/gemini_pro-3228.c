//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
    int x, y;
    int g_score, h_score, f_score;
    struct Node *parent;
} Node;

Node **initializeGrid(int width, int height) {
    Node **grid = malloc(sizeof(Node *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(Node) * width);
        for (int j = 0; j < width; j++) {
            grid[i][j].x = j;
            grid[i][j].y = i;
            grid[i][j].g_score = INT_MAX;
            grid[i][j].h_score = 0;
            grid[i][j].f_score = INT_MAX;
            grid[i][j].parent = NULL;
        }
    }
    return grid;
}

void freeGrid(Node **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
}

int calculateHeuristic(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

int calculateGScore(Node *node, Node *parent) {
    return parent->g_score + 1;
}

int calculateFScore(Node *node, Node *goal) {
    return node->g_score + calculateHeuristic(node, goal);
}

Node *getLowestFScoreNode(Node **grid, int width, int height) {
    Node *lowest = NULL;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].f_score < lowest->f_score) {
                lowest = &grid[i][j];
            }
        }
    }
    return lowest;
}

int isGoalNode(Node *node, Node *goal) {
    return node->x == goal->x && node->y == goal->y;
}

void reconstructPath(Node **grid, Node *goal) {
    Node *current = goal;
    while (current != NULL) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }
}

int main() {
    Node **grid = initializeGrid(WIDTH, HEIGHT);

    Node start = { .x = 0, .y = 0 };
    Node goal = { .x = WIDTH - 1, .y = HEIGHT - 1 };

    grid[start.y][start.x].g_score = 0;
    grid[start.y][start.x].h_score = calculateHeuristic(&start, &goal);
    grid[start.y][start.x].f_score = calculateFScore(&start, &goal);

    while (!isGoalNode(getLowestFScoreNode(grid, WIDTH, HEIGHT), &goal)) {
        Node *current = getLowestFScoreNode(grid, WIDTH, HEIGHT);
        
        if (current->x > 0) {
            Node *left = &grid[current->y][current->x - 1];
            if (left->g_score > calculateGScore(left, current)) {
                left->g_score = calculateGScore(left, current);
                left->h_score = calculateHeuristic(left, &goal);
                left->f_score = calculateFScore(left, &goal);
                left->parent = current;
            }
        }
        if (current->x < WIDTH - 1) {
            Node *right = &grid[current->y][current->x + 1];
            if (right->g_score > calculateGScore(right, current)) {
                right->g_score = calculateGScore(right, current);
                right->h_score = calculateHeuristic(right, &goal);
                right->f_score = calculateFScore(right, &goal);
                right->parent = current;
            }
        }
        if (current->y > 0) {
            Node *up = &grid[current->y - 1][current->x];
            if (up->g_score > calculateGScore(up, current)) {
                up->g_score = calculateGScore(up, current);
                up->h_score = calculateHeuristic(up, &goal);
                up->f_score = calculateFScore(up, &goal);
                up->parent = current;
            }
        }
        if (current->y < HEIGHT - 1) {
            Node *down = &grid[current->y + 1][current->x];
            if (down->g_score > calculateGScore(down, current)) {
                down->g_score = calculateGScore(down, current);
                down->h_score = calculateHeuristic(down, &goal);
                down->f_score = calculateFScore(down, &goal);
                down->parent = current;
            }
        }
    }

    reconstructPath(grid, &goal);

    freeGrid(grid, WIDTH, HEIGHT);

    return 0;
}