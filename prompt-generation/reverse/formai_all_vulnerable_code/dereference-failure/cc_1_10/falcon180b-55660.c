//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET ".,-~:;=!*#@"

typedef struct {
    int x, y;
} Point;

typedef struct {
    char *data;
    int width, height;
} Bitmap;

void init_bitmap(Bitmap *bitmap, int width, int height) {
    bitmap->data = calloc(width * height, sizeof(char));
    bitmap->width = width;
    bitmap->height = height;
}

void destroy_bitmap(Bitmap *bitmap) {
    free(bitmap->data);
}

void set_bit(Bitmap *bitmap, int x, int y) {
    int index = y * bitmap->width + x;
    bitmap->data[index] = 1;
}

void clear_bit(Bitmap *bitmap, int x, int y) {
    int index = y * bitmap->width + x;
    bitmap->data[index] = 0;
}

void print_bitmap(const Bitmap *bitmap) {
    int x, y;
    for (y = 0; y < bitmap->height; y++) {
        for (x = 0; x < bitmap->width; x++) {
            if (bitmap->data[y * bitmap->width + x]) {
                printf("%c", CHAR_SET[0]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_WIDTH];
    Bitmap bitmap;
    init_bitmap(&bitmap, MAX_WIDTH, MAX_HEIGHT);
    printf("Enter ASCII art:\n");
    fgets(input, MAX_WIDTH, stdin);
    int x = 0, y = 0;
    int width = 0, height = 0;
    for (int i = 0; input[i]!= '\0'; i++) {
        if (input[i] == '\n') {
            y++;
            x = 0;
        } else if (isspace(input[i])) {
            x++;
        } else {
            set_bit(&bitmap, x, y);
            x++;
        }
        if (x > width) {
            width = x;
        }
        if (y > height) {
            height = y;
        }
    }
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    print_bitmap(&bitmap);
    destroy_bitmap(&bitmap);
    return 0;
}