//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: surprised
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

typedef struct Cell {
    int x, y;
    struct Cell* next;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->next = NULL;
    return cell;
}

void addCell(Cell* cell, Cell* newCell) {
    cell->next = newCell;
}

void drawBoard(Cell* head) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Cell* currentCell = head;
            while (currentCell) {
                if (currentCell->x == x && currentCell->y == y) {
                    printf("O ");
                } else {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cell* head = createCell(0, 0);
    addCell(head, createCell(1, 0));
    addCell(head, createCell(2, 0));
    addCell(head, createCell(3, 0));

    drawBoard(head);

    return 0;
}