//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVES 100

typedef struct Node {
    int move_num;
    char move_type;
    struct Node* next;
} Node;

Node* create_node(int move_num, char move_type) {
    Node* node = malloc(sizeof(struct Node));
    node->move_num = move_num;
    node->move_type = move_type;
    node->next = NULL;
    return node;
}

void add_move(Node* head, int move_num, char move_type) {
    Node* new_node = create_node(move_num, move_type);
    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
        head = new_node;
    }
}

void print_moves(Node* head) {
    while (head) {
        printf("%d. %c ", head->move_num, head->move_type);
        head = head->next;
    }
}

int main() {
    Node* moves = NULL;
    add_move(moves, 1, 'e');
    add_move(moves, 2, 'a');
    add_move(moves, 3, 'b');
    add_move(moves, 4, 'c');
    add_move(moves, 5, 'd');

    print_moves(moves);

    return 0;
}