//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    Node* head = NULL;
    srand(time(NULL));

    // Player 1's move
    int player1Move = rand() % BOARD_SIZE;
    insertAtTail(head, player1Move);

    // Player 2's move
    int player2Move = rand() % BOARD_SIZE;
    insertAtTail(head, player2Move);

    // Player 1's move
    player1Move = rand() % BOARD_SIZE;
    insertAtTail(head, player1Move);

    // Player 2's move
    player2Move = rand() % BOARD_SIZE;
    insertAtTail(head, player2Move);

    // Winner determination
    int winner = 0;
    for (Node* current = head; current; current = current->next) {
        if (current->data == player1Move && current->next->data == player1Move && current->next->next->data == player1Move) {
            winner = 1;
        } else if (current->data == player2Move && current->next->data == player2Move && current->next->next->data == player2Move) {
            winner = 2;
        }
    }

    // Game result
    if (winner == 1) {
        printf("Player 1 won!");
    } else if (winner == 2) {
        printf("Player 2 won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}