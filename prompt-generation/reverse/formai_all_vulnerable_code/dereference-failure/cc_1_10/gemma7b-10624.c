//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, i, j, max_iter = 1000, color, pixel;
    double real, imag, z_real, z_imag, c_real, c_imag;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(max_iter * max_iter * 3);

    // Initialize the image
    for (i = 0; i < max_iter * max_iter; i++)
    {
        image[i] = 0;
    }

    // Generate the fractal
    for (x = 0; x < max_iter; x++)
    {
        for (y = 0; y < max_iter; y++)
        {
            z_real = -2.0 + (x / (double)max_iter) * 4.0;
            z_imag = -1.0 + (y / (double)max_iter) * 2.0;

            for (i = 0; i < max_iter; i++)
            {
                c_real = z_real;
                c_imag = z_imag;

                z_real = c_real * c_real - c_imag * c_imag + z_real;
                z_imag = 2.0 * c_real * c_imag + z_imag;

                pixel = (int)sqrt(z_real * z_real + z_imag * z_imag) * max_iter;

                if (pixel < max_iter)
                {
                    image[pixel] = 255;
                }
            }
        }
    }

    // Save the image
    FILE *file = fopen("fractal.bmp", "wb");
    fwrite(image, max_iter * max_iter * 3, 1, file);
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}