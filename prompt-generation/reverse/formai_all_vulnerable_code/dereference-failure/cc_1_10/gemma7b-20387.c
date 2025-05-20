//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 64
#define MOVE_LIMIT 4

typedef struct Node {
    int move_num;
    struct Node* next;
    char board[BOARD_SIZE];
} Node;

Node* insert_node(Node* head, int move_num, char board[]) {
    Node* newNode = malloc(sizeof(Node));
    newNode->move_num = move_num;
    newNode->next = NULL;
    memcpy(newNode->board, board, BOARD_SIZE);

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

void print_board(char board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", board[i]);
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Simulate a few moves
    insert_node(head, 1, "RNBQKB");
    insert_node(head, 2, "RNBNQKB");
    insert_node(head, 3, "RNBQQKB");

    print_board(head->board);

    return 0;
}