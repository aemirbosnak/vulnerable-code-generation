//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _char_info {
    int x;
    int y;
    char c;
} char_info;

typedef struct _ascii_art {
    int width;
    int height;
    char_info **chars;
} ascii_art;

ascii_art *create_ascii_art(int width, int height) {
    ascii_art *art = malloc(sizeof(ascii_art));
    art->width = width;
    art->height = height;
    art->chars = malloc(sizeof(char_info *) * height);
    for (int i = 0; i < height; i++) {
        art->chars[i] = malloc(sizeof(char_info) * width);
    }
    return art;
}

void destroy_ascii_art(ascii_art *art) {
    for (int i = 0; i < art->height; i++) {
        free(art->chars[i]);
    }
    free(art->chars);
    free(art);
}

void set_char_info(ascii_art *art, int x, int y, char c) {
    art->chars[y][x].x = x;
    art->chars[y][x].y = y;
    art->chars[y][x].c = c;
}

void draw_ascii_art(ascii_art *art) {
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            printf("%c", art->chars[y][x].c);
        }
        printf("\n");
    }
}

int main() {
    ascii_art *art = create_ascii_art(100, 50);

    // Draw a simple heart
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            double dx = x - art->width / 2;
            double dy = y - art->height / 2;
            double r = sqrt(dx * dx + dy * dy);
            if (r < 20) {
                set_char_info(art, x, y, '*');
            }
        }
    }

    draw_ascii_art(art);

    destroy_ascii_art(art);

    return 0;
}