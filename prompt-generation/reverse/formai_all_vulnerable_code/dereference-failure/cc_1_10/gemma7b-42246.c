//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 20

typedef struct invader_s {
    int x;
    int y;
    int direction;
    struct invader_s* next;
} invader_t;

invader_t* create_invader(int x, int y, int direction) {
    invader_t* invader = malloc(sizeof(invader_t));
    invader->x = x;
    invader->y = y;
    invader->direction = direction;
    invader->next = NULL;
    return invader;
}

void move_invader(invader_t* invader) {
    switch (invader->direction) {
        case 0:
            invader->x++;
            break;
        case 1:
            invader->x--;
            break;
        case 2:
            invader->y++;
            break;
        case 3:
            invader->y--;
            break;
    }
}

void draw_invaders(invader_t* invader) {
    printf("(");
    for (invader_t* current = invader; current; current = current->next) {
        printf("%d, %d ", current->x, current->y);
        if (current->next) {
            printf(",");
        }
    }
    printf(")\n");
}

int main() {
    invader_t* head = create_invader(0, 0, 0);
    move_invader(head);
    draw_invaders(head);

    return 0;
}