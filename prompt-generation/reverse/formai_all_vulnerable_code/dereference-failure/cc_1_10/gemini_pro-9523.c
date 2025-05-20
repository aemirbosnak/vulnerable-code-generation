//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int x;
    int y;
    int color;
} Player;

typedef struct {
    int width;
    int height;
    char *data;
} Canvas;

void draw_canvas(Canvas *canvas) {
    for(int y = 0; y < canvas->height; y++) {
        for(int x = 0; x < canvas->width; x++) {
            printf("%c", canvas->data[y * canvas->width + x]);
        }
        printf("\n");
    }
}

void draw_player(Canvas *canvas, Player *player) {
    canvas->data[player->y * canvas->width + player->x] = player->color;
}

int main() {
    Canvas canvas;
    canvas.width = MAX_WIDTH;
    canvas.height = MAX_HEIGHT;
    canvas.data = malloc(canvas.width * canvas.height);
    memset(canvas.data, ' ', canvas.width * canvas.height);

    Player players[MAX_PLAYERS];
    for(int i = 0; i < MAX_PLAYERS; i++) {
        players[i].x = rand() % canvas.width;
        players[i].y = rand() % canvas.height;
        players[i].color = rand() % 256;
    }

    draw_canvas(&canvas);

    while(1) {
        char input;
        scanf(" %c", &input);

        for(int i = 0; i < MAX_PLAYERS; i++) {
            switch(input) {
                case 'a':
                    players[i].x--;
                    break;
                case 'd':
                    players[i].x++;
                    break;
                case 'w':
                    players[i].y--;
                    break;
                case 's':
                    players[i].y++;
                    break;
                case 'q':
                    return 0;
            }

            draw_player(&canvas, &players[i]);
        }

        draw_canvas(&canvas);
    }

    free(canvas.data);

    return 0;
}