//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(int size) {
    time_t t = time(NULL);
    srand(t);

    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->x = rand() % size;
        newNode->y = rand() % size;
        newNode->next = head;
        head = newNode;
    }

    // Connect nodes randomly
    for (int i = 0; i < size; i++) {
        Node* current = head;
        for (int j = 0; j < size; j++) {
            if (current->x == j && current->y == i) {
                int direction = rand() % 4;
                switch (direction) {
                    case 0:
                        current->next = head->next;
                        break;
                    case 1:
                        current->next = head->next->next;
                        break;
                    case 2:
                        current->next = head->next->next->next;
                        break;
                    case 3:
                        current->next = head->next->next->next->next;
                        break;
                }
            }
        }
    }
}

int main() {
    generateMaze(MAX_SIZE);

    return 0;
}