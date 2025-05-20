//Gemma-7B DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Wall {
    Node* head;
    Node* tail;
} Wall;

Wall* createWall() {
    Wall* wall = malloc(sizeof(Wall));
    wall->head = NULL;
    wall->tail = NULL;
    return wall;
}

void addToWall(Wall* wall, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (wall->head == NULL) {
        wall->head = newNode;
        wall->tail = newNode;
    } else {
        wall->tail->next = newNode;
        wall->tail = newNode;
    }
}

int main() {
    Wall* wall = createWall();
    addToWall(wall, 'a');
    addToWall(wall, 'b');
    addToWall(wall, 'c');
    addToWall(wall, 'd');

    for (Node* node = wall->head; node; node = node->next) {
        printf("%c ", node->data);
    }

    printf("\n");

    return 0;
}