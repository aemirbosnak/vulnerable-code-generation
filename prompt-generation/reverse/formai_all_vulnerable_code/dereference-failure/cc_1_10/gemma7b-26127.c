//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLS 20
#define MAX_ROWS 10

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
}

void drawInvader(invader* invader) {
    printf("(");
    for (int i = 0; i < invader->x; i++) {
        printf(" ");
    }
    printf("%c", invader->y + 1);
    for (int i = 0; i < invader->x; i++) {
        printf(" ");
    }
    printf(")\n");
}

int main() {
    invader* head = createInvader(0, 0);
    head->next = createInvader(1, 0);
    head->next->next = createInvader(2, 0);
    head->next->next->next = createInvader(3, 0);

    for (int i = 0; i < 10; i++) {
        moveInvader(head);
        drawInvader(head);
        sleep(1);
    }

    return 0;
}