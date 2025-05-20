//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 20

typedef struct Move {
    int x;
    int y;
    struct Move* next;
} Move;

Move* createMoveList() {
    Move* head = malloc(sizeof(Move));
    head->x = -1;
    head->y = -1;
    head->next = NULL;
    return head;
}

void addMove(Move* head, int x, int y) {
    Move* newMove = malloc(sizeof(Move));
    newMove->x = x;
    newMove->y = y;
    newMove->next = NULL;

    if (head->next == NULL) {
        head->next = newMove;
    } else {
        head->next->next = newMove;
    }
}

void playGame() {
    Move* moves = createMoveList();
    addMove(moves, 0, 0);
    addMove(moves, 1, 0);
    addMove(moves, 1, 1);

    int i = 0;
    for (Move* move = moves; move->next != NULL; i++) {
        printf("Move %d: (%d, %d)\n", i + 1, move->x, move->y);
    }

    printf("Number of moves: %d\n", i + 1);
}

int main() {
    playGame();
    return 0;
}