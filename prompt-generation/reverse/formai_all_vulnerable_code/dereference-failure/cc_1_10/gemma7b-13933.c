//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(Node* tail, int data) {
    Node* newNode = createNode(data);
    if (tail) {
        tail->next = newNode;
    } else {
        tail = newNode;
    }
    return;
}

int main() {
    int boardSize = MAX_BOARD_SIZE;
    Node* head = NULL;
    time_t t;

    // Initialize the board
    for (int i = 0; i < boardSize * boardSize; i++) {
        insertAtTail(head, -1);
    }

    // Seed the random number generator
    srand(time(&t));

    // Get the player's move
    int move = rand() % boardSize * boardSize;

    // Make the move
    insertAtTail(head, move);

    // Print the board
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }

    return 0;
}