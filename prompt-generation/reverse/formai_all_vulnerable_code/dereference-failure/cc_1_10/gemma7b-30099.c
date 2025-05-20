//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int row, col;
    struct Node* next;
} Node;

Node* newNode(int row, int col) {
    Node* node = malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->next = NULL;
    return node;
}

int isBoardFull(Node* head) {
    while (head) {
        if (head->row == 0 && head->col == 0) {
            return 0;
        }
        head = head->next;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    Node* head = newNode(0, 0);
    head->next = newNode(1, 0);
    head->next->next = newNode(2, 0);
    head->next->next->next = newNode(0, 1);
    head->next->next->next->next = newNode(1, 1);
    head->next->next->next->next->next = newNode(2, 1);
    head->next->next->next->next->next->next = newNode(0, 2);
    head->next->next->next->next->next->next->next = newNode(1, 2);
    head->next->next->next->next->next->next->next->next = newNode(2, 2);

    int move = rand() % 9;
    switch (move) {
        case 0:
            head->row = 0;
            head->col = 0;
            break;
        case 1:
            head->row = 1;
            head->col = 0;
            break;
        case 2:
            head->row = 2;
            head->col = 0;
            break;
        case 3:
            head->row = 0;
            head->col = 1;
            break;
        case 4:
            head->row = 1;
            head->col = 1;
            break;
        case 5:
            head->row = 2;
            head->col = 1;
            break;
        case 6:
            head->row = 0;
            head->col = 2;
            break;
        case 7:
            head->row = 1;
            head->col = 2;
            break;
        case 8:
            head->row = 2;
            head->col = 2;
            break;
    }

    if (isBoardFull(head) || head->row == head->col) {
        printf("Game Over!");
    } else {
        printf("Next Move:");
    }

    return 0;
}