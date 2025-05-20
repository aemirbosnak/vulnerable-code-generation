//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVES 10

typedef struct Move {
    int x, y;
    struct Move* next;
} Move;

Move* createMove() {
    Move* move = (Move*)malloc(sizeof(Move));
    move->x = -1;
    move->y = -1;
    move->next = NULL;
    return move;
}

void addMove(Move* head, int x, int y) {
    Move* newMove = createMove();
    newMove->x = x;
    newMove->y = y;
    if (head == NULL) {
        head = newMove;
    } else {
        newMove->next = head;
        head = newMove;
    }
}

void printMoves(Move* head) {
    while (head) {
        printf("(%d, %d) ", head->x, head->y);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Move* moves = NULL;
    addMove(moves, 0, 0);
    addMove(moves, 1, 0);
    addMove(moves, 2, 0);
    addMove(moves, 3, 0);
    addMove(moves, 4, 0);

    printMoves(moves);

    return 0;
}