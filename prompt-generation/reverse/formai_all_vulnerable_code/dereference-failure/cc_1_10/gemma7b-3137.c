//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

typedef struct Map {
    int** grid;
    Node* head;
} Map;

Map* createMap() {
    Map* map = malloc(sizeof(Map));
    map->grid = malloc(MAX_SIZE * sizeof(int*));
    for (int i = 0; i < MAX_SIZE; i++) {
        map->grid[i] = malloc(MAX_SIZE * sizeof(int));
    }
    map->head = NULL;
    return map;
}

void addToMap(Map* map, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = map->head;
    map->head = newNode;
}

void findPath(Map* map, int x, int y) {
    Node* current = map->head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("Path found!\n");
            return;
        }
        current = current->next;
    }
    printf("Path not found.\n");
}

int main() {
    Map* map = createMap();
    addToMap(map, 0, 0);
    addToMap(map, 1, 0);
    addToMap(map, 2, 0);
    addToMap(map, 3, 0);
    addToMap(map, 3, 1);
    addToMap(map, 3, 2);
    addToMap(map, 3, 3);
    findPath(map, 0, 3);

    return 0;
}