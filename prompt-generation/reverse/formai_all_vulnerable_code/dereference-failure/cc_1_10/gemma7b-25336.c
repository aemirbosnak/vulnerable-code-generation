//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    *head = NULL;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
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

int main() {
    Node* head = NULL;
    createMaze(&head);

    // Generate a random path
    srand(time(NULL));
    int path_length = rand() % 10 + 1;
    Node* current = head;
    for (int i = 0; i < path_length; i++) {
        current = current->next;
    }

    // Print the path
    current = head;
    while (current) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }

    return 0;
}