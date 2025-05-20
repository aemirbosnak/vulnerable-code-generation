//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            *head = malloc(sizeof(Node));
            (*head)->x = i;
            (*head)->y = j;
            (*head)->next = NULL;
            head++;
        }
    }
}

void solveMaze(Node* head) {
    int x, y;
    scanf("Enter the starting x: ", &x);
    scanf("Enter the starting y: ", &y);

    // Traverse the maze
    while (head) {
        if (head->x == x && head->y == y) {
            printf("Congratulations! You have found the end of the maze.\n");
            return;
        } else if (head->x == -1 || head->y == -1) {
            printf("Game over! You have reached the boundary of the maze.\n");
            return;
        } else {
            printf("Current position: (%d, %d)\n", head->x, head->y);
            printf("Enter the direction (N, S, E, W): ");
            char direction;
            scanf("%c", &direction);

            switch (direction) {
                case 'N':
                    head->y--;
                    break;
                case 'S':
                    head->y++;
                    break;
                case 'E':
                    head->x++;
                    break;
                case 'W':
                    head->x--;
                    break;
            }
        }
    }

    printf("You have reached the end of the maze or exceeded the boundary.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    solveMaze(head);
    return 0;
}