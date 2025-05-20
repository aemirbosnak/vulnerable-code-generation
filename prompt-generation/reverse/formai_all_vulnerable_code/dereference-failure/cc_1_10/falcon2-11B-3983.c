//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Create a black image of size 100x100
    unsigned char *image = (unsigned char *)malloc(100 * 100 * 3);
    memset(image, 0, 100 * 100 * 3);

    // Create a green rectangle at position (50, 50)
    for (int y = 50; y < 100; y++) {
        for (int x = 50; x < 100; x++) {
            image[(y * 100) + x * 3] = 0;
            image[(y * 100) + x * 3 + 1] = 255;
            image[(y * 100) + x * 3 + 2] = 0;
        }
    }

    // Create a blue square at position (75, 75)
    for (int y = 75; y < 100; y++) {
        for (int x = 75; x < 100; x++) {
            image[(y * 100) + x * 3] = 255;
            image[(y * 100) + x * 3 + 1] = 0;
            image[(y * 100) + x * 3 + 2] = 255;
        }
    }

    // Draw a red circle at position (50, 50)
    int radius = 50;
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            int index = (y + 50) * 100 + (x + 50) * 3;
            image[index] = 255;
            image[index + 1] = 0;
            image[index + 2] = 0;
        }
    }

    // Print the image
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            printf("%d ", image[(y * 100) + x * 3]);
        }
        printf("\n");
    }

    // Free the memory
    free(image);

    return 0;
}