//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: cheerful
// Welcome to the realm of pixel magic! Let's paint a masterpiece together.

#include <stdio.h>
#include <stdlib.h>

// Paintbrush dimensions
#define BRUSH_SIZE 3
#define BRUSH_COLOR 0xFFFFFF // A dazzling white

typedef struct {
    unsigned char red, green, blue;
} Pixel;

// Our magical canvas
Pixel **canvas;
int canvas_width, canvas_height;

// Let's grab our tools!
void init_canvas(int width, int height) {
    canvas_width = width;
    canvas_height = height;
    
    // Allocate memory for our canvas
    canvas = (Pixel**)malloc(sizeof(Pixel*) * canvas_height);
    for (int i = 0; i < canvas_height; i++) {
        canvas[i] = (Pixel*)malloc(sizeof(Pixel) * canvas_width);
    }
    
    // Fill the canvas with a blank canvas
    for (int i = 0; i < canvas_height; i++) {
        for (int j = 0; j < canvas_width; j++) {
            canvas[i][j].red = canvas[i][j].green = canvas[i][j].blue = 0;
        }
    }
}

// Time to paint!
void paint_brush(int x, int y) {
    // Check if we're within the canvas
    if (x < 0 || x >= canvas_width || y < 0 || y >= canvas_height) {
        return;
    }
    
    // Paint with our brush size and color
    for (int i = x - BRUSH_SIZE / 2; i <= x + BRUSH_SIZE / 2; i++) {
        for (int j = y - BRUSH_SIZE / 2; j <= y + BRUSH_SIZE / 2; j++) {
            if (i >= 0 && i < canvas_width && j >= 0 && j < canvas_height) {
                canvas[j][i].red = BRUSH_COLOR >> 16;
                canvas[j][i].green = (BRUSH_COLOR & 0x00FF00) >> 8;
                canvas[j][i].blue = BRUSH_COLOR & 0x0000FF;
            }
        }
    }
}

// Let's see our masterpiece!
void display_canvas() {
    printf("Behold, your radiant canvas:\n");
    for (int i = 0; i < canvas_height; i++) {
        for (int j = 0; j < canvas_width; j++) {
            printf("#%02x%02x%02x ", canvas[i][j].red, canvas[i][j].green, canvas[i][j].blue);
        }
        printf("\n");
    }
}

int main() {
    // Set the stage for our masterpiece
    init_canvas(500, 500);
    
    // Let's start painting!
    paint_brush(250, 250);
    paint_brush(300, 300);
    
    // Time to unveil the beauty
    display_canvas();
    
    // Free up our tools
    for (int i = 0; i < canvas_height; i++) {
        free(canvas[i]);
    }
    free(canvas);
    
    return 0;
}