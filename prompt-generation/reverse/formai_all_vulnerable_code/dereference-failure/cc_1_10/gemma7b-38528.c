//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024

int main()
{
    int x, y, i, j, n, m;
    double r, g, b, c, d, e, f;

    // Allocate memory for the image
    unsigned char *img = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

    // Initialize the image
    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            img[x * HEIGHT * 3 + y * 3] = 0;
            img[x * HEIGHT * 3 + y * 3 + 1] = 0;
            img[x * HEIGHT * 3 + y * 3 + 2] = 0;
        }
    }

    // Generate the fractal
    n = 0;
    m = 0;
    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            c = (x - WIDTH / 2) / WIDTH;
            d = (y - HEIGHT / 2) / HEIGHT;
            e = sqrt(c * c + d * d);
            f = e * e * e;

            if(f < n)
            {
                img[x * HEIGHT * 3 + y * 3] = 255;
                img[x * HEIGHT * 3 + y * 3 + 1] = 255;
                img[x * HEIGHT * 3 + y * 3 + 2] = 255;
            }
            else
            {
                img[x * HEIGHT * 3 + y * 3] = 0;
                img[x * HEIGHT * 3 + y * 3 + 1] = 0;
                img[x * HEIGHT * 3 + y * 3 + 2] = 0;
            }
        }
    }

    // Save the image
    FILE *fp = fopen("fractal.bmp", "wb");
    fwrite(img, WIDTH * HEIGHT * 3, 1, fp);
    fclose(fp);

    // Free the memory
    free(img);

    return 0;
}