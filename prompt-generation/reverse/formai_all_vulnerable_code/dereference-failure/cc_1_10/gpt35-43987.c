//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// define the maze 
#define ROW 6
#define COL 6
char maze[ROW][COL] = { {'#', '#', '#', '#', '.', '#'},
                        {'.', '.', '.', '#', '.', '#'},
                        {'#', '#', '.', '.', '.', '#'},
                        {'#', '.', '.', '#', '.', '.'},
                        {'#', '#', '.', '.', '.', '#'},
                        {'#', '#', '#', '#', '.', '#'} };

// define node struct 
typedef struct node {
    int x;
    int y;
    struct node* parent;
}Node;

// helper function to check if position is a valid move 
int is_valid_move(int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL) {
        if (maze[x][y] != '#') {
            return 1;
        }
    }
    return 0;
}

// print the current path 
void print_path(Node* node) {
    if (node != NULL) {
        print_path(node->parent);
        printf("(%d, %d) -> ", node->x, node->y);
    }
}

// helper function to find shortest path using BFS 
Node* find_shortest_path(int start_x, int start_y, int end_x, int end_y) {
    // create visited matrix to keep track of visited nodes 
    int visited[ROW][COL] = { 0 };
    Node* queue[ROW * COL] = { 0 };
    int front = 0;
    int rear = 0;
    Node* start = (Node*)malloc(sizeof(Node));
    start->x = start_x;
    start->y = start_y;
    start->parent = NULL;
    queue[rear++] = start;
    visited[start_x][start_y] = 1;

    // bfs algorithm 
    while (front < rear) {
        Node* current = queue[front++];
        if (current->x == end_x && current->y == end_y) {
            return current;
        }

        // check all possible moves (north, south, east, west) 
        int dx[4] = { 0, 0, -1, 1 };
        int dy[4] = { -1, 1, 0, 0 };
        for (int i = 0; i < 4; i++) {
            int new_x = current->x + dx[i];
            int new_y = current->y + dy[i];
            if (is_valid_move(new_x, new_y) && !visited[new_x][new_y]) {
                visited[new_x][new_y] = 1;
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->x = new_x;
                new_node->y = new_y;
                new_node->parent = current;
                queue[rear++] = new_node;
            }
        }
    }
    return NULL;
}

// main function 
int main() {
    Node* path = find_shortest_path(0, 0, ROW - 1, COL - 1);
    if (path != NULL) {
        printf("The shortest path is: ");
        print_path(path);
        printf("END\n");
        return 0;
    }
    printf("No path found\n");
    return 0;
}