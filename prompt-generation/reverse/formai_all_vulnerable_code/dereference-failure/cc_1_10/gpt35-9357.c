//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 6
#define COL 6
#define ROW_POS 0
#define COL_POS 1

int start[2] = {0, 0};
int end[2] = {5, 5};
int obst[5][2] = {{2,2}, {2,3}, {3,2}, {3,3}, {4,2}};

int obstacle(int x, int y) {
    for (int i = 0; i < 5; i++) {
        if (x == obst[i][ROW_POS] && y == obst[i][COL_POS]) {
            return 1;
        }
    }
    return 0;
}

int heuristic(int x, int y) {
    return abs(x - end[ROW_POS]) + abs(y - end[COL_POS]);
}

typedef struct Node {
    int row;
    int col;
    int f;
    int g;
    int h;
    struct Node* parent;
} Node;

Node* create_node(int row, int col, int f, int g, int h, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node* open[], int size, int root) {
    int smallest = root;
    int left = (root * 2) + 1;
    int right = (root * 2) + 2;

    if (left < size && open[left]->f < open[smallest]->f) {
        smallest = left;
    }

    if (right < size && open[right]->f < open[smallest]->f) {
        smallest = right;
    }

    if (smallest != root) {
        swap(&open[root], &open[smallest]);
        heapify(open, size, smallest);
    }
}

void push_node(Node* open[], int* size, Node* new_node) {
    open[*size] = new_node;
    int i = *size;
    (*size)++;
    while (i > 0 && open[i]->f < open[(i - 1) / 2]->f) {
        swap(&open[i], &open[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop_node(Node* open[], int* size) {
    open[0] = open[*size - 1];
    (*size)--;
    heapify(open, *size, 0);
}

int visited(int row, int col, Node* closed[], int size) {
    for (int i = 0; i < size; i++) {
        if (closed[i]->row == row && closed[i]->col == col) {
            return 1;
        }
    }
    return 0;
}

int* get_directions(int row, int col, Node* current, Node* open[], int* size, Node* closed[], int* closed_size) {
    int* directions = malloc(sizeof(int) * 8);
    int index = 0;
    int new_row, new_col;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            new_row = row + i;
            new_col = col + j;
            if ((i != 0 || j != 0) && new_row >= 0 && new_row < ROW && new_col >= 0 && new_col < COL && obstacle(new_row, new_col) != 1 && visited(new_row, new_col, closed, *closed_size) != 1) {
                int g = current->g + 1; 
                int h = heuristic(new_row, new_col);
                int f = g + h;
                Node* new_node = create_node(new_row, new_col, f, g, h, current);
                push_node(open, size, new_node);
                directions[index] = (i * 10) + j;
                index++;
            }
        }
    }
    return directions;
}

int* get_path(Node* end_node, int* size) {
    Node* current = end_node;
    *size = 0;
    while (current != NULL) {
        (*size)++;
        current = current->parent;
    }
    int* path = malloc(sizeof(int) * (*size) * 2);
    current = end_node;
    int index = (*size) * 2 - 2;
    while (current != NULL) {
        path[index] = current->col;
        path[index - 1] = current->row;
        index -= 2;
        current = current->parent;
    }
    return path;
}

int main() {
    Node* open[ROW * COL];
    int open_size = 0;
    Node* closed[ROW * COL];
    int closed_size = 0;

    Node* start_node = create_node(start[ROW_POS], start[COL_POS], 0, 0, heuristic(start[ROW_POS], start[COL_POS]), NULL);
    push_node(open, &open_size, start_node);

    while (open_size > 0) {
        Node* current = open[0];
        if (current->row == end[ROW_POS] && current->col == end[COL_POS]) {
            int path_size;
            int* path = get_path(current, &path_size);
            printf("Path Found: ");
            for (int i = 0; i < path_size * 2; i+=2) {
                printf("(%d, %d) ", path[i], path[i+1]);
            }
            printf("\n");
            free(path);
            return 0;
        }
        pop_node(open, &open_size);
        closed[closed_size] = current;
        closed_size++;
        int* directions = get_directions(current->row, current->col, current, open, &open_size, closed, &closed_size);
        free(directions);
    }
    printf("No Path Found\n");
    return 0;
}