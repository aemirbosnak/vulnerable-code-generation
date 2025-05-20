//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void generateMaze(int size) {
    int i, j;
    Node* head = NULL;
    time_t t = time(NULL);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            Node* newNode = createNode(i, j);
            if (head == NULL) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }
    }

    // Randomly remove walls
    srand(t);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (rand() % 2 == 0) {
                Node* current = head;
                while (current) {
                    if (current->x == i && current->y == j) {
                        current->next = NULL;
                        break;
                    }
                    current = current->next;
                }
            }
        }
    }
}

int main() {
    generateMaze(MAX_SIZE);
    return 0;
}