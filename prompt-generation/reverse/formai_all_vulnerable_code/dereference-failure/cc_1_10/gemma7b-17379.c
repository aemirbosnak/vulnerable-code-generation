//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int getRandomChoice(int size) {
    srand(time(NULL));
    return rand() % size;
}

void playTicTacToe(int** board, int player) {
    int move = getRandomChoice(MAX_SIZE);

    while (board[move][move] != 0) {
        move = getRandomChoice(MAX_SIZE);
    }

    board[move][move] = player;
}

int main() {
    int** board = (int**)malloc(MAX_SIZE * sizeof(int*));
    for (int i = 0; i < MAX_SIZE; i++) {
        board[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    int player = 1;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    playTicTacToe(board, player);

    return 0;
}