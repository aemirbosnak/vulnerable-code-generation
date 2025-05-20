//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
    int move_type;
    struct Node* next;
    struct Node* prev;
    int piece_type;
    int x_coord;
    int y_coord;
} Node;

void make_move(Node** head, int move_type, int piece_type, int x_coord, int y_coord) {
    Node* new_node = malloc(sizeof(Node));
    new_node->move_type = move_type;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->piece_type = piece_type;
    new_node->x_coord = x_coord;
    new_node->y_coord = y_coord;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void print_board(Node* head) {
    while (head) {
        switch (head->piece_type) {
            case 0:
                printf("P");
                break;
            case 1:
                printf("R");
                break;
            case 2:
                printf("N");
                break;
            case 3:
                printf("B");
                break;
            case 4:
                printf("Q");
                break;
            case 5:
                printf("K");
                break;
            default:
                printf("E");
                break;
        }
        printf(" (%d, %d) ", head->x_coord, head->y_coord);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    make_move(&head, 0, 1, 0, 0);
    make_move(&head, 1, 3, 0, 1);
    make_move(&head, 0, 4, 1, 0);
    make_move(&head, 2, 2, 2, 0);
    print_board(head);

    return 0;
}