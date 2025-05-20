//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void solveSudoku(int** grid) {
    Node* head = NULL;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (grid[i][j] == 0) {
                insert(&head, grid[i][j]);
            }
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (grid[i][j] == 0) {
                int number = head->data;
                head = head->next;
                grid[i][j] = number;
            }
        }
    }
}

int main() {
    int** grid = (int**)malloc(sizeof(int*) * MAX);
    for (int i = 0; i < MAX; i++) {
        grid[i] = (int*)malloc(sizeof(int) * MAX);
    }

    solveSudoku(grid);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}