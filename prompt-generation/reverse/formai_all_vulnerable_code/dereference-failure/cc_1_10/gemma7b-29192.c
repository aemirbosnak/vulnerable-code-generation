//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generate_maze(Node** head) {
    time_t t = time(NULL);
    srand(t);

    *head = malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            (*head)->next = newNode;
            *head = newNode;
        }
    }

    // Randomly connect nodes
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            Node* current = (*head)->next;
            while (current) {
                if (current->x != i || current->y != j) {
                    int chance = rand() % 10;
                    if (chance == 0) {
                        current->next = malloc(sizeof(Node));
                        current->next->x = i;
                        current->next->y = j;
                        current->next->next = NULL;
                        current = current->next;
                    }
                }
            }
        }
    }
}

int main() {
    Node* head = NULL;
    generate_maze(&head);

    return 0;
}