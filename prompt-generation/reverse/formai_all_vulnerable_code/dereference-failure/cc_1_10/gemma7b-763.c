//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

typedef struct Circle {
    int radius;
    struct Node* head;
} Circle;

Circle* createCircle(int radius) {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->radius = radius;
    circle->head = NULL;
    return circle;
}

void insertNode(Circle* circle, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (circle->head == NULL) {
        circle->head = newNode;
    } else {
        Node* lastNode = circle->head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void printCircle(Circle* circle) {
    Node* node = circle->head;
    while (node) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->next;
    }
}

int main() {
    Circle* circle = createCircle(5);
    insertNode(circle, 1, 1);
    insertNode(circle, 2, 2);
    insertNode(circle, 3, 3);
    insertNode(circle, 4, 4);
    insertNode(circle, 5, 5);

    printCircle(circle);

    return 0;
}