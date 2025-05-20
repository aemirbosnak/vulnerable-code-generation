//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void playGame() {
    Node* head = createNode(0, 0);
    head->next = createNode(1, 0);
    head->next->next = createNode(2, 0);
    head->next->next->next = createNode(0, 1);
    head->next->next->next->next = createNode(1, 1);
    head->next->next->next->next->next = createNode(2, 1);
    head->next->next->next->next->next->next = createNode(0, 2);
    head->next->next->next->next->next->next->next = createNode(1, 2);
    head->next->next->next->next->next->next->next->next = createNode(2, 2);

    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

    int player = 1;

    while (!winner(head, board, player)) {
        int moveX, moveY;
        printf("Enter move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        if (validMove(board, moveX, moveY)) {
            board[moveX][moveY] = player;
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move.\n");
        }
    }

    winner(head, board, player);
}

int winner(Node* head, int board[BOARD_SIZE][BOARD_SIZE], int player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player) {
        return 1;
    }

    // If all moves are made and no winner, it's a draw
    return 2;
}

int validMove(int board[BOARD_SIZE][BOARD_SIZE], int moveX, int moveY) {
    return (moveX >= 0 && moveX < BOARD_SIZE && moveY >= 0 && moveY < BOARD_SIZE && board[moveX][moveY] == 0);
}

int main() {
    playGame();

    return 0;
}