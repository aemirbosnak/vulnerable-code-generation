//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define MAX_ROWS 20
#define MAX_COLS 20

typedef struct invader {
    int x, y, direction, speed;
    struct invader* next;
} invader;

invader* create_invader(int x, int y, int direction, int speed) {
    invader* new_invader = malloc(sizeof(invader));
    new_invader->x = x;
    new_invader->y = y;
    new_invader->direction = direction;
    new_invader->speed = speed;
    new_invader->next = NULL;
    return new_invader;
}

void move_invader(invader* invader) {
    switch (invader->direction) {
        case LEFT:
            invader->x--;
            break;
        case RIGHT:
            invader->x++;
            break;
        case UP:
            invader->y--;
            break;
        case DOWN:
            invader->y++;
            break;
    }
}

int main() {
    invader* head = create_invader(5, 5, RIGHT, 1);
    move_invader(head);
    printf("The invader's new position is: (%d, %d)\n", head->x, head->y);
    return 0;
}