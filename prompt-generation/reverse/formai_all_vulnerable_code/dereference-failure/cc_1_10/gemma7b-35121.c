//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10

typedef struct invader {
    int x, y;
    char direction;
    struct invader* next;
} invader;

invader* createInvader() {
    invader* newInvader = (invader*)malloc(sizeof(invader));
    newInvader->x = 0;
    newInvader->y = 0;
    newInvader->direction = 'r';
    newInvader->next = NULL;
    return newInvader;
}

void drawInvader(invader* invader) {
    printf("%c", invader->x + 1);
    printf("%c", invader->y + 1);
    printf(" ");
}

void moveInvader(invader* invader) {
    switch (invader->direction) {
        case 'r':
            invader->x++;
            break;
        case 'l':
            invader->x--;
            break;
        case 'u':
            invader->y--;
            break;
        case 'd':
            invader->y++;
            break;
    }
}

int main() {
    invader* head = createInvader();
    drawInvader(head);

    // Game loop
    while (1) {
        moveInvader(head);
        drawInvader(head);

        if (head->x >= COLS - 1) {
            head->direction = 'l';
        } else if (head->x <= 0) {
            head->direction = 'r';
        }

        if (head->y >= ROWS - 1) {
            // Game over
            break;
        }

        sleep(0.1);
    }

    return 0;
}