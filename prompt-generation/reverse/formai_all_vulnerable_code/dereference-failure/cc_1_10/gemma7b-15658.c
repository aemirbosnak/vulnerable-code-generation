//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

struct Node* createNode(int x, int y) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

    struct Node* head = createNode(0, 0);
    head->next = createNode(1, 0);
    head->next->next = createNode(2, 0);
    head->next->next->next = createNode(0, 1);
    head->next->next->next->next = createNode(1, 1);
    head->next->next->next->next->next = createNode(2, 1);
    head->next->next->next->next->next->next = createNode(0, 2);
    head->next->next->next->next->next->next->next = createNode(1, 2);
    head->next->next->next->next->next->next->next->next = createNode(2, 2);

    srand(time(NULL));

    int player = rand() % 2 + 1;

    // Game loop
    while (!board[head->x][head->y]) {
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Check if move is valid
        if (board[move_x][move_y] == 0) {
            board[move_x][move_y] = player;

            // Update head node
            head->x = move_x;
            head->y = move_y;

            // Check if player has won
            if (checkWin(board, player) == 1) {
                printf("Player %d has won!", player);
                break;
            }
        }
    }

    // If game ends in a draw
    if (!board[0][0] && !board[0][1] && !board[0][2] &&
        !board[1][0] && !board[1][1] && !board[1][2] &&
        !board[2][0] && !board[2][1] && !board[2][2]) {
        printf("It's a draw!");
    }

    return 0;
}

int checkWin(int** board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}