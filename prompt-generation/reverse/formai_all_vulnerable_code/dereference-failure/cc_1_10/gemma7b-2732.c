//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define BLOCK_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
    struct Cell* next;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->state = 0;
    cell->next = NULL;
    return cell;
}

void printMap(Cell* head) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            Cell* cell = head;
            while (cell) {
                if (cell->x == x && cell->y == y) {
                    switch (cell->state) {
                        case 0:
                            printf(".");
                            break;
                        case 1:
                            printf("#");
                            break;
                        case 2:
                            printf("$");
                            break;
                        case 3:
                            printf("O");
                            break;
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cell* head = createCell(0, 0);
    head->state = 1;

    Cell* tail = head;
    for (int i = 1; i < MAP_SIZE * MAP_SIZE; i++) {
        tail = createCell(rand() % MAP_SIZE, rand() % MAP_SIZE);
        tail->state = 1;
        tail->next = head;
        head = tail;
    }

    printMap(head);

    return 0;
}