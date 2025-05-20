//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
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

void addCell(Cell* head, int x, int y) {
    Cell* newCell = createCell(x, y);
    if (head == NULL) {
        head = newCell;
    } else {
        Cell* traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newCell;
    }
}

void drawBoard(Cell* head) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Cell* currentCell = head;
            while (currentCell) {
                if (currentCell->x == x && currentCell->y == y) {
                    printf("O ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cell* head = NULL;
    int score = 0;

    // Place the breakout bricks
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            addCell(head, i, j);
        }
    }

    // The ball
    Cell* ball = createCell(5, 0);

    // Game loop
    while (!head->next) {
        drawBoard(head);

        // Move the ball
        ball->x += rand() % 2 - 1;
        ball->y -= 1;

        // Check if the ball has hit a brick
        if (ball->x < 0 || ball->x >= BOARD_SIZE) {
            ball->x = rand() % BOARD_SIZE;
            ball->y = 0;
            score++;
        } else if (ball->y < 0) {
            printf("Game Over! Your score is: %d", score);
            break;
        }

        // Sleep
        sleep(0.1);
    }

    return 0;
}