//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef enum CellState { EMPTY, OCCUPIED, BLOCKED } CellState;

typedef struct Node {
    CellState state;
    struct Node* next;
} Node;

Node* createNode(CellState state)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->state = state;
    node->next = NULL;
    return node;
}

void printBoard(Node* head)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            switch (head->state)
            {
                case EMPTY:
                    printf(" ");
                    break;
                case OCCUPIED:
                    printf("X");
                    break;
                case BLOCKED:
                    printf("O");
                    break;
            }
            head = head->next;
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    Node* head = createNode(EMPTY);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        head = createNode(EMPTY);
        head->next = head;
    }

    printBoard(head);

    // Play the game...
}