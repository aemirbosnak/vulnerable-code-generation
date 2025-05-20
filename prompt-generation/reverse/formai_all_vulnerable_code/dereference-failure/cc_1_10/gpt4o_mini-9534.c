//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

void printPixel(char pixel) {
    printf("%c", pixel);
}

void drawHeart(int seed) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Create a heart pattern using math
            if ((x - 10) * (x - 10) + (y - 5) * (y - 5) <= 36 && 
                (x - 15) * (x - 15) + (y - 5) * (y - 5) <= 36) {
                printPixel('*');
            } else if ((x - 5) * (x - 5) + (y - 3) * (y - 3) <= 15) {
                printPixel('*');
            } else {
                printPixel(' ');
            }
        }
        printf("\n");
    }
}

void drawPattern(int patternSeed) {
    // Modulate line spacing and create a visual design
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value = (i * j + patternSeed) % 3;
            if (value == 0) {
                printPixel('#');
            } else if (value == 1) {
                printPixel('.');
            } else {
                printPixel('o');
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <seed_number>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    
    printf("Generating pixel art with seed: %d\n", seed);
    
    printf("\nHeart Pattern:\n");
    drawHeart(seed);
    
    printf("\nRandom Pattern:\n");
    drawPattern(seed);
    
    return 0;
}