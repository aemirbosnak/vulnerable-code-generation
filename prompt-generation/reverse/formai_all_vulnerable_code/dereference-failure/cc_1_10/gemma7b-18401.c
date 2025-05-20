//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10

#define BULLET_SPEED 5
#define invader_SPEED 3

#define GAME_OVER_MSG "GAME OVER!"
#define LEVEL_UP_MSG "LEVEL UP!"

typedef struct invader {
    int x, y;
    char direction;
    struct invader* next;
} invader;

invader* create_invader(int x, int y) {
    invader* new_invader = malloc(sizeof(invader));
    new_invader->x = x;
    new_invader->y = y;
    new_invader->direction = ' ';
    new_invader->next = NULL;

    return new_invader;
}

void draw_invaders(invader* invaders) {
    for (invader* current = invaders; current; current = current->next) {
        printf("%c", current->x + 1);
    }

    printf("\n");
}

void move_invaders(invader* invaders) {
    for (invader* current = invaders; current; current = current->next) {
        switch (current->direction) {
            case 'r':
                current->x++;
                break;
            case 'l':
                current->x--;
                break;
            case 'u':
                current->y--;
                break;
            case 'd':
                current->y++;
                break;
        }

        if (current->x >= COLS - 1) {
            current->direction = 'u';
        } else if (current->x <= 0) {
            current->direction = 'r';
        }

        if (current->y >= ROWS - 1) {
            current->direction = 'l';
        } else if (current->y <= 0) {
            current->direction = 'd';
        }
    }
}

int main() {
    invader* invaders = create_invader(0, 0);
    invader* current_invader = invaders;

    int score = 0;

    while (!current_invader->next) {
        draw_invaders(invaders);

        move_invaders(invaders);

        score++;

        if (score % 10 == 0) {
            printf("%s\n", LEVEL_UP_MSG);
        }

        if (invaders->x >= COLS - 1 || invaders->x <= 0) {
            printf("%s\n", GAME_OVER_MSG);
            break;
        }
    }

    return 0;
}