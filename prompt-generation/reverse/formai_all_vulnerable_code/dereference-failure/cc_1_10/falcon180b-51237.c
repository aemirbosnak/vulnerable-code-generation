//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define CHARSET_SIZE 94
#define DELAY 100000 // 100ms

// Character set
char charset[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void init_screen() {
    system("clear");
    printf("\033[2J");
}

void draw_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_screen();

    int font_size = rand() % 3 + 1;
    char *ascii_art = malloc(WIDTH * HEIGHT * sizeof(char));
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int c = rand() % CHARSET_SIZE;
            ascii_art[y * WIDTH + x] = charset[c];
        }
    }

    int delay_time = DELAY / font_size;
    int count = 0;

    while (1) {
        system("clear");
        printf("\033[2J");
        draw_ascii_art(ascii_art);
        printf("\033[1;1H");
        printf("Press any key to generate a new ASCII art... ");

        int c = getchar();
        if (c == '\n') {
            count++;
            if (count % 10 == 0) {
                font_size++;
                if (font_size > 3) {
                    font_size = 1;
                }
                delay_time = DELAY / font_size;
            }
        }
    }

    free(ascii_art);
    return 0;
}