//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,.-+*#=[]{}|;:<>?@! "
#define WHITE "\033[0m"
#define BLACK "\033[30m"

typedef struct pixel {
    int x;
    int y;
    char color;
} pixel;

void draw_pixel(pixel *screen, int x, int y, char color) {
    if (x >= 0 && x < MAX_WIDTH && y >= 0 && y < MAX_HEIGHT) {
        screen[y * MAX_WIDTH + x].color = color;
    }
}

void draw_text(pixel *screen, int x, int y, char *text, char color) {
    int i = 0;
    while (text[i]) {
        draw_pixel(screen, x + i * 8, y, color);
        i++;
    }
}

void clear_screen(pixel *screen) {
    int i, j;
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            screen[i * MAX_WIDTH + j].color = WHITE;
        }
    }
}

void print_screen(pixel *screen) {
    int i, j;
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            printf("%c", screen[i * MAX_WIDTH + j].color);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int width, height;
    char *text = "Shocked ASCII Art Generator Example Program";
    pixel *screen = (pixel *)malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(pixel));
    clear_screen(screen);
    draw_text(screen, (MAX_WIDTH - strlen(text)) / 2, (MAX_HEIGHT - 8) / 2, text, BLACK);
    print_screen(screen);
    free(screen);
    return 0;
}