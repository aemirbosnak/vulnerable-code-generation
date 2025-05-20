//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITER 1000

void drawFractal(int max_iter) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = 0, zy = 0;
            double cX = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double cY = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iter = 0;

            while (zx * zx + zy * zy < 4 && iter < max_iter) {
                double tmp = zx * zx - zy * zy + cX;
                zy = 2.0 * zx * zy + cY;
                zx = tmp;
                iter++;
            }

            if (iter == max_iter) {
                printf("#");  // Part of the Mandelbrot set
            } else {
                // Mapping iteration count to characters, for visualization
                switch (iter % 8) {
                    case 0: printf(" "); break; // Empty space
                    case 1: printf("."); break; // Light shading
                    case 2: printf("o"); break; // Medium shading
                    case 3: printf("*"); break; // Dark shading
                    case 4: printf("x"); break; // Darker shading
                    case 5: printf("+"); break; // More shading
                    case 6: printf("@"); break; // Almost black
                    case 7: printf("%c", 219); break; // Solid block
                }
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int max_iter = MAX_ITER;

    // Allow user to provide the maximum iterations as a command-line argument
    if (argc > 1) {
        max_iter = atoi(argv[1]);
        if (max_iter <= 0) {
            fprintf(stderr, "Invalid iteration count. Using default: %d\n", MAX_ITER);
            max_iter = MAX_ITER;
        }
    }

    printf("Mandelbrot Fractal (max_iter = %d)\n\n", max_iter);
    drawFractal(max_iter);

    return 0;
}