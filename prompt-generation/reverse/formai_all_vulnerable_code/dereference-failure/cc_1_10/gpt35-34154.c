//FormAI DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define MAXIMUM_ITERATIONS 100
#define ZOOM 1
#define INITIAL_TOP_LEFT_X -2
#define INITIAL_TOP_LEFT_Y -2

int main()
{
    int width = WINDOW_WIDTH / ZOOM;
    int height = WINDOW_HEIGHT / ZOOM;
    double zoom = ZOOM, xOffset = 0, yOffset = 0;
    double topLeftX = INITIAL_TOP_LEFT_X, topLeftY = INITIAL_TOP_LEFT_Y;
    double x, y, x0, y0, xTemp;
    int iterationCount;
    unsigned char* colors = (unsigned char*)malloc(MAXIMUM_ITERATIONS * sizeof(unsigned char));
    int i, j;

    FILE* fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", width, height);

    for (i = 0; i < MAXIMUM_ITERATIONS; i++)
    {
        colors[i] = (unsigned char)((double)i / (double)MAXIMUM_ITERATIONS * 255.0);
    }

    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            x0 = ((double)i / (double)width) * zoom + topLeftX + xOffset;
            y0 = ((double)j / (double)height) * zoom + topLeftY + yOffset;

            double a = x0 - 0.25;
            double r2 = a * a + y0 * y0;
            double iter;

            if (r2 * r2 + 0.25 * y0 * y0 < 0.25)
            {
                iter = MAXIMUM_ITERATIONS;
            }
            else
            {
                x = 0; y = 0;
                for (iterationCount = 0; iterationCount < MAXIMUM_ITERATIONS; iterationCount++)
                {
                    xTemp = x * x - y * y + x0;
                    y = 2 * x * y + y0;
                    x = xTemp;

                    if (x * x + y * y >= 4)
                    {
                        break;
                    }
                }
                iter = iterationCount;
            }
            unsigned char* color = colors + (int)iter;
            fwrite(color, 1, 1, fp);
            fwrite(color + 1, 1, 1, fp);
            fwrite(color + 2, 1, 1, fp);
        }
    }

    fclose(fp);
    free(colors);

    return 0;
}