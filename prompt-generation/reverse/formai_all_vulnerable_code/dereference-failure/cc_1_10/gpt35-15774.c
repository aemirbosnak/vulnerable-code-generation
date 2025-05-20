//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ROW 10
#define COL 10

int grid[ROW][COL] = {
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}
};

int visited[ROW][COL] = { 0 };

struct node {
    int row;
    int col;
    struct node *next;
};

void push(struct node **head, int row, int col) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void pop(struct node **head, int *row, int *col) {
    if (*head == NULL) {
        return;
    }
    *row = (*head)->row;
    *col = (*head)->col;
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int bfs(int start_row, int start_col, int end_row, int end_col) {
    struct node *q = NULL;
    push(&q, start_row, start_col);
    visited[start_row][start_col] = 1;
    int distance = 0;
    while (q != NULL) {
        int size = 0;
        for (struct node *current = q; current != NULL; current = current->next) {
            size++;
        }
        while (size > 0) {
            int row = 0, col = 0;
            pop(&q, &row, &col);
            if (row == end_row && col == end_col) {
                return distance;
            }
            if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 0) {
                push(&q, row - 1, col);
                visited[row - 1][col] = 1;
            }
            if (row + 1 < ROW && grid[row + 1][col] == 1 && visited[row + 1][col] == 0) {
                push(&q, row + 1, col);
                visited[row + 1][col] = 1;
            }
            if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 0) {
                push(&q, row, col - 1);
                visited[row][col - 1] = 1;
            }
            if (col + 1 < COL && grid[row][col + 1] == 1 && visited[row][col + 1] == 0) {
                push(&q, row, col + 1);
                visited[row][col + 1] = 1;
            }
            size--;
        }
        distance++;
    }
    return -1;
}

int main() {
    int start_row = 0, start_col = 0;
    int end_row = 9, end_col = 9;
    int distance = bfs(start_row, start_col, end_row, end_col);
    if (distance == -1) {
        printf("There is no path from start to end.");
    } else {
        printf("The shortest path from start to end is %d.", distance);
    }
    return 0;
}