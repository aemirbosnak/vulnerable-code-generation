//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

typedef struct invader {
    int x, y;
    char direction;
    struct invader* next;
} invader;

invader* createInvader(int x, int y, char direction) {
    invader* newInvader = malloc(sizeof(invader));
    newInvader->x = x;
    newInvader->y = y;
    newInvader->direction = direction;
    newInvader->next = NULL;
    return newInvader;
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
    invader* head = createInvader(0, 0, 'r');
    invader* tail = head;
    for (int i = 1; i < COLS; i++) {
        tail = createInvader(i, 0, 'r');
        tail->next = head;
        head = tail;
    }

    head = tail;
    for (int j = 1; j < ROWS; j++) {
        for (int i = 0; i < COLS; i++) {
            moveInvader(head);
            printf("%c ", head->x + 1);
        }
        printf("\n");
    }

    return 0;
}