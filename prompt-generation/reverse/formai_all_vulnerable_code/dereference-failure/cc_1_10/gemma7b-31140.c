//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    srand(time(NULL));

    Node* head = NULL;
    insertAtTail(&head, 0);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    insertAtTail(&head, 6);
    insertAtTail(&head, 7);
    insertAtTail(&head, 8);
    insertAtTail(&head, 9);

    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    int move = 0;
    int player = 1;
    int win = 0;

    while (!win) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        if (board[row][col] == 0) {
            board[row][col] = player;
            move++;
            if (move % 2 == 0) {
                player = 2;
            } else {
                player = 1;
            }

            // Check if the player won
            win = checkWin(board, player);
        }
    }

    // Print the winner
    printf("The winner is: %d", player);

    return 0;
}

int checkWin(int** board, int player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // If all moves have been made and there is no winner, the game is a draw
    return 0;
}