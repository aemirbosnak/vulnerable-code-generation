//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10
#define BLOCK_SIZE 20

typedef struct Block {
    int x, y;
    struct Block* next;
} Block;

Block* CreateBlock(int x, int y) {
    Block* block = malloc(sizeof(Block));
    block->x = x;
    block->y = y;
    block->next = NULL;
    return block;
}

void DestroyBlock(Block* block) {
    free(block);
}

void DrawMap(Block* head) {
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            Block* currentBlock = head;
            while (currentBlock) {
                if (currentBlock->x == x && currentBlock->y == y) {
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
    Block* head = CreateBlock(0, 0);
    head->next = CreateBlock(1, 0);
    head->next->next = CreateBlock(2, 0);
    head->next->next->next = CreateBlock(3, 0);

    DrawMap(head);

    DestroyBlock(head);

    return 0;
}