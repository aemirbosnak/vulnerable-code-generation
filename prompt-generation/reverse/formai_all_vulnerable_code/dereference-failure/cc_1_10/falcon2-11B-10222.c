//Falcon2-11B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

typedef struct {
    int x;
    int y;
    int width;
    int height;
    char color;
} Sprite;

typedef struct {
    Sprite* sprites;
    int numSprites;
} Game;

Game createGame(void) {
    Game game;
    game.sprites = malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Sprite));
    game.numSprites = SCREEN_WIDTH * SCREEN_HEIGHT;
    return game;
}

void drawGame(Game* game) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            int spriteIndex = y * SCREEN_WIDTH + x;
            if (spriteIndex >= game->numSprites) {
                continue;
            }
            Sprite* sprite = &game->sprites[spriteIndex];
            switch (sprite->color) {
                case 'X':
                    printf("X ");
                    break;
                case 'O':
                    printf("O ");
                    break;
                default:
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    Game game = createGame();

    while (1) {
        drawGame(&game);
        printf("Press any key to continue...");
        getchar();
        drawGame(&game);
        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}