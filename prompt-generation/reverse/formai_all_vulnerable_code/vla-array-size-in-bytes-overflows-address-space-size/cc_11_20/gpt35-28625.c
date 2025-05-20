//FormAI DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to my Fractal Generator!\n");
    printf("Get ready to experience the magic of fractals...\n");
    
    // User inputs
    int iterations;
    printf("How many iterations should I run? ");
    scanf("%d", &iterations);
    int width;
    printf("What width should my image be? ");
    scanf("%d", &width);
    
    // Initialize image array
    int image[width][width];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = 0;
        }
    }
    
    // Fractal generation
    int x = width / 2;
    int y = width / 2;
    image[x][y] = 1;
    for (int i = 0; i < iterations; i++) {
        int dir = rand() % 4;
        if (dir == 0) { // Up
            y -= 1;
        } else if (dir == 1) { // Down
            y += 1;
        } else if (dir == 2) { // Left
            x -= 1;
        } else if (dir == 3) { // Right
            x += 1;
        }
        if (x >= 0 && x < width && y >= 0 && y < width) {
            image[x][y] = 1;
        }
    }
    
    // Display image
    printf("Here is your beautiful fractal:\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("I hope you enjoyed your truly unique fractal experience!\n");
    return 0;
}