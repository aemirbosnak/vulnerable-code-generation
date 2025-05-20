//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char* font[] = {
    " _    _     _  __  __    __ ",
    "| |  | |   | |\\ \\/ /   / / ",
    "| |__| | __| | \\  /   / /  ",
    "|  __  |/ _` |  \\/   / /   ",
    "| |  | | (_| |   |   /_/    ",
    "|_|  |_|\__,_|   |_|(_)     "
};

unsigned char* screen;

void clear_screen() {
    memset(screen, ' ', WIDTH * HEIGHT);
}

void put_char(int x, int y, char c) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
    screen[y * WIDTH + x] = c;
}

void put_string(int x, int y, char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        put_char(x + i, y, str[i]);
    }
}

int main() {
    int i, j;

    screen = malloc(WIDTH * HEIGHT);

    clear_screen();

    put_string(0, 0, "Welcome to the ASCII Art Generator");

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            put_char(j * 10, i * 4, font[i][j]);
        }
    }

    free(screen);

    return 0;
}