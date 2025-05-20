//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 5
#define START_ROW 2
#define START_COL 2
#define END_ROW 5
#define END_COL 2

int maze[ROW][COL] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,0,1,1,0},
    {0,0,0,0,0}
};

int visited[ROW][COL] = {0};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct Coord {
    int row, col;
} Coord;

typedef struct Node {
    Coord coord;
    int dist;
    struct Node* prev;
} Node;

Node* create_node(Coord coord, int dist, Node* prev) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->coord = coord;
    node->dist = dist;
    node->prev = prev;
    return node;
}

void destroy_node(Node* node) {
    free(node);
}

int is_valid_location(Coord coord) {
    if (coord.row < 0 || coord.row >= ROW || coord.col < 0 || coord.col >= COL) {
        return 0;
    }
    if (maze[coord.row][coord.col] == 1) {
        return 0;
    }
    if (visited[coord.row][coord.col] == 1) {
        return 0;
    }
    return 1;
}

void print_path(Node* node) {
    if (node->prev != NULL) {
        print_path(node->prev);
    }
    printf("Coord(%d, %d) -> ", node->coord.row, node->coord.col);
}

void bfs_pathfinding(Coord start, Coord end) {
    Node* head = create_node(start, 0, NULL);
    visited[start.row][start.col] = 1;
    Node* queue[ROW*COL];
    int start_idx = 0;
    int end_idx = 1;
    queue[start_idx] = head;

    while (start_idx < end_idx) {
        Node* current = queue[start_idx];
        if (current->coord.row == end.row && current->coord.col == end.col) {
            printf("\nPath: ");
            print_path(current);
            printf("Coord(%d, %d)\n", end.row, end.col);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            Coord adj_coord = {current->coord.row + dx[i], current->coord.col + dy[i]};
            if (is_valid_location(adj_coord)) {
                visited[adj_coord.row][adj_coord.col] = 1;
                queue[end_idx++] = create_node(adj_coord, current->dist + 1, current);
            }
        }
        ++start_idx;
    }
    printf("No path found.\n");
}

int main() {
    Coord start = {START_ROW, START_COL};
    Coord end = {END_ROW, END_COL};
    bfs_pathfinding(start, end);
    return 0;
}