//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

int checkWin(Node* head) {
    // Vertical win
    for (int i = 0; i < BOARD_SIZE; i++) {
        Node* temp = head;
        while (temp) {
            if (temp->x == i && temp->y == 0 && temp->next && temp->next->x == i && temp->next->y == 0) {
                return 1;
            }
        }
    }

    // Horizontal win
    for (int j = 0; j < BOARD_SIZE; j++) {
        Node* temp = head;
        while (temp) {
            if (temp->x == 0 && temp->y == j && temp->next && temp->next->x == 0 && temp->next->y == j) {
                return 1;
            }
        }
    }

    // Diagonal win
    for (int d = 0; d < BOARD_SIZE; d++) {
        Node* temp = head;
        while (temp) {
            if (temp->x - temp->y == d && temp->next && temp->next->x - temp->next->y == d) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 0, 0);
    head = insertNode(head, 1, 0);
    head = insertNode(head, 2, 0);
    head = insertNode(head, 0, 1);
    head = insertNode(head, 1, 1);
    head = insertNode(head, 0, 2);

    if (checkWin(head) == 1) {
        printf("Player won!");
    } else {
        printf("No winner");
    }

    return 0;
}