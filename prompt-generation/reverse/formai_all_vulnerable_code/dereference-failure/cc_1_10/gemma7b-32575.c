//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->name[0] = 'A';
    (*head)->next = NULL;

    Node* tail = *head;
    for (int i = 1; i < MAX_SIZE; i++) {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->name[0] = 'A' + i;
        tail->next = NULL;
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    // Print the maze
    Node* current = head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }

    // Find the exit
    current = head;
    while (strcmp(current->name, "Z") != 0) {
        // Get the direction of the next move
        char direction = getchar();

        // Move in that direction
        switch (direction) {
            case 'N':
                current = current->next;
                break;
            case 'S':
                current = current->next->next;
                break;
            case 'E':
                current = current->next->next->next;
                break;
            case 'W':
                current = current->next->next->next->next;
                break;
            default:
                printf("Invalid direction\n");
                break;
        }
    }

    // You have won!
    printf("Congratulations! You have found the exit.\n");

    return 0;
}