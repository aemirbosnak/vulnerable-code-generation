//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int row, col;
    struct Node* next;
} Node;

Node* createNode(int row, int col) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int row, int col) {
    Node* newNode = createNode(row, col);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int checkWin(Node* head) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (head->row == r && head->next->row == r && head->next->next->row == r) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (head->col == c && head->next->col == c && head->next->next->col == c) {
            return 1;
        }
    }

    // Check diagonals
    if (head->row == head->col && head->next->row == head->next->col && head->next->next->row == head->next->next->col) {
        return 1;
    }

    return 0;
}

int main() {
    // Create a linked list to store the moves
    Node* head = NULL;

    // Play until someone wins or it's a draw
    while (!checkWin(head) && head->next) {
        // Get the move from the user
        int row, col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &row, &col);

        // Insert the move into the linked list
        insertNode(head, row, col);

        // Make the computer's move
        // (In this example, the computer always plays in the center)
        insertNode(head, 1, 1);
    }

    // Check if the user won or it's a draw
    if (checkWin(head)) {
        printf("You won!");
    } else {
        printf("It's a draw");
    }

    return 0;
}