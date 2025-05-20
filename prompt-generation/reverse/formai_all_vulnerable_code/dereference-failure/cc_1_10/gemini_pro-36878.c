//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char **data;
} Canvas;

Canvas *canvas_new(int width, int height) {
    Canvas *canvas = malloc(sizeof(Canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        canvas->data[i] = malloc(sizeof(char) * width);
        memset(canvas->data[i], ' ', width);
    }
    return canvas;
}

void canvas_free(Canvas *canvas) {
    for (int i = 0; i < canvas->height; i++) {
        free(canvas->data[i]);
    }
    free(canvas->data);
    free(canvas);
}

void canvas_set_pixel(Canvas *canvas, int x, int y, char c) {
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        canvas->data[y][x] = c;
    }
}

void canvas_print(Canvas *canvas) {
    for (int i = 0; i < canvas->height; i++) {
        printf("%s\n", canvas->data[i]);
    }
}

int main() {
    Canvas *canvas = canvas_new(MAX_WIDTH, MAX_HEIGHT);

    // Draw a rectangle
    for (int i = 0; i < MAX_WIDTH; i++) {
        canvas_set_pixel(canvas, i, 0, '*');
        canvas_set_pixel(canvas, i, MAX_HEIGHT - 1, '*');
    }
    for (int i = 1; i < MAX_HEIGHT - 1; i++) {
        canvas_set_pixel(canvas, 0, i, '*');
        canvas_set_pixel(canvas, MAX_WIDTH - 1, i, '*');
    }

    // Draw a circle
    int radius = 10;
    int center_x = MAX_WIDTH / 2;
    int center_y = MAX_HEIGHT / 2;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                canvas_set_pixel(canvas, center_x + i, center_y + j, '*');
            }
        }
    }

    // Draw a text
    char *text = "Hello, world!";
    int text_width = strlen(text);
    int text_height = 5;
    int text_x = (MAX_WIDTH - text_width) / 2;
    int text_y = (MAX_HEIGHT - text_height) / 2;
    for (int i = 0; i < text_height; i++) {
        for (int j = 0; j < text_width; j++) {
            canvas_set_pixel(canvas, text_x + j, text_y + i, text[i * text_width + j]);
        }
    }

    canvas_print(canvas);

    canvas_free(canvas);

    return 0;
}