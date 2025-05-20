//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: enthusiastic
// Behold, the Pixel Art Generator Extraordinaire!
// Unleash your inner Picasso with ease!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a new canvas
char** createCanvas(int width, int height) {
    char** canvas = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        canvas[i] = (char*)malloc(width * sizeof(char));
        memset(canvas[i], ' ', width);
    }
    return canvas;
}

// Function to draw a line on the canvas
void drawLine(char** canvas, int width, int height, int x1, int y1, int x2, int y2, char c) {
    // Handle horizontal lines
    if (y1 == y2) {
        for (int x = x1; x <= x2; x++) {
            canvas[y1][x] = c;
        }
    } // Handle vertical lines
    else if (x1 == x2) {
        for (int y = y1; y <= y2; y++) {
            canvas[y][x1] = c;
        }
    } // Handle diagonal lines
    else {
        // Calculate the slope and intercept of the line
        float slope = (float)(y2 - y1) / (x2 - x1);
        float intercept = y1 - slope * x1;

        // Draw the line using the slope and intercept
        for (int x = x1; x <= x2; x++) {
            int y = (int)(slope * x + intercept);
            if (y >= 0 && y < height) {
                canvas[y][x] = c;
            }
        }
    }
}

// Function to draw a rectangle on the canvas
void drawRectangle(char** canvas, int width, int height, int x1, int y1, int x2, int y2, char c) {
    drawLine(canvas, width, height, x1, y1, x2, y1, c);
    drawLine(canvas, width, height, x1, y1, x1, y2, c);
    drawLine(canvas, width, height, x2, y1, x2, y2, c);
    drawLine(canvas, width, height, x1, y2, x2, y2, c);
}

// Function to draw a circle on the canvas
void drawCircle(char** canvas, int width, int height, int cx, int cy, int r, char c) {
    for (int y = cy - r; y <= cy + r; y++) {
        for (int x = cx - r; x <= cx + r; x++) {
            if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r) {
                canvas[y][x] = c;
            }
        }
    }
}

// Function to print the canvas
void printCanvas(char** canvas, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }
}

int main() {
    // Create a canvas
    int width = 80;
    int height = 25;
    char** canvas = createCanvas(width, height);

    // Draw some shapes on the canvas
    drawLine(canvas, width, height, 10, 10, 70, 10, '*');
    drawLine(canvas, width, height, 10, 10, 10, 20, '*');
    drawLine(canvas, width, height, 70, 10, 70, 20, '*');
    drawLine(canvas, width, height, 10, 20, 70, 20, '*');
    drawRectangle(canvas, width, height, 20, 12, 60, 18, '*');
    drawCircle(canvas, width, height, 40, 15, 5, '*');

    // Print the canvas
    printCanvas(canvas, width, height);

    return 0;
}