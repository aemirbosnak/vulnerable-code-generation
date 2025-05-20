//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define PLAYER_SIZE 2
#define WALL_SIZE 1

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void initializeMap(Node** map) {
    *map = NULL;
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            *map = malloc(sizeof(Node));
            (*map)->x = x;
            (*map)->y = y;
            (*map)->next = NULL;
            map++;
        }
    }
}

void drawMap(Node* map) {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            Node* current = map;
            while (current) {
                if (current->x == x && current->y == y) {
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
    Node** map = NULL;
    initializeMap(map);

    drawMap(map);

    return 0;
}