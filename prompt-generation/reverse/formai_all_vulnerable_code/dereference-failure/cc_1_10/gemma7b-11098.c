//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct Node {
    struct Node* next;
    int board[BOARD_SIZE][BOARD_SIZE];
    char player;
} Node;

Node* createNode() {
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            node->board[i][j] = 0;
        }
    }
    node->player = 0;
    return node;
}

void playMove(Node* node, int x, int y) {
    if (node->board[x][y] != 0) {
        return;
    }
    node->board[x][y] = node->player;
}

char checkWin(Node* node) {
    // Horizontal win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (node->board[0][i] == node->board[1][i] && node->board[0][i] == node->board[2][i] && node->board[0][i] != 0) {
            return node->board[0][i];
        }
    }

    // Vertical win
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (node->board[j][0] == node->board[j][1] && node->board[j][0] == node->board[j][2] && node->board[j][0] != 0) {
            return node->board[j][0];
        }
    }

    // Diagonal win
    if (node->board[0][0] == node->board[1][1] && node->board[0][0] == node->board[2][2] && node->board[0][0] != 0) {
        return node->board[0][0];
    }

    // Draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (node->board[i][j] == 0) {
                return 0;
            }
        }
    }

    // No win or draw
    return 0;
}

int main() {
    Node* head = createNode();
    playMove(head, 1, 1);
    playMove(head, 0, 0);
    playMove(head, 2, 2);
    char winner = checkWin(head);
    if (winner) {
        printf("Winner: %c", winner);
    } else {
        printf("Draw");
    }
    return 0;
}