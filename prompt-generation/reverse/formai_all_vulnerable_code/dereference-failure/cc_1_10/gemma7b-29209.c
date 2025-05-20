//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

Cell* createCell(int state, Cell* next) {
    Cell* cell = malloc(sizeof(Cell));
    cell->state = state;
    cell->next = next;
    return cell;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board
    Cell* head = createCell(0, NULL);
    for (int i = 0; i < BOARD_SIZE; i++) {
        head->next = createCell(0, head);
        head = head->next;
    }

    // Play the game
    int player = rand() % 2;
    while (!head->next->next) {
        // Get the move
        int move = rand() % BOARD_SIZE;

        // Place the mark
        Cell* current = head;
        for (int i = 0; i < move; i++) {
            current = current->next;
        }
        current->state = player;

        // Switch players
        player = (player == 0) ? 1 : 0;
    }

    // Print the winner
    Cell* current = head;
    for (int i = 0; i < BOARD_SIZE; i++) {
        current = current->next;
        if (current->state == player) {
            printf("Winner: Player %d\n", player);
            break;
        }
    }

    return 0;
}