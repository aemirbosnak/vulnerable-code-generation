//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int x, y;
    char color;
} Pixel;

Pixel* pixels;

void initPixels() {
    pixels = (Pixel*) malloc(WIDTH * HEIGHT * sizeof(Pixel));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i].x = i % WIDTH;
        pixels[i].y = i / WIDTH;
        pixels[i].color = (i % 2) ? 1 : 0;
    }
}

void drawCircle(int x, int y, int radius) {
    int startX = x - radius;
    int startY = y - radius;
    int endX = x + radius;
    int endY = y + radius;
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT) {
                pixels[i * HEIGHT + j].color = 1;
            }
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    int startX = x1;
    int startY = y1;
    int endX = x2;
    int endY = y2;
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT) {
                pixels[i * HEIGHT + j].color = 1;
            }
        }
    }
}

void drawRectangle(int x, int y, int width, int height) {
    drawLine(x, y, x + width, y);
    drawLine(x, y + height, x + width, y + height);
    drawLine(x, y, x, y + height);
    drawLine(x + width, y, x + width, y + height);
}

void main() {
    srand(time(NULL));
    initPixels();
    int moveX = 0, moveY = 0;
    int direction = 1;
    int radius = 1;
    int widthToDraw = 10;
    int heightToDraw = 10;
    char command;

    while (1) {
        // Clear the screen
        for (int i = 0; i < WIDTH * HEIGHT; i++) {
            pixels[i].color = 0;
        }

        // Draw a circle
        drawCircle(moveX, moveY, radius);

        // Move the circle
        moveX += direction * (radius + 1);
        moveY += direction * (radius + 1);

        // Check for border
        if (moveX < 0 || moveX >= WIDTH || moveY < 0 || moveY >= HEIGHT) {
            direction = -direction;
        }

        // Draw a line
        drawLine(moveX, moveY, moveX + radius, moveY);

        // Draw a rectangle
        drawRectangle(moveX, moveY, widthToDraw, heightToDraw);

        // Get the next command
        command = getchar();

        // Check for quit command
        if (command == 'q') {
            break;
        }

        // Check for up command
        if (command == 'u') {
            radius++;
        }

        // Check for down command
        if (command == 'd') {
            radius--;
        }

        // Check for left command
        if (command == 'l') {
            moveX -= radius;
        }

        // Check for right command
        if (command == 'r') {
            moveX += radius;
        }
    }
}