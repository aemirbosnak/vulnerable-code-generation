//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <math.h>

int main() {

    int x, y, i, j, n, m;
    float x_min, x_max, y_min, y_max;

    // Set the parameters
    x_min = -2.0f;
    x_max = 1.0f;
    y_min = -1.0f;
    y_max = 1.0f;
    n = 256;
    m = 256;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(n * m);

    // Iterate over the pixels
    for (y = 0; y < m; y++) {
        for (x = 0; x < n; x++) {
            int iterations = 0;

            // Iterate over the iterations
            for (i = 0; i < 255; i++) {
                float x_c = x_min + (x / (float)n) * (x_max - x_min);
                float y_c = y_min + (y / (float)m) * (y_max - y_min);
                float z = 0.0f;
                for (j = 0; j < 2; j++) {
                    z = z * z + x_c * z + y_c * z - 2.0f * z + 1.0f;
                    if (z > 2.0f) {
                        break;
                    }
                }
                if (iterations == 255) {
                    image[x * m + y] = 0;
                } else {
                    image[x * m + y] = iterations;
                }
            }
        }
    }

    // Save the image
    FILE *file = fopen("fractal.ppm", "w");
    fprintf(file, "PPPM %d %d %d\n", n, m, 3);
    fwrite(image, n * m * 3, 1, file);
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}