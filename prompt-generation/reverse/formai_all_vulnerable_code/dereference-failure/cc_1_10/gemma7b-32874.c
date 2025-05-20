//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* next;
    char move[20];
    int score;
} Node;

typedef struct Board {
    struct Node** board;
    int size;
} Board;

void initBoard(Board* board) {
    board->board = malloc(board->size * sizeof(struct Node*));
    for (int i = 0; i < board->size; i++) {
        board->board[i] = NULL;
    }
}

void makeMove(Board* board, char move) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    strcpy(newNode->move, move);
    newNode->score = 0;

    switch (move) {
        case 'e':
            board->board[1] = newNode;
            break;
        case 'N':
            board->board[6] = newNode;
            break;
        case 'B':
            board->board[8] = newNode;
            break;
        case 'R':
            board->board[9] = newNode;
            break;
        case 'Q':
            board->board[10] = newNode;
            break;
        case 'K':
            board->board[12] = newNode;
            break;
    }
}

void printBoard(Board* board) {
    for (int i = 0; i < board->size; i++) {
        struct Node* node = board->board[i];
        if (node) {
            printf("%s ", node->move);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    Board* board = malloc(sizeof(struct Board));
    board->size = 13;
    initBoard(board);

    makeMove(board, 'e');
    makeMove(board, 'N');
    makeMove(board, 'B');
    makeMove(board, 'R');
    makeMove(board, 'Q');
    makeMove(board, 'K');

    printBoard(board);

    return 0;
}