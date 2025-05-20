//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 64

typedef struct Node {
    int move;
    struct Node* next;
} Node;

Node* move_list_insert(Node* head, int move) {
    Node* newNode = malloc(sizeof(Node));
    newNode->move = move;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void print_board(int** board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int** board = malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(int) * BOARD_SIZE);
    }

    board[0][0] = 'r';
    board[0][1] = 'p';
    board[1][0] = 'n';
    board[1][1] = 'p';

    print_board(board);

    move_list_insert(NULL, 1);
    move_list_insert(NULL, 2);

    print_board(board);

    free(board);

    return 0;
}