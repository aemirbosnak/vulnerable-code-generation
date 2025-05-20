//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Linus Torvalds
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct invader_s {
    int x, y;
    struct invader_s* next;
} invader_t;

invader_t* invaders_create(int num_invaders)
{
    invader_t* head = malloc(sizeof(invader_t) * num_invaders);
    for (int i = 0; i < num_invaders; i++) {
        head[i].x = i;
        head[i].y = 0;
        head[i].next = NULL;
    }
    return head;
}

void invaders_move(invader_t* head)
{
    for (invader_t* inv = head; inv; inv = inv->next) {
        inv->x++;
        if (inv->x >= MAX_WIDTH - 1) {
            inv->y++;
            inv->x = 0;
        }
    }
}

void invaders_draw(invader_t* head)
{
    for (invader_t* inv = head; inv; inv = inv->next) {
        printf(" ");
        for (int i = 0; i < inv->x; i++) {
            printf("%c", '#');
        }
        printf("%c", '\n');
    }
}

int main()
{
    srand(time(NULL));
    invader_t* invaders = invaders_create(10);
    invaders_move(invaders);
    invaders_draw(invaders);

    return 0;
}