//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

void print_char(char c, int x, int y) {
    int row = y * WIDTH + x;
    printf("\033[%d;%dH%c", y, x, c);
}

void print_rect(int x, int y, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            print_char('#', x + j, y + i);
        }
    }
}

void print_string_centered(const char *s, int x, int y) {
    int len = strlen(s);
    int spacing = (WIDTH - len) / 2;

    for (int i = 0; i < spacing; i++) {
        print_char(' ', x - i - 1, y);
    }

    for (int i = 0; i < len; i++) {
        print_char(s[i], x + i + spacing, y);
    }
}

void draw_text(const char *text, int x, int y) {
    Point *points = malloc(sizeof(Point) * (strlen(text) + 1));

    int index = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];

        if (isalpha(c) || isdigit(c) || c == ' ') {
            points[index].x = x + (i - (int)strspn(text, "0123456789")) % WIDTH;
            points[index].y = y;
            index++;
        }
    }

    points[index].x = 0;
    points[index].y = 0;

    for (int i = 0; i < index; i++) {
        print_char(text[i], points[i].x, points[i].y);
        if (i < index - 1 && isspace(text[i + 1])) {
            print_rect(points[i].x, points[i].y, 1, 1);
        }
    }

    free(points);
}

int main() {
    print_rect(0, 0, WIDTH, HEIGHT);
    draw_text("Hello, World!", 3, 3);
    print_string_centered("Text Centered", 15, 5);

    return 0;
}