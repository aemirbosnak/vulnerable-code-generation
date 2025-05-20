//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void watermark(int **img, int w, int h, int **wm)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            int avg = 0;
            for (int i = 0; i < MAX; i++)
            {
                if (wm[i][0] == r && wm[i][1] == c)
                {
                    avg += img[r][c];
                }
            }
            img[r][c] = (avg / MAX) + 1;
        }
    }
}

int main()
{
    int w = 8, h = 6;
    int **img = (int **)malloc(h * w * sizeof(int));
    int **wm = (int **)malloc(MAX * 2 * sizeof(int));

    // Generate sample image data
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            img[r][c] = rand() % 256;
        }
    }

    // Generate watermark data
    wm[0][0] = 2;
    wm[0][1] = 3;
    wm[1][0] = 4;
    wm[1][1] = 5;

    watermark(img, w, h, wm);

    // Display the watermarked image
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf("%d ", img[r][c]);
        }
        printf("\n");
    }

    free(img);
    free(wm);

    return 0;
}