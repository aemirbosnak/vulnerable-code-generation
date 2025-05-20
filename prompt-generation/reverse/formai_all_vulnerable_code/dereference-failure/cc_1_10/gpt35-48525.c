//FormAI DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fractal generator function
void generateFractal(int n, double cx, double cy, double zoom) {
    int i, j;
    double x, y, zx, zy, tmp, colors;

    // Create an array for storing the color values
    int **image = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        image[i] = (int*)malloc(n * sizeof(int));
    }

    // Iterate through each pixel in the image
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            x = cx - (n/2 - i)/(0.5 * zoom * n);
            y = cy - (n/2 - j)/(0.5 * zoom * n);
            zx = x;
            zy = y;

            // Apply the fractal formula
            for (colors=0; colors<256 && (zx*zx + zy*zy) < 4; colors++) {
                tmp = zx*zx - zy*zy + x;
                zy = 2*zx*zy + y;
                zx = tmp;
            }

            // Store the color value for the pixel in the array
            image[i][j] = colors;
        }
    }

    // Print out the image
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (image[i][j] == 0) {
                printf(" ");
            }
            else {
                printf("%c", (image[i][j] < 128 ? '.' : '*'));
            }
        }
        printf("\n");
    }

    // Free up the memory used by the image array
    for (i = 0; i < n; i++) {
        free(image[i]);
    }
    free(image);
}

// Main function to call the fractal generator
int main() {
    int n = 30;
    double cx = 0, cy = 0, zoom = 1;
    printf("Generating fractal...\n");
    generateFractal(n, cx, cy, zoom);
    printf("Done!\n");
    return 0;
}