//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 64

typedef struct Node {
    int move;
    struct Node* next;
} Node;

void make_move(int move, Node** head) {
    Node* newNode = malloc(sizeof(Node));
    newNode->move = move;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int evaluate_board(int board[]) {
    int sum = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != 0) {
            sum += board[i] * get_piece_value(board[i]);
        }
    }
    return sum;
}

int get_piece_value(int piece) {
    switch (piece) {
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 40;
        case 5:
            return 50;
        case 6:
            return 60;
        case 7:
            return 70;
        default:
            return 0;
    }
}

int main() {
    int board[BOARD_SIZE] = {0};
    board[1] = 1;
    board[6] = 2;
    board[10] = 3;
    board[15] = 4;

    Node* head = NULL;
    make_move(2, &head);
    make_move(4, &head);
    make_move(3, &head);

    int evaluation = evaluate_board(board);
    printf("Evaluation: %d\n", evaluation);

    return 0;
}