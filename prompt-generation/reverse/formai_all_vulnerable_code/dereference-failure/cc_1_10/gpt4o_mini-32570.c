//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// Function Prototypes
void drawCanvas(char canvas[HEIGHT][WIDTH]);
void clearCanvas(char canvas[HEIGHT][WIDTH]);
void drawShapes(char canvas[HEIGHT][WIDTH]);
void drawCircle(char canvas[HEIGHT][WIDTH], int x, int y, int radius);
void drawSquare(char canvas[HEIGHT][WIDTH], int x, int y, int side);
void drawTriangle(char canvas[HEIGHT][WIDTH], int x, int y, int base);
void printInstructions();

// Main Function
int main() {
    char canvas[HEIGHT][WIDTH];
    int choices, radius, side, base, x, y;

    srand(time(0));  // Seed random number generator

    // Instruction to the user
    printInstructions();

    while (1) {
        printf("Choose a shape to draw (1: Circle, 2: Square, 3: Triangle, 4: Exit): ");
        scanf("%d", &choices);

        if (choices == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter X (0-%d): ", WIDTH - 1);
        scanf("%d", &x);
        printf("Enter Y (0-%d): ", HEIGHT - 1);
        scanf("%d", &y);

        switch (choices) {
            case 1:
                printf("Enter radius (1-%d): ", WIDTH < HEIGHT ? WIDTH / 2 : HEIGHT / 2);
                scanf("%d", &radius);
                drawCircle(canvas, x, y, radius);
                break;
            case 2:
                printf("Enter side length (1-%d): ", WIDTH < HEIGHT ? WIDTH : HEIGHT);
                scanf("%d", &side);
                drawSquare(canvas, x, y, side);
                break;
            case 3:
                printf("Enter base length (1-%d): ", WIDTH < HEIGHT ? WIDTH : HEIGHT);
                scanf("%d", &base);
                drawTriangle(canvas, x, y, base);
                break;
            default:
                printf("Invalid choice! Please choose a valid shape.\n");
        }

        clearCanvas(canvas);
        drawShapes(canvas);
        drawCanvas(canvas);
    }

    return 0;
}

// Draw the canvas on the console
void drawCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

// Clear the canvas
void clearCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
}

// Draw the shapes on the canvas
void drawShapes(char canvas[HEIGHT][WIDTH]) {
    // The function currently draws nothing, it's ready for implementation in main
}

// Draw a circle on the canvas
void drawCircle(char canvas[HEIGHT][WIDTH], int x, int y, int radius) {
    for (int i = 0; i <= 2 * radius; i++) {
        for (int j = 0; j <= 2 * radius; j++) {
            int distance = (int)((radius - sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius))) + 0.5);
            if (distance >= 0 && distance < 1) {
                if (x + (j - radius) >= 0 && x + (j - radius) < WIDTH &&
                    y + (i - radius) >= 0 && y + (i - radius) < HEIGHT) {
                    canvas[y + (i - radius)][x + (j - radius)] = '*';
                }
            }
        }
    }
}

// Draw a square on the canvas
void drawSquare(char canvas[HEIGHT][WIDTH], int x, int y, int side) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (x + j < WIDTH && y + i < HEIGHT && x + j >= 0 && y + i >= 0)
                canvas[y + i][x + j] = '#';
        }
    }
}

// Draw a triangle on the canvas
void drawTriangle(char canvas[HEIGHT][WIDTH], int x, int y, int base) {
    for (int i = 0; i < base; i++) {
        for (int j = 0; j <= i; j++) {
            if (x + j < WIDTH && y + i < HEIGHT && x + j >= 0 && y + i >= 0) {
                canvas[y + i][x + j] = '/';
                canvas[y + i][x + (base - 1 - j)] = '\\';
            }
        }
    }
}

// Print the instructions for the user
void printInstructions() {
    printf("Welcome to the Shape Drawer!\n");
    printf("You can draw shapes on a 40x20 canvas.\n");
    printf("Available shapes:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Triangle\n");
    printf("To exit, choose 4.\n");
}