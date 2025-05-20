//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 10
#define COL 10
#define INF 10000000

// define a node
typedef struct node {
    int x, y, f, g, h;
    struct node *next;
} Node;

// declare some functions
void insert(Node **head, int x, int y, int f, int g, int h);

void free_list(Node *head);

void print_list(Node *head);

void astar(char maze[ROW][COL], int start[2], int end[2]);

int in_boundary(int i, int j);

int can_pass(char maze[ROW][COL], int i, int j);

int get_distance(int start[2], int end[2]);

// define the main function
int main() {
    char maze[ROW][COL] = {
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '1', '0', '1', '0', '1', '0', '1'},
            {'1', '0', '1', '1', '0', '1', '0', '1', '0', '1'},
            {'1', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
            {'1', '0', '1', '1', '1', '1', '0', '1', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '0', '1', '1', '1', '0', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    int start[2] = {1, 1};
    int end[2] = {8, 8};

    astar(maze, start, end);

    return 0;
}

// define the insert function for the linked list
void insert(Node **head, int x, int y, int f, int g, int h) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->f = f;
    new_node->g = g;
    new_node->h = h;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    if (new_node->f < current->f) {
        new_node->next = current;
        *head = new_node;
        return;
    }

    while (current->next != NULL && current->next->f < new_node->f) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// define the free_list function for the linked list
void free_list(Node *head) {
    Node *prev = NULL;
    while (head != NULL) {
        prev = head;
        head = head->next;
        free(prev);
    }
}

// define the print_list function for the linked list (for debugging)
void print_list(Node *head) {
    while (head != NULL) {
        printf("(%d,%d,%d,%d,%d) ", head->x, head->y, head->f, head->g, head->h);
        head = head->next;
    }
    printf("\n");
}

// define the A* algorithm function
void astar(char maze[ROW][COL], int start[2], int end[2]) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int open[ROW][COL] = {0};
    int close[ROW][COL] = {0};
    int parent[ROW][COL][2] = {0}; // keep track of the parent of each node

    int f[ROW][COL] = {INF};
    int g[ROW][COL] = {INF};
    int h[ROW][COL] = {INF};

    Node *head = NULL; // create an empty linked list to store the nodes to be visited

    insert(&head, start[0], start[1], 0, 0, get_distance(start, end)); // insert the first node into the linked list
    open[start[0]][start[1]] = 1; // mark the starting node as "open"

    while (head != NULL) {
        Node *current = head; // get the node with the lowest f score
        head = head->next;
        open[current->x][current->y] = 0; // mark the current node as "closed"
        close[current->x][current->y] = 1;

        if (current->x == end[0] && current->y == end[1]) { // if we reach the end, stop searching
            printf("Found a path!\n");
            while (current != NULL) {
                printf("(%d,%d) ", current->x, current->y);
                current = current->next;
            }
            printf("\n");
            free_list(head); // free the linked list
            return;
        }

        for (int i = 0; i < 4; i++) { // check each neighbor of the current node
            int x = current->x + dx[i];
            int y = current->y + dy[i];

            if (!in_boundary(x, y)) { // check if it's within the boundary of the maze
                continue;
            }

            if (!can_pass(maze, x, y)) { // check if it's a wall or not
                continue;
            }

            int new_g = current->g + 1;
            int new_h = get_distance((int[]) {x, y}, end);
            int new_f = new_g + new_h;

            if (close[x][y]) { // check if it's already closed
                continue;
            }

            if (!open[x][y] || new_f < f[x][y]) { // check if it's not open or has a better f score than previously
                f[x][y] = new_f;
                g[x][y] = new_g;
                h[x][y] = new_h;
                parent[x][y][0] = current->x;
                parent[x][y][1] = current->y;

                if (!open[x][y]) { // if it's not open, add it to the linked list
                    insert(&head, x, y, new_f, new_g, new_h);
                    open[x][y] = 1;
                }
            }
        }
    }

    printf("Path not found.\n");
    free_list(head); // free the linked list
}

// define the in_boundary function
int in_boundary(int i, int j) {
    if (i < 0 || i >= ROW || j < 0 || j >= COL) {
        return 0;
    }
    return 1;
}

// define the can_pass function
int can_pass(char maze[ROW][COL], int i, int j) {
    return maze[i][j] == '0';
}

// define the get_distance function
int get_distance(int start[2], int end[2]) {
    return abs(start[0] - end[0]) + abs(start[1] - end[1]);
}