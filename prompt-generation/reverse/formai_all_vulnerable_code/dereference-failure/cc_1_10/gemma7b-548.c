//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 20
#define PILE_WIDTH 5

#define LEFT_BOUND 0
#define RIGHT_BOUND (MAX_PILES - 1)

typedef struct Block {
    int x, y;
    struct Block* next;
} Block;

Block* createBlock(int x, int y) {
    Block* newBlock = malloc(sizeof(Block));
    newBlock->x = x;
    newBlock->y = y;
    newBlock->next = NULL;
    return newBlock;
}

void moveBlock(Block* block, int dx, int dy) {
    block->x += dx;
    block->y += dy;
}

int main() {
    Block* head = createBlock(LEFT_BOUND, 0);
    head->next = createBlock(RIGHT_BOUND, 0);
    head->next->next = createBlock(LEFT_BOUND, 1);
    head->next->next->next = createBlock(RIGHT_BOUND, 1);

    int direction = 1;
    int speed = 1;

    while (head) {
        moveBlock(head, direction * speed, 0);

        if (head->x == LEFT_BOUND || head->x == RIGHT_BOUND) {
            direction *= -1;
        }

        printf("Block position: (%d, %d)\n", head->x, head->y);

        head = head->next;
    }

    return 0;
}