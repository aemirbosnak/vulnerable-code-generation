//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void drawHeart(int size);

int main() {
    int size;

    // Setting the size of the heart
    printf("Enter the size of the heart (recommended: 6 or more): ");
    scanf("%d", &size);

    // Validating size
    if (size < 3) {
        printf("Size should be 3 or more!\n");
        return 1;
    }

    // Draw heart
    drawHeart(size);
    return 0;
}

// Function to draw a heart shape
void drawHeart(int size) {
    int width = 2 * size + 1; // Width of the heart
    int height = size + 2;    // Height of the heart
    char heart[height][width];
    
    // Initialize the heart array with space
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            heart[i][j] = ' ';
        }
    }
    
    // Create heart shape
    for (int i = 0; i < size; i++) {
        heart[0][size - i] = '*'; // Left top curve
        heart[0][size + i] = '*'; // Right top curve
        heart[i + 1][i] = '*';    // Left side
        heart[i + 1][width - 1 - i] = '*'; // Right side
    }
    
    // Draw bottom point of heart
    heart[size + 1][size] = '*';
    
    // Print heart
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", heart[i][j]);
        }
        printf("\n");
    }
}