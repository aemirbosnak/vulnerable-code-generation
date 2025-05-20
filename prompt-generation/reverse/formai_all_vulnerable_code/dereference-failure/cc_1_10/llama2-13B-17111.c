//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PATH_LEN 20
#define MAZE_SIZE 100

struct path {
    char name[PATH_LEN];
    int length;
};

struct node {
    char name[PATH_LEN];
    int x, y;
    struct node *next;
};

struct node *start, *end, *current;

void init_maze() {
    start = (struct node *) malloc(sizeof(struct node));
    end = (struct node *) malloc(sizeof(struct node));
    current = start;

    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == 0 || j == 0 || i == MAZE_SIZE - 1 || j == MAZE_SIZE - 1) {
                current->name[0] = ' ';
                current->x = i;
                current->y = j;
                current->next = NULL;
                if (i == 0 || j == 0) {
                    start = current;
                } else if (i == MAZE_SIZE - 1 || j == MAZE_SIZE - 1) {
                    end = current;
                }
                current = current->next;
            } else {
                char dir = (rand() % 2) ? 'L' : 'R';
                current->name[0] = dir;
                current->x += (dir == 'L' ? -1 : 1);
                current->y += (dir == 'U' ? -1 : 1);
                current->next = (struct node *) malloc(sizeof(struct node));
                current = current->next;
            }
        }
    }
}

void move(char dir) {
    current = current->next;
    if (dir == 'L' || dir == 'R') {
        current->x += (dir == 'L' ? -1 : 1);
    } else if (dir == 'U' || dir == 'D') {
        current->y += (dir == 'U' ? -1 : 1);
    }
}

void print_maze() {
    for (struct node *node = start; node != NULL; node = node->next) {
        printf("%c", node->name[0]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    init_maze();

    printf("Welcome to the Magical Forest!\n");
    printf("Your goal is to reach the enchanted crystal at the center of the forest.\n");
    printf("You start at the entrance of the forest, and must navigate through the maze of paths to reach the crystal.\n");
    printf("You can move in four directions: North, South, East, and West. Type 'n', 's', 'e', or 'w' to move in that direction.\n");

    while (1) {
        char dir = getchar();
        move(dir);
        print_maze();
    }

    return 0;
}