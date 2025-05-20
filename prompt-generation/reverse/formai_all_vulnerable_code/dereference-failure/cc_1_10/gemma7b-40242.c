//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
    int move;
    struct Node* next;
} Node;

void makeMove(int move, Node** head) {
    Node* newNode = malloc(sizeof(Node));
    newNode->move = move;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int evaluateBoard(int** board) {
    int score = 0;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (board[i] == 1) {
            score++;
        } else if (board[i] == 2) {
            score--;
        }
    }

    return score;
}

int main() {
    int board[MAX_BOARD_SIZE] = {0};
    board[1] = board[5] = board[9] = board[13] = board[17] = board[21] = board[25] = 1;
    board[2] = board[6] = board[10] = board[14] = board[18] = board[22] = board[26] = 2;

    int move = 0;
    Node* head = NULL;

    makeMove(move++, &head);
    makeMove(move++, &head);
    makeMove(move++, &head);
    makeMove(move++, &head);

    int evaluation = evaluateBoard(board);

    if (evaluation > 0) {
        printf("White wins!");
    } else if (evaluation < 0) {
        printf("Black wins!");
    } else {
        printf("Draw!");
    }

    return 0;
}