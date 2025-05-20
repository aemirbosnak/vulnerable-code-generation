//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 5

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel colors[16] = {
    {0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {0, 0, 255},
    {255, 255, 0}, {0, 255, 255}, {255, 0, 255}, {255, 255, 255},
    {128, 128, 128}, {255, 128, 128}, {128, 255, 128}, {128, 128, 255},
    {128, 255, 255}, {255, 128, 128}, {255, 128, 255}, {255, 255, 128}
};

void draw_rectangle(int x, int y, int w, int h, pixel fill) {
    int i, j;

    for (i = y; i < y + h; i++) {
        for (j = x; j < x + w; j++)
            printf("%c", fill.b > 128 ? '*' : ' ');
        if (i != y + h - 1)
            printf("\n");
    }
}

void print_ascii_art(char *text, int len, pixel *palette) {
    int i, j, k, c, bw, bh;
    pixel bg = {255, 255, 255};

    bw = (WIDTH + 1) / 2;
    bh = (HEIGHT + 1) / 2;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            c = (text[i * WIDTH + j] < ' ') ? 0 : text[i * WIDTH + j] - ' ';
            if (c >= len || c < 0)
                continue;

            draw_rectangle(j - bw, i - bh, 2, 2, palette[c]);
        }

        printf("\n");
    }

    draw_rectangle(0, 0, WIDTH, HEIGHT, bg);
}

int main(int argc, char **argv) {
    int len;
    char *text;

    if (argc != 2) {
        printf("Usage: %s <ASCII art text>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]);

    text = (char *)calloc(WIDTH * HEIGHT + 1, sizeof(char));
    strncpy(text, argv[1], WIDTH * HEIGHT);

    print_ascii_art(text, len, colors);

    free(text);

    return 0;
}