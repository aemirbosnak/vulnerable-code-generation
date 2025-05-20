//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

typedef struct node {
    int row;
    int col;
    int f_cost;
    int g_cost;
    int h_cost;
    struct node* parent;
} Node;

typedef struct priority_queue {
    int count;
    int capacity;
    int* cost;
    Node** nodes;
} PriorityQueue;

Node* astar(int maze[][COL], int start_row, int start_col, int end_row, int end_col);
int heuristic_cost(int row1, int col1, int row2, int col2);
PriorityQueue* create_priority_queue(int capacity);
Node* create_node(int row, int col, int f_cost, int g_cost, int h_cost, Node* parent);
void enqueue(PriorityQueue* pq, int cost, Node* node);
Node* dequeue(PriorityQueue* pq);
void free_memory(int** arr, int size);
void free_priority_queue(PriorityQueue* pq);
void print_path(Node* node);

int main(void) {
    int maze[ROW][COL] = {{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    Node* end_node = astar(maze, 0, 0, 9, 9);
    print_path(end_node);

    return 0;
}

Node* astar(int maze[][COL], int start_row, int start_col, int end_row, int end_col) {
    int i, row, col, new_row, new_col;
    int** g_cost = (int**)malloc(ROW * sizeof(int*));
    for (i = 0; i < ROW; i++) {
        g_cost[i] = (int*)malloc(COL * sizeof(int));
    }
    for (i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            g_cost[i][j] = INT_MAX;
        }
    }
    g_cost[start_row][start_col] = 0;

    PriorityQueue* open_list = create_priority_queue(ROW * COL);
    enqueue(open_list, 0, create_node(start_row, start_col, 0, 0, 0, NULL));

    int** closed_list = (int**)malloc(ROW * sizeof(int*));
    for (i = 0; i < ROW; i++) {
        closed_list[i] = (int*)malloc(COL * sizeof(int));
    }
    for (i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closed_list[i][j] = 0;
        }
    }

    while (open_list->count > 0) {
        Node* curr_node = dequeue(open_list);
        row = curr_node->row;
        col = curr_node->col;

        if (row == end_row && col == end_col) {
            free_priority_queue(open_list);
            for (i = 0; i < ROW; i++) {
                free(closed_list[i]);
            }
            free(closed_list);
            for (i = 0; i < ROW; i++) {
                free(g_cost[i]);
            }
            free(g_cost);
            return curr_node;
        }

        closed_list[row][col] = 1;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (i = 0; i < 4; i++) {
            new_row = row + directions[i][0];
            new_col = col + directions[i][1];

            if (new_row < 0 || new_col < 0 || new_row >= ROW || new_col >= COL || closed_list[new_row][new_col] == 1 || maze[new_row][new_col] == 1) {
                continue;
            }

            int temp_g_cost = g_cost[row][col] + 1;
            if (temp_g_cost < g_cost[new_row][new_col]) {
                g_cost[new_row][new_col] = temp_g_cost;
                int h_cost = heuristic_cost(new_row, new_col, end_row, end_col);
                int f_cost = temp_g_cost + h_cost;
                enqueue(open_list, f_cost, create_node(new_row, new_col, f_cost, temp_g_cost, h_cost, curr_node));
            }
        }
    }
    return NULL;
}

int heuristic_cost(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

PriorityQueue* create_priority_queue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->count = 0;
    pq->capacity = capacity;
    pq->cost = (int*)malloc(capacity * sizeof(int));
    pq->nodes = (Node**)malloc(capacity * sizeof(Node*));
    return pq;
}

Node* create_node(int row, int col, int f_cost, int g_cost, int h_cost, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f_cost = f_cost;
    node->g_cost = g_cost;
    node->h_cost = h_cost;
    node->parent = parent;
    return node;
}

void enqueue(PriorityQueue* pq, int cost, Node* node) {
    int i;
    for (i = 0; i < pq->count; i++) {
        if (pq->cost[i] > cost) {
            break;
        }
    }
    for (int j = pq->count; j > i; j--) {
        pq->cost[j] = pq->cost[j-1];
        pq->nodes[j] = pq->nodes[j-1];
    }
    pq->cost[i] = cost;
    pq->nodes[i] = node;
    pq->count++;
}

Node* dequeue(PriorityQueue* pq) {
    Node* node = pq->nodes[0];
    pq->count--;
    for (int i = 0; i < pq->count; i++) {
        pq->cost[i] = pq->cost[i+1];
        pq->nodes[i] = pq->nodes[i+1];
    }
    return node;
}

void free_memory(int** arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}

void free_priority_queue(PriorityQueue* pq) {
    free(pq->cost);
    free(pq->nodes);
    free(pq);
}

void print_path(Node* node) {
    if (node == NULL) {
        printf("There is no path.\n");
        return;
    }
    int i;
    int path_cost = node->f_cost;
    printf("The path cost is %d.\n", path_cost);
    while (node != NULL) {
        printf("(%d, %d) ", node->row, node->col);
        node = node->parent;
    }
    printf("\n");
}