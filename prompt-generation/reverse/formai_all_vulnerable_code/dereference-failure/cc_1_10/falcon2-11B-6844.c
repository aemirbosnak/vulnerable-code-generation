//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int x;
    int y;
    struct Node* next;
};

typedef struct Node Node;

int isWall(int x, int y) {
    return x < 0 || x >= 20 || y < 0 || y >= 20;
}

void print_board(Node* board) {
    for (Node* curr = board; curr!= NULL; curr = curr->next) {
        printf("%d ", curr->x);
    }
    printf("\n");
    for (Node* curr = board; curr!= NULL; curr = curr->next) {
        printf("%d ", curr->y);
    }
    printf("\n");
}

int main() {
    Node* board = NULL;
    Node* curr = NULL;
    int x = 1;
    int y = 1;
    board = (Node*)malloc(sizeof(Node));
    curr = board;
    board->x = x;
    board->y = y;
    board->next = NULL;
    int startx = 10;
    int starty = 10;
    Node* start = (Node*)malloc(sizeof(Node));
    start->x = startx;
    start->y = starty;
    start->next = NULL;
    board = start;
    curr = board;
    while (curr!= NULL) {
        if (isWall(curr->x, curr->y)) {
            curr = curr->next;
            continue;
        }
        if (curr->next == NULL) {
            print_board(board);
            printf("x = %d, y = %d\n", curr->x, curr->y);
            break;
        }
        curr = curr->next;
    }
    return 0;
}