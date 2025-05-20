//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Turing
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

int IsBoardFull(Node* head) {
    for (Node* node = head; node; node = node->next) {
        if (node->x == -1) {
            return 0;
        }
    }
    return 1;
}

int GetRandomMove(Node* head) {
    srand(time(NULL));
    int r = rand() % 9;
    int x = r / BOARD_SIZE;
    int y = r % BOARD_SIZE;
    while (IsMoveValid(x, y, head) == 0) {
        r = rand() % 9;
        x = r / BOARD_SIZE;
        y = r % BOARD_SIZE;
    }
    return x * BOARD_SIZE + y;
}

int IsMoveValid(int x, int y, Node* head) {
    for (Node* node = head; node; node = node->next) {
        if (node->x == x && node->y == y) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Node* head = CreateNode(0, 0);
    head->next = CreateNode(1, 0);
    head->next->next = CreateNode(2, 0);
    head->next->next->next = CreateNode(0, 1);
    head->next->next->next->next = CreateNode(1, 1);
    head->next->next->next->next->next = CreateNode(2, 1);
    head->next->next->next->next->next->next = CreateNode(0, 2);
    head->next->next->next->next->next->next->next = CreateNode(1, 2);
    head->next->next->next->next->next->next->next->next = CreateNode(2, 2);

    int move = GetRandomMove(head);
    printf("%d", move);

    return 0;
}