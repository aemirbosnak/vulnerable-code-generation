//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    // Allocates memory for the maze and initializes the head
    *head = (Node*)malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    // Generates the maze randomly
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (rand() % 2 == 0) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->x = i;
                newNode->y = j;
                newNode->next = NULL;
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }
}

void findRoute(Node* head) {
    // Traverses the maze and finds the route
    while (head) {
        // If the current node is the end node, the route is found
        if (head->x == MAX_SIZE - 1 && head->y == MAX_SIZE - 1) {
            printf("The route is found!\n");
            return;
        }

        // Otherwise, move to the next node in the direction of the goal
        if (head->x < MAX_SIZE - 1) {
            head = head->next;
            head->x++;
        } else if (head->y < MAX_SIZE - 1) {
            head = head->next;
            head->y++;
        } else if (head->x > 0) {
            head = head->next;
            head->x--;
        } else if (head->y > 0) {
            head = head->next;
            head->y--;
        }
    }

    // If the end node is not found, the route is not found
    printf("No route found.\n");
}

int main() {
    // Creates a maze
    Node* head = NULL;
    createMaze(&head);

    // Finds the route
    findRoute(head);

    return 0;
}