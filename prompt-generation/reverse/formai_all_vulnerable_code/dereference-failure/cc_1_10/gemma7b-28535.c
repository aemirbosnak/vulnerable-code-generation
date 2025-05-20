//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize_map(int** map, int size) {
    map = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        map[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            map[i][j] = -1;
        }
    }
}

void print_map(int** map, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void find_path(int** map, int size, int x, int y) {
    Node* head = NULL;
    Node* current = NULL;
    map[x][y] = 0;

    if (head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        current = head;
        current->x = x;
        current->y = y;
        current->next = NULL;
    } else {
        current = (Node*)malloc(sizeof(Node));
        current->x = x;
        current->y = y;
        current->next = NULL;
        head->next = current;
        current = head;
    }

    while (current) {
        if (current->x == x && current->y == y) {
            return;
        }

        if (current->x - 1 >= 0 && map[current->x - 1][current->y] == -1) {
            map[current->x - 1][current->y] = 0;
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = current->x - 1;
            current->next->y = current->y;
            current->next->next = NULL;
            current = current->next;
        }

        if (current->x + 1 < size && map[current->x + 1][current->y] == -1) {
            map[current->x + 1][current->y] = 0;
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = current->x + 1;
            current->next->y = current->y;
            current->next->next = NULL;
            current = current->next;
        }

        if (current->y - 1 >= 0 && map[current->x][current->y - 1] == -1) {
            map[current->x][current->y - 1] = 0;
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = current->x;
            current->next->y = current->y - 1;
            current->next->next = NULL;
            current = current->next;
        }

        if (current->y + 1 < size && map[current->x][current->y + 1] == -1) {
            map[current->x][current->y + 1] = 0;
            current->next = (Node*)malloc(sizeof(Node));
            current->next->x = current->x;
            current->next->y = current->y + 1;
            current->next->next = NULL;
            current = current->next;
        }
    }
}

int main() {
    int size = MAX_SIZE;
    int** map = NULL;

    initialize_map(map, size);

    find_path(map, size, 0, 0);

    print_map(map, size);

    return 0;
}