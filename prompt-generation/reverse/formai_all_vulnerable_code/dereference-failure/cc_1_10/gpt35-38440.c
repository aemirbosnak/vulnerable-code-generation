//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct node {
    int x, y, f, g, h;
    struct node *parent;
};

int abs(int a) {
    return a < 0 ? -a : a;
}

int heuristic(struct node *n, struct node *end) {
    return abs(end->x - n->x) + abs(end->y - n->y);
}

int is_valid(int x, int y, int max_x, int max_y) {
    return x >= 0 && y >= 0 && x < max_x && y < max_y;
}

void insert_node(struct node **fringe, struct node *new_node, int *fringe_size) {
    int i;
    for (i = 0; i < *fringe_size; i++) {
        if (new_node->f <= fringe[i]->f) {
            // make space for new node
            for (int j = *fringe_size - 1; j >= i; j--) {
                fringe[j+1] = fringe[j];
            }
            fringe[i] = new_node; // insert node
            (*fringe_size)++;
            return;
        }
    }
    // new node has largest f - append to end
    fringe[*fringe_size] = new_node;
    (*fringe_size)++;
}

void get_neighbours(struct node *current, struct node *end, struct node **fringe, int *fringe_size, int **visited, int max_x, int max_y) {
    int movements[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int i = 0; i < 4; i++) {
        int new_x = current->x + movements[i][0];
        int new_y = current->y + movements[i][1];
        if (!is_valid(new_x, new_y, max_x, max_y)) {
            continue; // skip if out of bounds
        }
        if (visited[new_x][new_y]) {
            continue; // skip if already visited
        }
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->x = new_x;
        new_node->y = new_y;
        new_node->parent = current;
        new_node->g = current->g + 1;
        new_node->h = heuristic(new_node, end);
        new_node->f = new_node->g + new_node->h;
        insert_node(fringe, new_node, fringe_size);
    }
}

void print_path(struct node *current) {
    if (current->parent == NULL) {
        printf("(%d,%d)", current->x, current->y);
        return;
    }
    print_path(current->parent);
    printf(" -> (%d,%d)", current->x, current->y);
}

void find_path(int **grid, int start_x, int start_y, int end_x, int end_y, int max_x, int max_y) {
    struct node start_node = {start_x, start_y};
    struct node end_node = {end_x, end_y};
    int visited[max_x][max_y];
    for (int x = 0; x < max_x; x++) {
        for (int y = 0; y < max_y; y++) {
            visited[x][y] = 0;
        }
    }
    struct node *fringe[max_x*max_y];
    int fringe_size = 0;
    insert_node(fringe, &start_node, &fringe_size);
    while (fringe_size > 0) {
        struct node *current = fringe[0];
        if (current->x == end_x && current->y == end_y) {
            printf("Path found:\n");
            print_path(current);
            printf("\n");
            return;
        }
        visited[current->x][current->y] = 1;
        get_neighbours(current, &end_node, fringe, &fringe_size, visited, max_x, max_y);
        for (int i = 0; i < fringe_size-1; i++) {
            fringe[i] = fringe[i+1]; // update fringe by removing first element
        }
        fringe_size--;
        free(current);
    }
    printf("No path found.\n");
}

int main() {
    int max_x = 6;
    int max_y = 6;
    int **grid = (int **) malloc(max_x * sizeof(int *));
    for (int x = 0; x < max_x; x++) {
        grid[x] = (int *) malloc(max_y * sizeof(int));
        for (int y = 0; y < max_y; y++) {
            grid[x][y] = 1;
        }
    }
    // set obstacles
    grid[1][3] = 0;
    grid[2][3] = 0;
    grid[3][3] = 0;
    grid[3][2] = 0;
    grid[3][1] = 0;
    grid[3][0] = 0;
    grid[4][3] = 0;
    grid[5][3] = 0;

    int start_x = 0;
    int start_y = 0;
    int end_x = 4;
    int end_y = 5;

    find_path(grid, start_x, start_y, end_x, end_y, max_x, max_y);

    // free memory
    for (int x = 0; x < max_x; x++) {
        free(grid[x]);
    }
    free(grid);

    return 0;
}