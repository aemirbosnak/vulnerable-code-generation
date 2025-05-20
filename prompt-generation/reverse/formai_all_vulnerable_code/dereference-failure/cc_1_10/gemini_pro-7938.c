//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int width;
    int height;
    char **grid;
} Bitmap;

Bitmap *bitmap_new(int width, int height) {
    Bitmap *bitmap = malloc(sizeof(Bitmap));
    bitmap->text = malloc(width * height);
    bitmap->grid = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        bitmap->grid[i] = bitmap->text + i * width;
    }
    bitmap->width = width;
    bitmap->height = height;
    return bitmap;
}

void bitmap_free(Bitmap *bitmap) {
    free(bitmap->text);
    free(bitmap->grid);
    free(bitmap);
}

void bitmap_clear(Bitmap *bitmap) {
    memset(bitmap->text, ' ', bitmap->width * bitmap->height);
}

void bitmap_set_pixel(Bitmap *bitmap, int x, int y, char c) {
    if (x >= 0 && x < bitmap->width && y >= 0 && y < bitmap->height) {
        bitmap->grid[y][x] = c;
    }
}

void bitmap_print(Bitmap *bitmap) {
    for (int y = 0; y < bitmap->height; y++) {
        for (int x = 0; x < bitmap->width; x++) {
            printf("%c", bitmap->grid[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int width = 80;
    int height = 25;
    Bitmap *bitmap = bitmap_new(width, height);
    bitmap_clear(bitmap);

    // Draw a line
    for (int x = 0; x < width; x++) {
        bitmap_set_pixel(bitmap, x, 10, '*');
    }

    // Draw a filled rectangle
    for (int y = 5; y < 15; y++) {
        for (int x = 20; x < 40; x++) {
            bitmap_set_pixel(bitmap, x, y, '#');
        }
    }

    // Draw a circle
    int radius = 10;
    int center_x = width / 2;
    int center_y = height / 2;
    for (int y = center_y - radius; y <= center_y + radius; y++) {
        for (int x = center_x - radius; x <= center_x + radius; x++) {
            if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius) {
                bitmap_set_pixel(bitmap, x, y, 'o');
            }
        }
    }

    // Draw some text
    char *text = "Hello, world!";
    int text_width = strlen(text);
    int text_height = 5;
    for (int y = 0; y < text_height; y++) {
        for (int x = 0; x < text_width; x++) {
            bitmap_set_pixel(bitmap, x + (width - text_width) / 2, y + (height - text_height) / 2, text[x]);
        }
    }

    // Print the bitmap
    bitmap_print(bitmap);

    // Free the bitmap
    bitmap_free(bitmap);

    return 0;
}