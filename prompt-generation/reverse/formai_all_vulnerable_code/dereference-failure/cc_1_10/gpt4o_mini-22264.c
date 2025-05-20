//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 16
#define HEIGHT 16

// Struct to represent a pixel with RGB values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Function to draw a single pixel
void draw_pixel(Pixel **canvas, int x, int y, Pixel color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = color;
    }
}

// Function to create a blank canvas
Pixel **create_canvas() {
    Pixel **canvas = malloc(HEIGHT * sizeof(Pixel*));
    for (int i = 0; i < HEIGHT; ++i) {
        canvas[i] = malloc(WIDTH * sizeof(Pixel));
        memset(canvas[i], 0, WIDTH * sizeof(Pixel));
    }
    return canvas;
}

// Function to free the canvas memory
void free_canvas(Pixel **canvas) {
    for (int i = 0; i < HEIGHT; ++i) {
        free(canvas[i]);
    }
    free(canvas);
}

// Function to render the canvas to console
void render_canvas(Pixel **canvas) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Pixel pixel = canvas[y][x];
            if (pixel.r == 0 && pixel.g == 0 && pixel.b == 0) {
                printf(" ");
            } else {
                printf("\033[48;2;%d;%d;%dm ", pixel.r, pixel.g, pixel.b);
            }
        }
        printf("\033[0m\n");
    }
}

// Function to create a colorful pattern
void create_pattern(Pixel **canvas) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((x + y) % 2 == 0) {
                draw_pixel(canvas, x, y, (Pixel){255, 0, 0});  // Red
            } else {
                draw_pixel(canvas, x, y, (Pixel){0, 255, 0});  // Green
            }
        }
    }
}

// Function to create a checkerboard pattern
void create_checkerboard(Pixel **canvas) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((x / 4 + y / 4) % 2 == 0) {
                draw_pixel(canvas, x, y, (Pixel){0, 0, 255});  // Blue
            } else {
                draw_pixel(canvas, x, y, (Pixel){255, 255, 0});  // Yellow
            }
        }
    }
}

// Function to create a gradient effect
void create_gradient(Pixel **canvas) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            draw_pixel(canvas, x, y, (Pixel){(unsigned char)(x * 16), (unsigned char)(y * 16), 128});
        }
    }
}

// Function to generate a pixel art based on user's choice
void generate_pixel_art(Pixel **canvas) {
    int choice;
    
    printf("Select pixel art pattern:\n");
    printf("1. Colorful Pattern\n");
    printf("2. Checkerboard Pattern\n");
    printf("3. Gradient Effect\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            create_pattern(canvas);
            break;
        case 2:
            create_checkerboard(canvas);
            break;
        case 3:
            create_gradient(canvas);
            break;
        default:
            printf("Invalid choice, using colorful pattern by default.\n");
            create_pattern(canvas);
            break;
    }
}

int main() {
    Pixel **canvas = create_canvas();
    
    generate_pixel_art(canvas);
    
    render_canvas(canvas);
    
    free_canvas(canvas);
    
    return 0;
}