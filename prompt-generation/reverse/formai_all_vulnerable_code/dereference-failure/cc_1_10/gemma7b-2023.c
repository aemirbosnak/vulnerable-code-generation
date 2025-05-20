//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void initializeMaze(Node** head) {
    *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            if (*head == NULL) {
                *head = newNode;
            } else {
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }
}

void findRoute(Node* head) {
    int targetX = rand() % MAX_SIZE;
    int targetY = rand() % MAX_SIZE;

    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Congratulations! You found the target.\n");
            break;
        } else {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("Sorry, the target was not found.\n");
    }
}

int main() {
    Node** head = NULL;
    initializeMaze(head);
    findRoute(head);

    return 0;
}