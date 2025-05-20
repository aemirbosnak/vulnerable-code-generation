//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 8
#define START_ROW 2
#define START_COL 0
#define END_ROW 1
#define END_COL 7

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#'}
};

int visited[ROWS][COLS];

typedef struct {
    int row;
    int col;
    int distance;
    struct node* parent;
} node;

node* new_node(int row, int col, int distance, node* parent) {
    node* new = (node*)malloc(sizeof(node));
    new->row = row;
    new->col = col;
    new->distance = distance;
    new->parent = parent;
    return new;
}

int is_valid_move(int row, int col) {
    if (row < 0 || row >= ROWS) return 0;
    if (col < 0 || col >= COLS) return 0;
    if (maze[row][col] == '#') return 0;
    if (visited[row][col]) return 0;
    return 1;
}

node* get_shortest_path() {
    node* queue[ROWS * COLS];
    int head = 0;
    int tail = 0;
    queue[tail++] = new_node(START_ROW, START_COL, 0, NULL);
    visited[START_ROW][START_COL] = 1;
    while (head < tail) {
        node* curr = queue[head++];
        if (curr->row == END_ROW && curr->col == END_COL) {
            return curr;
        }
        if (is_valid_move(curr->row + 1, curr->col)) {
            visited[curr->row + 1][curr->col] = 1;
            queue[tail++] = new_node(curr->row + 1, curr->col, curr->distance + 1, curr);
        }
        if (is_valid_move(curr->row - 1, curr->col)) {
            visited[curr->row - 1][curr->col] = 1;
            queue[tail++] = new_node(curr->row - 1, curr->col, curr->distance + 1, curr);
        }
        if (is_valid_move(curr->row, curr->col + 1)) {
            visited[curr->row][curr->col + 1] = 1;
            queue[tail++] = new_node(curr->row, curr->col + 1, curr->distance + 1, curr);
        }
        if (is_valid_move(curr->row, curr->col - 1)) {
            visited[curr->row][curr->col - 1] = 1;
            queue[tail++] = new_node(curr->row, curr->col - 1, curr->distance + 1, curr);
        }
    }
    return NULL;
}

void print_path(node* end) {
    if (end == NULL) return;
    print_path(end->parent);
    printf("(%d, %d)\n", end->row, end->col);
}

int main() {
    node* end = get_shortest_path();
    if (end == NULL) {
        printf("No path found!\n");
    } else {
        printf("Shortest path found:\n");
        print_path(end);
    }
    return 0;
}