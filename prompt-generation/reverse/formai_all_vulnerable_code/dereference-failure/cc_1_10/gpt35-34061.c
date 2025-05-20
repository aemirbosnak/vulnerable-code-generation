//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

#define START_ROW 0
#define START_COL 0

#define END_ROW 9
#define END_COL 9

#define WALL_ROW 5
#define WALL_COL_START 2
#define WALL_COL_END 7

int heuristic(int row, int col) {
    return abs(row - END_ROW) + abs(col - END_COL);
}

typedef struct {
    int row;
    int col;
} Node;

typedef struct ListNode {
    Node node;
    struct ListNode* next;
} ListNode;

typedef struct {
    int size;
    ListNode* head;
    ListNode* tail;
} List;

void InitList(List* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

bool IsListEmpty(List* list) {
    return list->size == 0;
}

void Enqueue(List* list, Node node) {
    ListNode* new_node = malloc(sizeof(ListNode));
    new_node->node = node;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

Node Dequeue(List* list) {
    Node node = list->head->node;

    ListNode* temp = list->head;
    list->head = list->head->next;

    free(temp);
    list->size--;

    return node;
}

List* ConstructPath(Node* nodes, Node node) {
    List* path = malloc(sizeof(List));
    InitList(path);

    while (node.row != START_ROW || node.col != START_COL) {
        Enqueue(path, node);
        node = nodes[node.row * ROWS + node.col];
    }

    Enqueue(path, (Node) {START_ROW, START_COL});

    return path;
}

int main() {
    int obstacles[ROWS][COLS] = {0};

    // Create a wall of obstacles
    for (int col = WALL_COL_START; col <= WALL_COL_END; col++) {
        obstacles[WALL_ROW][col] = 1;
    }

    // Create start and end nodes
    Node start = {START_ROW, START_COL};
    Node end = {END_ROW, END_COL};

    // Initialize the open and closed lists
    List open_list;
    InitList(&open_list);

    bool closed_list[ROWS][COLS] = {false};

    // Add the start node to the open list
    Enqueue(&open_list, start);

    // Initialize the G and H scores
    int g_scores[ROWS][COLS];
    int f_scores[ROWS][COLS];

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            g_scores[row][col] = __INT_MAX__;
            f_scores[row][col] = __INT_MAX__;
        }
    }

    // Set the G score of the start node to 0
    g_scores[start.row][start.col] = 0;

    // Set the F score of the start node to the heuristic
    f_scores[start.row][start.col] = heuristic(start.row, start.col);

    // Keep looping until the open list is empty or the goal is found
    while (!IsListEmpty(&open_list)) {
        // Get the node with the lowest F score
        Node current_node = Dequeue(&open_list);

        // Check if the goal has been reached
        if (current_node.row == end.row && current_node.col == end.col) {
            List* path = ConstructPath((Node*)closed_list, current_node);
            printf("Path found!\n");

            while (!IsListEmpty(path)) {
                Node node = Dequeue(path);
                printf("(%d,%d) ", node.row, node.col);
            }

            printf("\n");
            return 0;
        }

        // Mark the current node as closed
        closed_list[current_node.row][current_node.col] = true;

        // Loop through all the neighbors of the current node
        for (int row_offset = -1; row_offset <= 1; row_offset++) {
            for (int col_offset = -1; col_offset <= 1; col_offset++) {
                // Skip the current node and diagonals
                if ((row_offset == 0 && col_offset == 0) ||
                    (abs(row_offset) == 1 && abs(col_offset) == 1)) {
                    continue;
                }

                int neighbor_row = current_node.row + row_offset;
                int neighbor_col = current_node.col + col_offset;

                // Skip out-of-bounds nodes and nodes that are obstacles or closed
                if (neighbor_row < 0 || neighbor_row >= ROWS ||
                    neighbor_col < 0 || neighbor_col >= COLS ||
                    obstacles[neighbor_row][neighbor_col] ||
                    closed_list[neighbor_row][neighbor_col]) {
                    continue;
                }

                // Calculate the tentative G score of the neighbor
                int tentative_g_score = g_scores[current_node.row][current_node.col] + 1;

                // If the tentative score is better than the current score, update the scores
                if (tentative_g_score < g_scores[neighbor_row][neighbor_col]) {
                    g_scores[neighbor_row][neighbor_col] = tentative_g_score;
                    f_scores[neighbor_row][neighbor_col] = tentative_g_score + heuristic(neighbor_row, neighbor_col);

                    // Add the neighbor to the open list if it isn't already there
                    if (!closed_list[neighbor_row][neighbor_col]) {
                        Enqueue(&open_list, (Node) {neighbor_row, neighbor_col});
                    }
                }
            }
        }
    }

    printf("No path found!\n");
    return -1;
}