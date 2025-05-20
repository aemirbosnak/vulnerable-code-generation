//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            ((*head)->next) = newNode;
            head = &newNode;
        }
    }
}

void findRoute(Node* head) {
    int x, y;
    scanf("Enter the starting x: ", &x);
    scanf("Enter the starting y: ", &y);

    printf("Enter the destination x: ");
    int destX;
    scanf("%d", &destX);

    printf("Enter the destination y: ");
    int destY;
    scanf("%d", &destY);

    Node* current = head;
    while (current) {
        if (current->x == destX && current->y == destY) {
            printf("The route is found!\n");
            break;
        } else if (current->x == x && current->y == y) {
            printf("Current position: (%d, %d)\n", current->x, current->y);
            current = current->next;
        } else {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No route found.\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head);

    return 0;
}