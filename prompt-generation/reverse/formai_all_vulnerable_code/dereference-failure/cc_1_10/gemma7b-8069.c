//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void generateMaze(Node* head) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            head->next = newNode;
            head = newNode;
        }
    }
}

void findRoute(Node* head) {
    srand(time(NULL));
    int startx = rand() % MAZE_SIZE;
    int starty = rand() % MAZE_SIZE;
    Node* current = head;
    current->x = startx;
    current->y = starty;

    int goalx = rand() % MAZE_SIZE;
    int goaly = rand() % MAZE_SIZE;
    Node* goal = head;
    goal->x = goalx;
    goal->y = goaly;

    while (current->x != goal->x || current->y != goal->y) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                current->x--;
                break;
            case 1:
                current->x++;
                break;
            case 2:
                current->y--;
                break;
            case 3:
                current->y++;
                break;
        }
        current = current->next;
    }

    printf("The route from (%d, %d) to (%d, %d) is:", startx, starty, goalx, goaly);
    printf("\n");
    current = head;
    while (current) {
        if (current->x == startx && current->y == starty) {
            printf("Start: (%d, %d)\n", current->x, current->y);
        } else if (current->x == goalx && current->y == goaly) {
            printf("Goal: (%d, %d)\n", current->x, current->y);
        } else {
            printf("(%d, %d)\n", current->x, current->y);
        }
        current = current->next;
    }
}

int main() {
    Node* head = malloc(sizeof(Node));
    generateMaze(head);
    findRoute(head);
    return 0;
}