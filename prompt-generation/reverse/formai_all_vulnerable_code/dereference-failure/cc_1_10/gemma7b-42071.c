//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

#define MOVE_INVALID -1
#define MOVE_VALID 0
#define MOVE_WIN 1

typedef struct Node {
    int move;
    struct Node* next;
} Node;

Node* createMoveList(int size) {
    Node* head = malloc(sizeof(Node));
    head->move = MOVE_INVALID;
    head->next = NULL;

    for (int i = 0; i < size - 1; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->move = MOVE_INVALID;
        newNode->next = head;
        head = newNode;
    }

    return head;
}

int makeMove(Node* moveList, int player, int move) {
    if (moveList->move == MOVE_INVALID) {
        moveList->move = move;
        moveList->next = malloc(sizeof(Node));
        moveList->next->move = MOVE_INVALID;
        moveList->next->next = NULL;
        return MOVE_VALID;
    } else {
        return MOVE_INVALID;
    }
}

int checkWin(int board[], int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == player && board[i - 1] == player && board[i + 1] == player) {
            return MOVE_WIN;
        }
    }

    return MOVE_VALID;
}

int main() {
    int board[BOARD_SIZE] = {0, 0, 0};
    Node* moveList = createMoveList(10);

    srand(time(NULL));

    // Player X moves first
    makeMove(moveList, PLAYER_X, rand() % 9);

    // Player O moves
    makeMove(moveList, PLAYER_O, rand() % 9);

    // Check if player X won
    if (checkWin(board, PLAYER_X) == MOVE_WIN) {
        printf("Player X won!");
    }

    // Check if player O won
    else if (checkWin(board, PLAYER_O) == MOVE_WIN) {
        printf("Player O won!");
    }

    // It's a draw
    else {
        printf("Draw!");
    }

    return 0;
}