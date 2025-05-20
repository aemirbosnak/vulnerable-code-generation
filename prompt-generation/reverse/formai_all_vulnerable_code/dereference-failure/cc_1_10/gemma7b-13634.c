//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define PLAYER_SIZE 2
#define BALL_SIZE 2

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void DrawMap(Node* head) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Node* current = head;
            while (current) {
                if (current->x == x && current->y == y) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create the map
    Node* head = CreateNode(0, 0);
    head->next = CreateNode(1, 0);
    head->next->next = CreateNode(2, 0);
    head->next->next->next = CreateNode(3, 0);
    head->next->next->next->next = CreateNode(4, 0);

    // Draw the map
    DrawMap(head);

    // Move the player
    head->x = 2;
    head->y = 2;

    // Draw the map again
    DrawMap(head);

    return 0;
}