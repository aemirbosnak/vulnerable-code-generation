//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

typedef struct invader {
    int x, y;
    int direction;
    struct invader* next;
} invader;

invader* createInvader(int x, int y) {
    invader* newInvader = malloc(sizeof(invader));
    newInvader->x = x;
    newInvader->y = y;
    newInvader->direction = rand() % 2;
    newInvader->next = NULL;
    return newInvader;
}

void drawInvader(invader* invader) {
    printf("(");
    for (int i = 0; i < invader->x; i++) {
        printf("%c ", ' ');
    }
    printf("%c ", '*');
    for (int i = 0; i < invader->x; i++) {
        printf("%c ", ' ');
    }
    printf(")\n");
}

void moveInvader(invader* invader) {
    switch (invader->direction) {
        case 0:
            invader->x++;
            break;
        case 1:
            invader->x--;
            break;
    }
    if (invader->x >= MAX_WIDTH - 1) {
        invader->direction = 1;
    } else if (invader->x <= 0) {
        invader->direction = 0;
    }
    invader->y++;
}

int main() {
    invader* head = createInvader(0, 0);
    head->next = createInvader(1, 0);
    head->next->next = createInvader(2, 0);

    for (int i = 0; i < 100; i++) {
        moveInvader(head);
        drawInvader(head);
        sleep(0.1);
    }

    return 0;
}