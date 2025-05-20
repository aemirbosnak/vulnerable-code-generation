//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 40

typedef struct invader {
    int x;
    int y;
    int direction;
    struct invader* next;
} invader;

invader* createInvader(int x, int y) {
    invader* newInvader = malloc(sizeof(invader));
    newInvader->x = x;
    newInvader->y = y;
    newInvader->direction = 1;
    newInvader->next = NULL;
    return newInvader;
}

void drawInvader(invader* invader) {
    printf("(");
    for (int i = 0; i < invader->x; i++) {
        printf("%c ", '#');
    }
    printf("%c ", invader->y);
    for (int i = invader->x; i < MAX_COLS; i++) {
        printf("%c ", ' ');
    }
    printf(")\n");
}

void moveInvader(invader* invader) {
    switch (invader->direction) {
        case 1:
            invader->x++;
            break;
        case 2:
            invader->x--;
            break;
        case 3:
            invader->y++;
            break;
        case 4:
            invader->y--;
            break;
    }

    if (invader->x == MAX_COLS - 1) {
        invader->direction = 2;
    } else if (invader->x == 0) {
        invader->direction = 1;
    }

    if (invader->y == MAX_ROWS - 1) {
        invader->direction = 4;
    } else if (invader->y == 0) {
        invader->direction = 3;
    }
}

int main() {
    invader* head = createInvader(0, 0);
    head->next = createInvader(1, 0);
    head->next->next = createInvader(2, 0);

    while (1) {
        drawInvader(head);
        moveInvader(head);

        if (head->next == NULL) {
            printf("Game Over!\n");
            break;
        }

        sleep(0.1);
    }

    return 0;
}