//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define MAX_WIDTH 100
#define TEXT_HEIGHT 6

// ASCII art character set
char *charset[] = {
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                                                         ",
    "                                                                                              ",
    "                                                                                                                           ",
    "                                                                                                                     ",
    "                                                                                                                 ",
    "                                                                                                               ",
    "                                                                                                             ",
    "                                                                                                           ",
    "                                                                                                       ",
    "                                                                                                   ",
    "                                                                                                   ",
    "                                                                                                   ",
    "                                                                                                   ",
    "                                                                                                   ",
    "                                                                                                   ",
    "                                                                                                   ",
    "                                                                                                   "};

// Print a character to the ASCII art canvas
void draw_char(int x, int y, char c) {
    if (x < 0 || x >= MAX_WIDTH || y < 0 || y >= TEXT_HEIGHT) {
        return;
    }
    charset[y][x] = c;
}

// Print a string to the ASCII art canvas
void draw_string(int x, int y, char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        draw_char(x + i, y, str[i]);
    }
}

// Clear the ASCII art canvas
void clear_canvas() {
    for (int i = 0; i < TEXT_HEIGHT; i++) {
        memset(charset[i], ' ', MAX_WIDTH);
    }
}

// Convert a text string to ASCII art
void text_to_ascii(char *text) {
    clear_canvas();

    int x = 0;
    int y = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char c = text[i];
        if (c == '\n') {
            x = 0;
            y++;
        } else {
            draw_char(x, y, c);
            x++;
        }
    }
}

// Print the ASCII art canvas to the console
void print_canvas() {
    for (int i = 0; i < TEXT_HEIGHT; i++) {
        printf("%s\n", charset[i]);
    }
}

int main() {
    char *text = "Hello, world!";

    text_to_ascii(text);
    print_canvas();

    return 0;
}