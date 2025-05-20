//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(Node** head) {
    int x, y;
    srand(time(NULL));
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = x;
            newNode->y = y;
            newNode->next = NULL;
            *head = newNode;
            head = &newNode->next;
        }
    }
}

void printMaze(Node* head) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            Node* current = head;
            while (current) {
                if (current->x == x && current->y == y) {
                    printf("O ");
                } else {
                    printf("X ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    Node* head = NULL;
    generateMaze(&head);
    printMaze(head);
    return 0;
}