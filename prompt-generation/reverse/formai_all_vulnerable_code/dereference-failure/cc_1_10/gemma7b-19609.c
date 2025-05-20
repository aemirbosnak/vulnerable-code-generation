//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int checkWin(Node* head) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        int win = 1;
        for (int c = 0; c < BOARD_SIZE; c++) {
            Node* node = head;
            while (node) {
                if (node->x == r && node->y == c) {
                    if (node->next && node->next->x == r && node->next->y == c) {
                        win = 0;
                    }
                }
            }
            if (win) {
                return 1;
            }
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        int win = 1;
        for (int r = 0; r < BOARD_SIZE; r++) {
            Node* node = head;
            while (node) {
                if (node->x == r && node->y == c) {
                    if (node->next && node->next->x == r && node->next->y == c) {
                        win = 0;
                    }
                }
            }
            if (win) {
                return 1;
            }
        }
    }

    // Check diagonals
    for (int d = 0; d < BOARD_SIZE; d++) {
        int win = 1;
        for (int r = 0; r < BOARD_SIZE; r++) {
            for (int c = 0; c < BOARD_SIZE; c++) {
                Node* node = head;
                while (node) {
                    if (node->x == r && node->y == c) {
                        if (node->next && node->next->x == r - d && node->next->y == c + d) {
                            win = 0;
                        }
                    }
                }
            }
            if (win) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 0, 2);
    insertNode(head, 1, 2);
    insertNode(head, 2, 2);

    if (checkWin(head)) {
        printf("Player won!");
    } else {
        printf("No winner");
    }

    return 0;
}