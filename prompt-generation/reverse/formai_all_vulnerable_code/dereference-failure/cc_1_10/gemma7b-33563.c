//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void addNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int getRandomMove(Node* head) {
    srand(time(NULL));
    int move = rand() % 9;
    while (head->x == move / BOARD_SIZE && head->y == move % BOARD_SIZE) {
        move = rand() % 9;
    }
    return move;
}

int main() {
    Node* board = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            addNode(board, i, j);
        }
    }

    int move = getRandomMove(board);
    printf("The AI's move is: (%d, %d)\n", move / BOARD_SIZE, move % BOARD_SIZE);

    return 0;
}