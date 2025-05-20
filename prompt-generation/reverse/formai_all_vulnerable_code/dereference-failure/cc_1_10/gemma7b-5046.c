//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void playTicTacToe() {
    Node* board = insertAtTail(NULL, 0);
    board = insertAtTail(board, 1);
    board = insertAtTail(board, 2);
    board = insertAtTail(board, 3);
    board = insertAtTail(board, 4);
    board = insertAtTail(board, 5);
    board = insertAtTail(board, 6);
    board = insertAtTail(board, 7);
    board = insertAtTail(board, 8);
    board = insertAtTail(board, 9);

    int player = 1;
    int moveMade = 0;
    char move;

    printf("Welcome to Tic Tac Toe!\n");

    while (!moveMade) {
        printf("Enter your move (e.g. a, b, c): ");
        scanf("%c", &move);

        switch (move) {
            case 'a':
                if (board->data == 0) {
                    board->data = player;
                    moveMade = 1;
                }
                break;
            case 'b':
                if (board->next->data == 0) {
                    board->next->data = player;
                    moveMade = 1;
                }
                break;
            case 'c':
                if (board->next->next->data == 0) {
                    board->next->next->data = player;
                    moveMade = 1;
                }
                break;
            default:
                printf("Invalid move.\n");
                break;
        }
    }

    if (board->data == player) {
        printf("You won!\n");
    } else {
        printf("You lost.\n");
    }
}

int main() {
    playTicTacToe();

    return 0;
}