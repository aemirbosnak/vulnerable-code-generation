//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WINDOW_WIDTH  80
#define WINDOW_HEIGHT 25

typedef struct {
    char letter;
    int x, y;
} position_t;

typedef struct {
    position_t current;
    position_t next;
} game_t;

game_t* game;

void init_game(void) {
    game = malloc(sizeof(game_t));
    game->current.letter = 'A';
    game->current.x = 0;
    game->current.y = 0;
    game->next.letter = 'A';
    game->next.x = 0;
    game->next.y = 0;
}

void print_game(void) {
    printf("   A   B   C   D   E   F   G   H   I   J\n");
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        for (int j = 0; j < WINDOW_WIDTH; j++) {
            char cell = game->current.letter;
            if (cell == 'A') {
                printf("   %c   ", cell);
            } else {
                printf("  %c   ", cell);
            }
            game->current.x = j;
            game->current.y = i;
            game->next.x = j;
            game->next.y = i + 1;
            if (game->next.y >= WINDOW_HEIGHT) {
                game->next.y = 0;
            }
            if (game->next.x >= WINDOW_WIDTH) {
                game->next.x = 0;
            }
            game->current = game->next;
        }
        printf("\n");
    }
}

void move_up(void) {
    if (game->current.y > 0) {
        game->current.y -= 1;
        game->next.y -= 1;
    }
}

void move_down(void) {
    if (game->current.y < WINDOW_HEIGHT - 1) {
        game->current.y += 1;
        game->next.y += 1;
    }
}

void move_left(void) {
    if (game->current.x > 0) {
        game->current.x -= 1;
        game->next.x -= 1;
    }
}

void move_right(void) {
    if (game->current.x < WINDOW_WIDTH - 1) {
        game->current.x += 1;
        game->next.x += 1;
    }
}

int main(void) {
    init_game();
    while (1) {
        print_game();
        switch (getchar()) {
            case 'A':
                move_left();
                break;
            case 'B':
                move_up();
                break;
            case 'C':
                move_right();
                break;
            case 'D':
                move_down();
                break;
            default:
                break;
        }
    }
    return 0;
}